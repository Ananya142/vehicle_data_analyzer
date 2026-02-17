#include <iostream>
#include "Auth.h"
#include "VehicleManager.h"

void showMenu() {
    std::cout << "\n=== Vehicle Inventory System ===\n";
    std::cout << "1. Add Vehicle\n";
    std::cout << "2. Update Vehicle (Admin)\n";
    std::cout << "3. Delete Vehicle (Admin)\n";
    std::cout << "4. Display All\n";
    std::cout << "5. Search by ID (Binary Search)\n";
    std::cout << "6. Generate Report\n";
    std::cout << "7. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    Auth auth;
    VehicleManager manager("vehicles.txt");

    std::string role;
    if (!auth.login(role)) {
        std::cout << "Invalid login.\n";
        return 0;
    }

    std::cout << "Logged in as: " << role << "\n";

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: manager.addVehicle(); break;
            case 2:
                if (role == "admin") manager.updateVehicle();
                else std::cout << "Admin only feature.\n";
                break;
            case 3:
                if (role == "admin") manager.deleteVehicle();
                else std::cout << "Admin only feature.\n";
                break;
            case 4: manager.displayAll(); break;
            case 5: manager.searchByIdBinary(); break;
            case 6: manager.generateReport(); break;
            case 7: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}
