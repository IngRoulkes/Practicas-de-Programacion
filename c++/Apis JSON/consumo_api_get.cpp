#include <iostream>
#include <string>
#include <vector>
#include <json.hpp>
#include <CURL.hpp>


void show_results(nlohmann::json objeto){
    std::string name, username, email, phone, company;
    int id;
    for (const auto& item : objeto ){
        name = item["name"].get<std::string>();
        username = item["username"].get<std::string>();
        email = item["email"].get<std::string>();
        id = item["id"].get<int>();
        phone = item ["phone"].get<std::string>();
        company = item ["company"]["name"].get<std::string>();

        std::cout << name <<" - " <<  username <<" - " << email <<" - " << phone << " - " << company << id << std::endl;
    }
}

int main (){

    std::string url = "https://jsonplaceholder.typicode.com/users";
    std::vector<std::string> headers = {"Content-Type: application/json"};
    bool consume = false;
    long http_code;
    std::string response_str = {};
    consume = perform_curl_get_request(url, headers, response_str, &http_code);
    nlohmann::json respuesta_obj;
    

    if (consume && http_code == 200){
        std::cout << "CONSUMO EXITOSO" << std::endl;
        std::cout << response_str << std::endl;
        respuesta_obj = nlohmann::json::parse(response_str);
        show_results(respuesta_obj);
    }else{
        std::cout << "CONSUMO ERRONEO" << std::endl;
        std::cout << response_str << std::endl;
    }

    return 0;
}