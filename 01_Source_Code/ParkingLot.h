#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "ParkingSpot.h"
#include "StandardSpot.h"
#include "DisabledSpot.h"
#include "VIPSpot.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <iomanip>

class ParkingLot {
private:
    std::vector<ParkingSpot*> spots; // Polymorphic array
    
public:
    ParkingLot() {}
    ~ParkingLot() {
        // Proper cleanup of polymorphic array
        for (auto spot : spots) {
            delete spot;
        }
    }
    
    void initializeLot() {
        // Clear existing spots
        for (auto spot : spots) {
            delete spot;
        }
        spots.clear();
        
        // Create mixed parking spots (20 total: 12 Standard, 4 Disabled, 4 VIP)
        for (int i = 1; i <= 12; ++i) {
            spots.push_back(new StandardSpot("S" + std::to_string(i)));
        }
        for (int i = 1; i <= 4; ++i) {
            spots.push_back(new DisabledSpot("D" + std::to_string(i)));
        }
        for (int i = 1; i <= 4; ++i) {
            spots.push_back(new VIPSpot("V" + std::to_string(i)));
        }
    }
    
    bool parkVehicle(const std::string& spotType, int hours) {
        // Find first available spot of specified type
        for (auto spot : spots) {
            if (!spot->getIsOccupied() && spot->getSpotType() == spotType) {
                spot->setOccupied(true);
                std::cout << "Vehicle parked in " << spot->getSpotID() 
                          << " (" << spot->getDescription() << ")" << std::endl;
                return true;
            }
        }
        std::cout << "No available " << spotType << " spots!" << std::endl;
        return false;
    }
    
    double exitVehicle(const std::string& spotID, int hours) {
        // Find spot by ID
        for (auto spot : spots) {
            if (spot->getSpotID() == spotID) {
                if (!spot->getIsOccupied()) {
                    std::cout << "Spot " << spotID << " is already empty!" << std::endl;
                    return 0.0;
                }
                
                // Polymorphic fee calculation
                double fee = spot->calculateFee(hours);
                spot->setOccupied(false);
                
                std::cout << "Vehicle exited from " << spotID 
                          << " (" << spot->getSpotType() << ")" << std::endl;
                std::cout << "Parking duration: " << hours << " hours" << std::endl;
                std::cout << "Total fee: $" << std::fixed << std::setprecision(2) << fee << std::endl;
                std::cout << std::string(50, '-') << std::endl;
                return fee;
            }
        }
        std::cout << "Spot " << spotID << " not found!" << std::endl;
        return 0.0;
    }
    
    void displayStatus() const {
        std::cout << "\n=== PARKING LOT STATUS ===" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        
        int occupiedCount = 0;
        for (const auto spot : spots) {
            spot->displayStatus();
            if (spot->getIsOccupied()) occupiedCount++;
        }
        
        double occupancy = (static_cast<double>(occupiedCount) / spots.size()) * 100.0;
        std::cout << std::string(50, '=') << std::endl;
        std::cout << "Total Spots: " << spots.size() << std::endl;
        std::cout << "Occupied Spots: " << occupiedCount << std::endl;
        std::cout << "Occupancy: " << std::fixed << std::setprecision(1) << occupancy << "%" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }
    
    size_t getTotalSpots() const { return spots.size(); }
};

#endif