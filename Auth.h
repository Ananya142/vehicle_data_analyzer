#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <fstream>
#include <string>
#include <functional>

using namespace std;

class Auth {
public:
    void registerUser();
    bool login(string &role);
private:
    string hashPassword(const string &password);
};

#endif
