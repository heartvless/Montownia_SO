#include <iostream>
#include "pamiec.hpp"
#include "semafor.hpp"

int main() {

    key_t key = stworz_klucz(".", 'M');

    int shmid = utworz_dolacz_pamiec(key, sizeof(Magazyn));
    Magazyn* magazyn = podepnij_pamiec(shmid);

    key_t sem_key = stworz_klucz(".", 'S');
    int semid = utworz_semafory(sem_key, 1);

    for(int i = 0; i < 100000; i++) {
        opusc_semafor(semid, 0);
        magazyn->liczba_czesci++;
        podnies_semafor(semid, 0);
    }

    odlacz_i_usun_pamiec(magazyn, shmid, false);

    return 0;
}