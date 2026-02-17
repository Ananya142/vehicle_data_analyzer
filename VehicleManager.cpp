#include "VehicleManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <iomanip>

// Constructor
VehicleManager::VehicleManager(const std::string& file)
    : filename(file), nextId(1) {
    loadFromFile();
}

// Load data
void VehicleManager::loadFromFile() {
    std::ifstream file(filename);
    if (!file) return;

    inventory.clear();

    int id, year;
    double price;
    std::string make, model, category;

    while (file >> id >> make >> model >> year >> price >> category) {
        inventory.emplace_back(id, make, model, year, price, category);
        nextId = std::max(nextId, id + 1);
    }
}

// Save data
void VehicleManager::saveToFile() const {
    std::ofstream file(filename);

    for (const auto& v : inventory) {
        file << v.id << " "
             << v.make << " "
             << v.model << " "
             << v.year << " "
             << v.price << " "
             << v.category << "\n";
    }
}

// Print header
void VehicleManager::printHeader() const {
    std::cout << "\n"
              << std::left
              << std::setw(5)  << "ID"
              << std::setw(15) << "Make"
              << std::setw(15) << "Model"
              << std::setw(8)  << "Year"
              << std::setw(10) << "Price"
              << std::setw(10) << "Category"
              << "\n"
              << std::string(65, '-') << "\n";
}

// Add vehicle
void VehicleManager::addVehicle() {
    std::string make, model, category;
    int year;
    double price;

    std::cout << "Enter Make: ";
    std::cin >> make;

    std::cout << "Enter Model: ";
    std::cin >> model;

    std::cout << "Enter Year: ";
    std::cin >> year;

    std::cout << "Enter Price: ";
    std::cin >> price;

    std::cout << "Enter Category: ";
    std::cin >> category;

    if (year <= 0 || price < 0) {
        std::cout << "Invalid input.\n";
        return;
    }

    inventory.emplace_back(nextId++, make, model, year, price, category);
    saveToFile();

    std::cout << "Vehicle added successfully.\n";
}

// Update vehicle
void VehicleManager::updateVehicle() {
    int id;
    std::cout << "Enter Vehicle ID to update: ";
    std::cin >> id;

    for (auto& v : inventory) {
        if (v.id == id) {
            std::cout << "Enter New Make: ";
            std::cin >> v.make;

            std::cout << "Enter New Model: ";
            std::cin >> v.model;

            std::cout << "Enter New Year: ";
            std::cin >> v.year;

            std::cout << "Enter New Price: ";
            std::cin >> v.price;

            std::cout << "Enter New Category: ";
            std::cin >> v.category;

            saveToFile();
            std::cout << "Vehicle updated successfully.\n";
            return;
        }
    }

    std::cout << "Vehicle not found.\n";
}

// Delete vehicle
void VehicleManager::deleteVehicle() {
    int id;
    std::cout << "Enter Vehicle ID to delete: ";
    std::cin >> id;

    auto originalSize = inventory.size();

    inventory.erase(
        std::remove_if(inventory.begin(), inventory.end(),
            [id](const Vehicle& v) {
                return v.id == id;
            }),
        inventory.end()
    );

    if (inventory.size() < originalSize) {
        saveToFile();
        std::cout << "Vehicle deleted successfully.\n";
    } else {
        std::cout << "Vehicle not found.\n";
    }
}

// Sort by ID
void VehicleManager::sortById() {
    std::sort(inventory.begin(), inventory.end(),
        [](const Vehicle& a, const Vehicle& b) {
            return a.id < b.id;
        });
}

// Binary search
void VehicleManager::searchByIdBinary() {
    if (inventory.empty()) {
        std::cout << "Inventory empty.\n";
        return;
    }

    int id;
    std::cout << "Enter Vehicle ID to search: ";
    std::cin >> id;

    sortById();

    int left = 0, right = inventory.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (inventory[mid].id == id) {
            printHeader();
            inventory[mid].display();
            return;
        }
        else if (inventory[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << "Vehicle not found.\n";
}

// Display all
void VehicleManager::displayAll() const {
    if (inventory.empty()) {
        std::cout << "Inventory empty.\n";
        return;
    }

    printHeader();
    for (const auto& v : inventory)
        v.display();

    std::cout << "\nTotal Vehicles: " << inventory.size() << "\n";
}

// Generate report
void VehicleManager::generateReport() const {
    if (inventory.empty()) {
        std::cout << "No vehicles available.\n";
        return;
    }

    std::map<std::string, int> categoryCount;

    double totalValue = std::accumulate(
        inventory.begin(),
        inventory.end(),
        0.0,
        [](double sum, const Vehicle& v) {
            return sum + v.price;
        });

    for (const auto& v : inventory)
        categoryCount[v.category]++;

    std::cout << "\n--- Inventory Analysis ---\n";
    std::cout << "Total Vehicles: " << inventory.size() << "\n";
    std::cout << "Total Inventory Value: $" << totalValue << "\n";
    std::cout << "Average Price: $" << totalValue / inventory.size() << "\n";

    std::cout << "\nCategory Distribution:\n";
    for (const auto& pair : categoryCount)
        std::cout << pair.first << " : " << pair.second << "\n";

    std::cout << "----------------------------\n";
}
