#include <iostream> 
#include <string> 
#include <vector> 

int main (){
    std::vector<std::string> nombres = {"irma", "pablo", "diego"};
    nombres.push_back("aaron");
    nombres.push_back("juan");
    nombres.push_back("pepe");
    nombres.push_back("maria");
    nombres.push_back("carlos");

    std::cout<< "numero de nombres: "<< nombres.size() <<std::endl;

    // iterando con un for_each
    for(const std::string nombre : nombres){
        std::cout << "nombre: " << nombre << std::endl;
    }
     std::cout << std::endl << std::endl;

    // iterando con un for y eliminando del vector 

    for(auto it= nombres.begin(); it != nombres.end();){ // abreviatura de for (int i = 0; i < nombres.size(); i++)
        std::cout << "*it: " << *it << std::endl;
        if (*it == "pepe" || *it == "pablo"){
            it = nombres.erase(it);
        } else {
            it++;
        }
    }
    
    
    std::cout<<"\n\nnueva lista"<< std::endl;
    for(const std::string nombre : nombres){
        std::cout << "nombre: " << nombre << std::endl;
    }
    return 0;
}