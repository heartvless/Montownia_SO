#include <unistd.h>
#include <sys/wait.h>
#include "pamiec.hpp"

int main() {

    key_t klucz = stworz_klucz(".", 'M');
    int shmid = utworz_dolacz_pamiec(klucz, sizeof(Magazyn));
    Magazyn* magazyn = podepnij_pamiec(shmid);

    magazyn->liczba_czesci = 0;
    magazyn->czy_gotowe = false;

    std::cout << "[RODZIC] Start - Liczba czesci: " << magazyn->liczba_czesci << std::endl;

    pid_t pid = fork();

    if(pid == -1) {
        perror("Blad fork");
        odlacz_i_usun_pamiec(magazyn, shmid, true);
        exit(EXIT_FAILURE);
    }

    if(pid == 0) {

        execl("./potomek", "potomek", NULL);
        perror("Blad excel");
        exit(EXIT_FAILURE);
    }

    wait(NULL);

    std::cout << "[RODZIC] Po pracy dziecka. Liczba czesci: " << magazyn->liczba_czesci << std::endl << "[RODZIC] Czy gotowe: " << magazyn->czy_gotowe << std::endl;
    
    odlacz_i_usun_pamiec(magazyn, shmid, true);

    return 0;
}