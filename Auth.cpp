#include "Auth.h"
#include <iostream>
#include <fstream>

using namespace std;

bool Auth::login(string& role) {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p, r;

    while (file >> u >> p >> r) {
        if (u == username && p == password) {
            role = r;
            return true;
        }
    }
    return false;
}

void Auth::registerUser() {
    ofstream file("users.txt", ios::app);
    string username, password, role;

    cout << "New Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Role (admin/user): ";
    cin >> role;

    file << username << " " << password << " " << role << "\n";
    cout << "User Registered Successfully!\n";
}
