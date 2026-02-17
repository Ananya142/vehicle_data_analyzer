#ifndef VEHICLE_MANAGER_H
#define VEHICLE_MANAGER_H

#include "Vehicle.h"
#include <vector>
#include <string>

class VehicleManager {
private:
    std::vector<Vehicle> inventory;
    std::string filename;
    int nextId;

    void loadFromFile();
    void saveToFile() const;
    void sortById();
    void printHeader() const;

public:
    VehicleManager(const std::string& file);

    void addVehicle();
    void updateVehicle();
    void deleteVehicle();
    void displayAll() const;
    void searchByIdBinary();
    void generateReport() const;
};

#endif
