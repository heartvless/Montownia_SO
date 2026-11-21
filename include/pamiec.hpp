#pragma once
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct Magazyn {

    int liczba_czesci;
    bool czy_gotowe;

};

//tworzy klucz przyjmuje: tablice char (jako sciezke), char (jako dowolny znak) | zwraca: klucz key_t
key_t stworz_klucz(const char*, const char); 

//tworzy/dolacza pamiec, przyjmuje: key_t (jako klucz z ftok()), size_t (jako rozmiar z sizeof()) | zwraca: shmid int
int utworz_dolacz_pamiec(key_t, std::size_t);

//podpina pamiec pod wskaznik, przyjmuje: int (jako shmid - shared memory id z funkcji shmget()) | zwraca: wskaźnik Magazyn*
Magazyn* podepnij_pamiec(int);

//odlacza wskaznik oraz usuwa zarezerwowana wczesiej pamiec, przyjmuje: Magazyn* (jako wskaznik do miejsca w pamieci), int (jako shmid), bool (czy usunac)
void odlacz_i_usun_pamiec(Magazyn*, int, bool);
