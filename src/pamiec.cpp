#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "pamiec.hpp"

key_t stworz_klucz(const char *path, const char name_ch) {

    key_t key = ftok(path, name_ch);

    if(key == -1) {
        perror("Blad ftok");
        exit(EXIT_FAILURE);
    }   

    return key;
}

int utworz_dolacz_pamiec(key_t key, std::size_t size = sizeof(Magazyn)) {

    int shmid = shmget(key, size, IPC_CREAT | 0600);

    if (shmid == -1) {
        perror("Blad shmget");
        exit(EXIT_FAILURE);
    }

    return shmid;
}

Magazyn* podepnij_pamiec(int shmid) {

    void* addr = shmat(shmid, NULL, 0);

    if(addr == (void*)-1) {
        perror("Blad shmat");
        exit(EXIT_FAILURE);
    }

    return static_cast<Magazyn*>(addr);
}

void odlacz_i_usun_pamiec(Magazyn* ptr_mag, int shmid, bool should_delete) {

    if(shmdt(ptr_mag) == -1) {
        perror("Blad shmdt");
    }

    if(should_delete) {
        if(shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("Blad shmctl IPC_RMID");
        }
    }
}
