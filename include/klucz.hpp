#pragma once
#include <sys/types.h>
#include <sys/ipc.h>

//tworzy klucz przyjmuje: tablice char (jako sciezke), char (jako dowolny znak) | zwraca: klucz key_t
key_t stworz_klucz(const char*, const char); 