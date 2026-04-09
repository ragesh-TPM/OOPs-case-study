#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <string>
#include <vector>
#include <ctime>

class ParkingSlot {
public:
    ParkingSlot();
    bool isOccupied() const;
    void parkVehicle(const std::string& vehicleNumber);
    void exitVehicle();
    std::string getVehicleNumber() const;
    time_t getEntryTime() const;
    double calculateFee() const;
    
private:
    std::string vehicleNumber;
    time_t entryTime;
    bool occupied;
};

class ParkingLot {
public:
    ParkingLot(int capacity);
    void parkVehicle(const std::string& vehicleNumber);
    void exitVehicle(const std::string& vehicleNumber);
    void displayStatus() const;
    void displayAvailableSlots() const;
    
private:
    std::vector<ParkingSlot> slots;
    int capacity;
    int findAvailableSlot() const;
    int findVehicleSlot(const std::string& vehicleNumber) const;
};

#endif