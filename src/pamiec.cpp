#include <cstdlib>
#include <cstdio>
#include "pamiec.hpp"

int utworz_pamiec(key_t key, std::size_t size) {

    int shmid = shmget(key, size, IPC_CREAT | IPC_EXCL | 0600);

    if (shmid == -1) {
        perror("Blad shmget (TWORZENIE)");
        exit(EXIT_FAILURE);
    }

    return shmid;
}

int dolacz_pamiec(key_t key, std::size_t size) {

    int shmid = shmget(key, size, 0600);

    if(shmid == -1) {
        perror("Blad shmget (DOLACZANIE)");
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
            perror("Blad shmctl (IPC_RMID)");
        }
    }
}
