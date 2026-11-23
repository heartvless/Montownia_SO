#pragma once
#include <cstddef>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

//tworzy semafory, przyjmuje: key_t (jako klucz z ftok()), int (jako liczba semaforow) | zwraca: semid int
int utworz_semafory(key_t, int);

//dolacza semafory, przyjmuje: key_t (jako klucz z ftok()), int (jako liczba semaforow) | zwraca: semid int
int dolacz_semafory(key_t, int);

//ustawia semafor, przyjmuje: int (jako semid), int (jako numer semafora), int (jako wartosc semafora)
void ustaw_semafor(int, int, int);

//zajecie zasobu przez proces (Operacja P), przyjmuje: int (jako semid), int (jako numer semafora)
void opusc_semafor(int, int);

//zwolnienie zasobu przez proces (Operacja V), przyjmuje: int (jako semid), int (jako numer semafora)
void podnies_semafor(int, int);

//usuwa semafory, przyjmuje: int (jako semid)
void usun_semafory(int);