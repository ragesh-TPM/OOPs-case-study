#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <string>
#include <iostream>

class ParkingSpot {
protected:
    std::string spotID;
    bool isOccupied;
    
public:
    // Constructor
    ParkingSpot(const std::string& id) : spotID(id), isOccupied(false) {}
    
    // Destructor
    virtual ~ParkingSpot() = default;
    
    // Pure virtual functions for polymorphism
    virtual double calculateFee(int hours) const = 0;
    virtual std::string getSpotType() const = 0;
    virtual std::string getDescription() const = 0;
    
    // Common interface methods
    bool getIsOccupied() const { return isOccupied; }
    std::string getSpotID() const { return spotID; }
    void setOccupied(bool occupied) { isOccupied = occupied; }
    
    // Virtual method for status display
    virtual void displayStatus() const {
        std::cout << "Spot ID: " << spotID 
                  << ", Type: " << getSpotType()
                  << ", Status: " << (isOccupied ? "OCCUPIED" : "AVAILABLE")
                  << std::endl;
    }
};

#endif