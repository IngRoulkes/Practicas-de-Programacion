#include <iostream>
#include <string>
#include <json.hpp>

std::string get_data(nlohmann::json obj){
    std::string name, lastname,email;
    int age;

    name = obj["user_data"]["name"].get<std::string>();
    lastname = obj["user_data"]["lastname"].get<std::string>();
    email = obj["user_metadata"]["email"].get<std::string>();
    age = obj["user_data"]["age"].get<int>(); 
    return "Hola mi nombre es: " + name + " y mi apellido es: " + lastname + " tengo " + std::to_string(age) + " anios y mi email es: " + email;
}
int main(){
    nlohmann::json miobjeto;
    miobjeto["user_data"]["name"]="aaron";
    miobjeto["user_data"]["lastname"]="gordillo";
    miobjeto["user_data"]["age"]=22;
    miobjeto["user_metadata"]["email"]="email@.com";

    std::cout << miobjeto.dump() << std::endl;
    std::cout << "----------------" << std::endl;
    

    std::cout <<  get_data(miobjeto)<< std::endl;
    return 0;
}