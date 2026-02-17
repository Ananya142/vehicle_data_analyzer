#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>

struct Vehicle {
    int id;
    std::string make;
    std::string model;
    int year;
    double price;
    std::string category;

    Vehicle() {}

    Vehicle(int id, std::string make,
            std::string model, int year,
            double price, std::string category)
        : id(id), make(make), model(model),
          year(year), price(price), category(category) {}

    void display() const {
        std::cout << std::left
                  << std::setw(5) << id
                  << std::setw(15) << make
                  << std::setw(15) << model
                  << std::setw(8) << year
                  << std::setw(10) << price
                  << std::setw(10) << category
                  << std::endl;
    }
};

#endif
