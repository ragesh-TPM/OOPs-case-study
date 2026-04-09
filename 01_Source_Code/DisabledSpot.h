#ifndef DISABLEDSPOT_H
#define DISABLEDSPOT_H

#include "ParkingSpot.h"

class DisabledSpot : public ParkingSpot {
public:
    DisabledSpot(const std::string& id) : ParkingSpot(id) {}
    
    double calculateFee(int hours) const override {
        return hours * 0.5; // $0.50 per hour (discounted)
    }
    
    std::string getSpotType() const override {
        return "Disabled";
    }
    
    std::string getDescription() const override {
        return "Disabled parking spot - $0.50/hour (discounted)";
    }
};

#endif