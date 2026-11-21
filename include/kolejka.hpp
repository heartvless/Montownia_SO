#pragma once
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct KomunikatT {
    long mtype;
    int position;
    int weight;
};

int stworz_pobierz_kolejke(key_t);
int dodaj_do_kolejki(int, const KomunikatT*);
int pobierz_z_kolejki(int, KomunikatT*, long);
int usun_kolejke(int);