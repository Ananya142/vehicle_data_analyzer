#include "Auth.h"
#include <iostream>

bool Auth::login(std::string &role) {
    std::string username, password;

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Password: ";
    std::cin >> password;

    if (username == "admin" && password == "admin123") {
        role = "admin";
        return true;
    }

    if (username == "user" && password == "user123") {
        role = "user";
        return true;
    }

    return false;
}
