#include <cstdlib>
#include <cstdio>
#include "kolejka.hpp"

int stworz_kolejke(key_t klucz) {

    int msgid = msgget(klucz, IPC_CREAT | IPC_EXCL | 0600);

    if(msgid == -1) {
        perror("Blad msgget (TWORZENIE)");
        exit(EXIT_FAILURE);
    }

    return msgid;
}

int dolacz_kolejke(key_t klucz) {

    int msgid = msgget(klucz, 0600);

    if(msgid == -1) {
        perror("Blad msgget (DOLACZANIE)");
        exit(EXIT_FAILURE);
    }

    return msgid;

}

/*int dodaj_do_kolejki(int msgid, const KomunikatT* Komunikat, std::size_t rozmiar) {

    int cos = msgsnd(msgid, Komunikat*)
}
    */