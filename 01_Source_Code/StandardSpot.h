#ifndef STANDARDSPOT_H
#define STANDARDSPOT_H

#include "ParkingSpot.h"

class StandardSpot : public ParkingSpot {
public:
    StandardSpot(const std::string& id) : ParkingSpot(id) {}
    
    double calculateFee(int hours) const override {
        return hours * 2.0; // $2 per hour
    }
    
    std::string getSpotType() const override {
        return "Standard";
    }
    
    std::string getDescription() const override {
        return "Standard parking spot - $2/hour";
    }
};

#endif