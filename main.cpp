#include "VehicleManager.h"
#include "Auth.h"
#include <iostream>

using namespace std;

int main() {
    Auth auth;
    string role;

    cout << "1. Login\n2. Register\nChoice: ";
    int choice;
    cin >> choice;

    if (choice == 2)
        auth.registerUser();

    if (!auth.login(role)) {
        cout << "Login Failed!\n";
        return 0;
    }

    VehicleManager manager;
    manager.load();

    int option;
    do {
        cout << "\n===== Vehicle System =====\n";
        cout << "1. Add\n2. Display\n3. Delete\n4. Update\n5. Sort\n6. Search\n7. Analytics\n8. Exit\n";
        cin >> option;

        if (role != "admin" && option <= 4) {
            cout << "Only Admin Allowed!\n";
            continue;
        }

        switch(option) {
            case 1: manager.addVehicle(); break;
            case 2: manager.displayAll(); break;
            case 3: {
                int id; cin >> id;
                manager.deleteVehicle(id); break;
            }
            case 4: {
                int id; cin >> id;
                manager.updateVehicle(id); break;
            }
            case 5: manager.sortByPrice(); break;
            case 6: {
                int id; cin >> id;
                manager.searchById(id); break;
            }
            case 7: manager.analytics(); break;
            case 8: manager.save(); break;
        }

    } while(option != 8);

    return 0;
}
