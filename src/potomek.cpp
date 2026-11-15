#include "pamiec.hpp"

int main() {

    key_t key = stworz_klucz(".", 'M');

    int shmid = utworz_dolacz_pamiec(key, sizeof(Magazyn));
    Magazyn* magazyn = podepnij_pamiec(shmid);

    std::cout << "[DZIECKO] Wpisuje 777 do pamieci wspoldzielonej" << std::endl;
    magazyn->liczba_czesci = 777;
    magazyn->czy_gotowe = true;

    odlacz_i_usun_pamiec(magazyn, shmid, false);

    return 0;
}