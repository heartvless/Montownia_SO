#include <cstdlib>
#include <cstdio>
#include "semafor.hpp"

int utworz_semafory(key_t key, int sem_amount) {

    int semid = semget(key, sem_amount, IPC_CREAT | IPC_EXCL | 0600);

    if(semid == -1) {
        perror("Blad semget (TWORZENIE)");
        exit(EXIT_FAILURE);
    }

    return semid;
}

int dolacz_semafory(key_t key, int sem_amount) {

    int semid = semget(key, sem_amount, 0600);

    if(semid == -1) {
        perror("Blad semget (DOLACZANIE)");
        exit(EXIT_FAILURE);
    }

    return semid;
}

void ustaw_semafor(int semid, int sem_number, int sem_value) {

    if(semctl(semid, sem_number, SETVAL, sem_value) == -1) {
        perror("Blad semctl (SETVAL)");
        exit(EXIT_FAILURE);
    }

}

void opusc_semafor(int semid, int sem_number) {

    struct sembuf op;

    op.sem_num = sem_number;
    op.sem_op = -1;
    op.sem_flg = 0;

    if(semop(semid, &op, 1) == -1) {
        perror("Blad semop (OPUSC)");
        exit(EXIT_FAILURE);
    }

}

void podnies_semafor(int semid, int sem_number) {

    struct sembuf op;

    op.sem_num = sem_number;
    op.sem_op = 1;
    op.sem_flg = 0;

    if(semop(semid, &op, 1) == -1) {
        perror("Blad semop (PODNIES)");
        exit(EXIT_FAILURE);
    }
}

void usun_semafory(int semid) {

    if(semctl(semid, 0, IPC_RMID) == -1) {
        perror("Blad semctl (IPC_RMID)");
    }

}