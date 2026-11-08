#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    std::cout << "POCZATEK PROGRAMU PRZED FORK\n\n";
    std::cout << "ID GLOWNEGO PROCESU: " << getpid() << "\n\n";

    //tworzenie dziecka funkcja fork
    pid_t dziecko = fork();

    //sprawdzanie warunków istnienia wzgledem tego co zwroci fork - (< 0: blad), (== 0: dziecko), (inna liczba: rodzic)
    if(dziecko < 0) {
        
        //kanal bledow cerr
        std::cerr << "Blad podczas tworzenia procesu!\n\n";
        return 1;

    } else if(dziecko == 0) {

        std::cout << "Jestem dzieckiem! Moje PID to: " << getpid() << " , a PID mojego rodzica to: " << getppid();
        std::cout << "\n\n";

    } else {

        std::cout << "Jestem rodzicem, utworzylem dziecko o PID: " << dziecko << " , a moje wlasne PID to: " << getpid();
        std::cout << "\n\n";

    }
    
    std::cout << "KONIEC, wykonany przez proces: " << getpid() << "\n\n";
    
    return 0;
}