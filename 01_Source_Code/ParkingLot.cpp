#include "ParkingLot.h"
#include <iostream>
#include <iomanip>
#include <ctime>

ParkingSlot::ParkingSlot() : occupied(false), entryTime(0) {}

bool ParkingSlot::isOccupied() const {
    return occupied;
}

void ParkingSlot::parkVehicle(const std::string& vehicleNumber) {
    this->vehicleNumber = vehicleNumber;
    this->entryTime = time(nullptr);
    this->occupied = true;
}

void ParkingSlot::exitVehicle() {
    this->occupied = false;
    this->vehicleNumber = "";
    this->entryTime = 0;
}

std::string ParkingSlot::getVehicleNumber() const {
    return vehicleNumber;
}

time_t ParkingSlot::getEntryTime() const {
    return entryTime;
}

double ParkingSlot::calculateFee() const {
    if (!occupied) return 0.0;
    
    time_t currentTime = time(nullptr);
    double hours = difftime(currentTime, entryTime) / 3600.0;
    
    // Fee calculation: $2 for first hour, $1 for each additional hour
    double fee = 2.0;
    if (hours > 1.0) {
        fee += (hours - 1.0) * 1.0;
    }
    return fee;
}

ParkingLot::ParkingLot(int capacity) : capacity(capacity) {
    slots.resize(capacity);
}

void ParkingLot::parkVehicle(const std::string& vehicleNumber) {
    int slotIndex = findAvailableSlot();
    
    if (slotIndex == -1) {
        std::cout << "Sorry! Parking lot is FULL." << std::endl;
        return;
    }
    
    slots[slotIndex].parkVehicle(vehicleNumber);
    time_t entryTime = slots[slotIndex].getEntryTime();
    std::cout << "\nVehicle " << vehicleNumber 
              << " parked successfully at Slot " << (slotIndex + 1) << "!" << std::endl;
    std::cout << "Entry Time: " 
              << std::ctime(&entryTime);
}

void ParkingLot::exitVehicle(const std::string& vehicleNumber) {
    int slotIndex = findVehicleSlot(vehicleNumber);
    
    if (slotIndex == -1) {
        std::cout << "Vehicle " << vehicleNumber << " not found in parking lot!" << std::endl;
        return;
    }
    
    double fee = slots[slotIndex].calculateFee();
    time_t entryTime = slots[slotIndex].getEntryTime();
    
    std::cout << "\nVehicle Exit Details:" << std::endl;
    std::cout << "Vehicle: " << vehicleNumber << std::endl;
    std::cout << "Slot: " << (slotIndex + 1) << std::endl;
    std::cout << "Entry Time: " << std::ctime(&entryTime);
    std::cout << "Total Fee: $" << std::fixed << std::setprecision(2) << fee << std::endl;
    std::cout << "Please pay $" << std::fixed << std::setprecision(2) << fee << std::endl;
    
    slots[slotIndex].exitVehicle();
    std::cout << "Vehicle exited successfully!" << std::endl;
}

void ParkingLot::displayStatus() const {
    std::cout << "\nPARKING LOT STATUS (" << capacity << " slots):" << std::endl;
    std::cout << std::left << std::setw(8) << "Slot" 
              << std::setw(12) << "Status" 
              << std::setw(15) << "Vehicle #" 
              << "Entry Time" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    for (int i = 0; i < capacity; ++i) {
        std::cout << std::left << std::setw(8) << (i + 1);
        if (slots[i].isOccupied()) {
            std::cout << std::setw(12) << "OCCUPIED";
            std::cout << std::setw(15) << slots[i].getVehicleNumber();
            time_t entryTime = slots[i].getEntryTime();
            std::cout << std::ctime(&entryTime);
        } else {
            std::cout << std::setw(12) << "AVAILABLE";
            std::cout << std::setw(15) << "-";
            std::cout << "-" << std::endl;
        }
    }
    
    int occupiedCount = 0;
    for (const auto& slot : slots) {
        if (slot.isOccupied()) occupiedCount++;
    }
    std::cout << "\nOccupancy: " << occupiedCount << "/" << capacity 
              << " (" << (occupiedCount * 100.0 / capacity) << "%)" << std::endl;
}

void ParkingLot::displayAvailableSlots() const {
    std::cout << "\nAVAILABLE SLOTS:" << std::endl;
    bool hasAvailable = false;
    for (int i = 0; i < capacity; ++i) {
        if (!slots[i].isOccupied()) {
            std::cout << "Slot " << (i + 1) << std::endl;
            hasAvailable = true;
        }
    }
    if (!hasAvailable) {
        std::cout << "No available slots!" << std::endl;
    }
}

int ParkingLot::findAvailableSlot() const {
    for (int i = 0; i < capacity; ++i) {
        if (!slots[i].isOccupied()) {
            return i;
        }
    }
    return -1;
}

int ParkingLot::findVehicleSlot(const std::string& vehicleNumber) const {
    for (int i = 0; i < capacity; ++i) {
        if (slots[i].isOccupied() && slots[i].getVehicleNumber() == vehicleNumber) {
            return i;
        }
    }
    return -1;
}