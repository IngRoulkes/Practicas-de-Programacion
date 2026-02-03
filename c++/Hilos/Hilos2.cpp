#include <iostream>
#include <thread>
#include <chrono>

void hilojoin() {
    std::cout << "este es el hilo join" << std::endl;
}

void hilodetach() {
    std::cout << "este es el hilo detach" << std::endl;
}

int main() {
    std::cout << "inicio del programa" << std::endl;

    std::thread t1(hilojoin);
    std::thread t2(hilodetach);

    t2.detach(); // Es preferible poner primero el detach

    std::this_thread::sleep_for(std::chrono::seconds(10)); //hacemos esperar 10 segundos al join

    t1.join(); 

    std::cout << "Fin del programa" << std::endl;

    return 0;
}
