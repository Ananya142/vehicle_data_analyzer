#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

struct Vehicle {
    int id;
    std::string make;
    std::string model;
    int year;
    double price;
    std::string category;
};

#endif
