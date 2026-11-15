#pragma once

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstdlib>
#include <cstdio>

struct Magazyn {

    int liczba_czesci;
    bool czy_gotowe;

};

key_t stworz_klucz(const char*, const char); //tworzy klucz, przyjmuje: tablice char (jako sciezke), char (jako dowolny znak)

int utworz_dolacz_pamiec(key_t, std::size_t); //dolacza pamiec, przyjmuje: key_t (jako klucz z ftok()), size_t (jako rozmiar z sizeof())

Magazyn* podepnij_pamiec(int); //podpina pamiec pod wskaznik, przyjmuje: int (jako shmid - shared memory id z funkcji shmget())

void odlacz_i_usun_pamiec(Magazyn*, int, bool); //odlacza wskaznik oraz usuwa zarezerwowana wczesiej pamiec, przyjmuje: Magazyn* (jako wskaznik do miejsca w pamieci), int (jako shmid), bool (czy usunac)
