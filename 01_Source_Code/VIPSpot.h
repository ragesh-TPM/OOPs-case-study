#ifndef VIPSPOT_H
#define VIPSPOT_H

#include "ParkingSpot.h"

class VIPSpot : public ParkingSpot {
public:
    VIPSpot(const std::string& id) : ParkingSpot(id) {}
    
    double calculateFee(int hours) const override {
        return 10.0 + (hours * 5.0); // $10 flat + $5/hour premium
    }
    
    std::string getSpotType() const override {
        return "VIP";
    }
    
    std::string getDescription() const override {
        return "VIP parking spot - $10 + $5/hour (premium)";
    }
};

#endif