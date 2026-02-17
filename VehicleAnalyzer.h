#ifndef VEHICLE_ANALYZER_H
#define VEHICLE_ANALYZER_H

#include "Vehicle.h"
#include <vector>

class VehicleAnalyzer {
public:
    static void generateReport(const std::vector<Vehicle>& inventory);
};

#endif
