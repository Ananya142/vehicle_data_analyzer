#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include "Vehicle.h"
#include <vector>

class VehicleManager {
private:
    std::vector<Vehicle> inventory;
    int nextId = 1;

public:
    void load();
    void save();
    void addVehicle();
    void displayAll();
    void deleteVehicle(int id);
    void updateVehicle(int id);
    void sortByPrice();
    void searchById(int id);
    void analytics();
};

#endif
