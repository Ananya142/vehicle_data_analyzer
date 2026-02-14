#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth {
public:
    bool login(std::string& role);
    void registerUser();
};

#endif
