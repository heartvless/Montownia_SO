#include "header.hpp"

int main() {
    
    std::cout << "PID glownego procesu: " << getpid() << "\n\n";

    pid_t dziecko = fork();

    if(dziecko < 0) {

        std::cerr << "Blad fork!\n\n";
        return 1;

    } else if(dziecko == 0) {

        std::cout << "Dziecko za chwile podmieni swoj kod funkcji excel!\n\n";

        execl("./potomek", "potomek", NULL);

        std::cerr << "Blad execl!\n\n";
        return 1;
        

    } else {

        wypisz_pid(getpid(), "rodzic");
        std::cout << "Czekam az potomek skonczy...\n\n";
        wait(NULL);
        std::cout << "Potomek zakonczyl prace. Koniec programu glownego!\n\n";

    }

    return 0;
}