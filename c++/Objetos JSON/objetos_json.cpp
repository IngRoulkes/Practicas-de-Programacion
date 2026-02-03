#include <iostream>
#include <string>
#include <json.hpp>
int main(){
    nlohmann::json miobjeto;
    miobjeto["user_data"]["name"]="aaron";
    miobjeto["user_data"]["lastname"]="gordillo";
    miobjeto["user_data"]["age"]=22;
    miobjeto["user_metadata"]["email"]="email@.com";

    std::cout << miobjeto.dump() << std::endl;
    std::cout << "----------------" << std::endl;
    std::string name, lastname,email;
    int age;

    name = miobjeto["user_data"]["name"].get<std::string>();
    lastname = miobjeto["user_data"]["lastname"].get<std::string>();
    email = miobjeto["user_metadata"]["email"].get<std::string>();
    age = miobjeto["user_data"]["age"].get<int>();
    std::string mensaje;
    mensaje = "Hola mi nombre es: " + name + " y mi apellido es: " + lastname + " tengo " + std::to_string(age) + " anios y mi email es: " + email;
    std::cout << mensaje<< std::endl;
    return 0;
}