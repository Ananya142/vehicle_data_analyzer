#include "VehicleManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <map>

using namespace std;

void VehicleManager::load() {
    ifstream file("vehicles.txt");
    if (!file) return;

    Vehicle v;
    while (file >> v.id >> v.make >> v.model >> v.year >> v.price >> v.category) {
        inventory.push_back(v);
        nextId = max(nextId, v.id + 1);
    }
}

void VehicleManager::save() {
    ofstream file("vehicles.txt");
    for (auto& v : inventory)
        file << v.id << " " << v.make << " " << v.model << " "
             << v.year << " " << v.price << " " << v.category << "\n";
}

void VehicleManager::addVehicle() {
    Vehicle v;
    v.id = nextId++;

    cout << "Make: "; cin >> v.make;
    cout << "Model: "; cin >> v.model;
    cout << "Year: "; cin >> v.year;
    cout << "Price: "; cin >> v.price;
    cout << "Category: "; cin >> v.category;

    inventory.push_back(v);
    cout << "Vehicle Added!\n";
}

void VehicleManager::displayAll() {
    cout << "\nID   Make    Model    Year   Price   Category\n";
    cout << "-----------------------------------------------\n";
    for (auto& v : inventory)
        cout << v.id << "   " << v.make << "   " << v.model << "   "
             << v.year << "   " << v.price << "   " << v.category << endl;
}

void VehicleManager::deleteVehicle(int id) {
    inventory.erase(remove_if(inventory.begin(), inventory.end(),
                    [id](Vehicle& v){ return v.id == id; }),
                    inventory.end());
}

void VehicleManager::updateVehicle(int id) {
    for (auto& v : inventory) {
        if (v.id == id) {
            cout << "New Price: ";
            cin >> v.price;
            return;
        }
    }
}

void VehicleManager::sortByPrice() {
    sort(inventory.begin(), inventory.end(),
         [](Vehicle& a, Vehicle& b) {
             return a.price < b.price;
         });
}

void VehicleManager::searchById(int id) {
    sort(inventory.begin(), inventory.end(),
         [](Vehicle& a, Vehicle& b) {
             return a.id < b.id;
         });

    int left = 0, right = inventory.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (inventory[mid].id == id) {
            cout << "Found: " << inventory[mid].make << endl;
            return;
        }
        if (inventory[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << "Not Found\n";
}

void VehicleManager::analytics() {
    double total = accumulate(inventory.begin(), inventory.end(), 0.0,
        [](double sum, Vehicle& v){ return sum + v.price; });

    cout << "Total Inventory Value: " << total << endl;

    map<string,int> count;
    for (auto& v : inventory)
        count[v.category]++;

    for (auto& p : count)
        cout << p.first << ": " << p.second << endl;
}
