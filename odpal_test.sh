#!/bin/bash
set -e
g++ -Iinclude src/test_main.cpp src/pamiec.cpp src/semafor.cpp src/klucz.cpp -o test_main
g++ -Iinclude src/potomek.cpp src/pamiec.cpp src/semafor.cpp src/klucz.cpp -o potomek
./test_main
ipcs -m
ipcs -s
ipcs -q

#ipcs -m -i shmid/semid
#ps -p PID -o pid,ppid,cmd
