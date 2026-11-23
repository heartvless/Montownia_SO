#pragma once
#include <cstddef>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct KomunikatT {
    long mtype;
    int position;
    int weight;
};

//Do dodania wiecej msgtyp funkcji do pobierz z kolejki lub switch w srodku 
int stworz_kolejke(key_t);
int dolacz_kolejke(key_t);
int dodaj_do_kolejki(int, const KomunikatT*, std::size_t rozmiar = (sizeof(KomunikatT)) - sizeof(long));
int pobierz_z_kolejki(int, KomunikatT*, long, std::size_t rozmiar = (sizeof(KomunikatT)) - sizeof(long));
int usun_kolejke(int);