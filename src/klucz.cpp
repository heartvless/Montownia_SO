#include <cstdlib>
#include <cstdio>
#include "klucz.hpp"

key_t stworz_klucz(const char *path, const char name_ch) {

    key_t key = ftok(path, name_ch);

    if(key == -1) {
        perror("Blad ftok");
        exit(EXIT_FAILURE);
    }   

    return key;
}