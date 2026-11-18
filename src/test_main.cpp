#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include "pamiec.hpp"
#include "semafor.hpp"

int main() {

    key_t klucz = stworz_klucz(".", 'M');
    int shmid = utworz_dolacz_pamiec(klucz, sizeof(Magazyn));
    Magazyn* magazyn = podepnij_pamiec(shmid);

    magazyn->liczba_czesci = 0;
    magazyn->czy_gotowe = false;

    key_t sem_klucz = stworz_klucz(".", 'S');
    int semid = utworz_semafory(sem_klucz, 1);
    ustaw_semafor(semid, 0, 1);

    std::cout << "[RODZIC] Start - Liczba czesci: " << magazyn->liczba_czesci << std::endl;

    pid_t pid = fork();

    if(pid == -1) {
        perror("Blad fork");
        odlacz_i_usun_pamiec(magazyn, shmid, true);
        usun_semafory(semid);
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {

        execl("./potomek", "potomek", NULL);
        perror("Blad excel");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 100000; i++) {
        opusc_semafor(semid, 0);
        magazyn->liczba_czesci++;
        podnies_semafor(semid, 0);
    }

    wait(NULL);

    std::cout << "[RODZIC] Po pracy dziecka. Liczba czesci: " << magazyn->liczba_czesci << std::endl << "[RODZIC] Czy gotowe: " << magazyn->czy_gotowe << std::endl;
    
    odlacz_i_usun_pamiec(magazyn, shmid, true);
    usun_semafory(semid);

    return 0;
}