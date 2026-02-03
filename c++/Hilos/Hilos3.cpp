#include<iostream>
#include<thread>

void mostrarnumero(int x){
    std::cout << "HIlo recibio: "<< x <<std::endl;
}

void suma(int a, int b){
    std::cout << "suma: "<<a + b << std::endl;
}

void ciclo(int n){
    for(int i=1; i<=n; i++){
        std::cout << "i= "<<i <<std::endl;
    }
}

int main (){
    std::thread t(mostrarnumero, 10);
    std::thread t2(suma,4,6);
    std::thread t3(ciclo, 6);
    t2.join();
    t.join();
    t3.join();

    return 0;
}