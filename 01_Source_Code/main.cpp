#include "ParkingLot.h"
#include <iostream>
#include <iomanip>
#include <limits>

void displayMenu() {
    std::cout << "\n=== SMART PARKING LOT SYSTEM ===" << std::endl;
    std::cout << "1. Initialize Parking Lot" << std::endl;
    std::cout << "2. Park Vehicle (Standard)" << std::endl;
    std::cout << "3. Park Vehicle (Disabled)" << std::endl;
    std::cout << "4. Park Vehicle (VIP)" << std::endl;
    std::cout << "5. Exit Vehicle" << std::endl;
    std::cout << "6. Display Status" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter choice: ";
}

int main() {
    ParkingLot lot;
    int choice;
    
    std::cout << "Welcome to Smart Parking Lot Management System!" << std::endl;
    
    do {
        displayMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                lot.initializeLot();
                std::cout << "Parking lot initialized with 20 spots!" << std::endl;
                break;
                
            case 2: {
                int hours;
                std::cout << "Enter parking hours: ";
                std::cin >> hours;
                lot.parkVehicle("Standard", hours);
                break;
            }
                
            case 3: {
                int hours;
                std::cout << "Enter parking hours: ";
                std::cin >> hours;
                lot.parkVehicle("Disabled", hours);
                break;
            }
                
            case 4: {
                int hours;
                std::cout << "Enter parking hours: ";
                std::cin >> hours;
                lot.parkVehicle("VIP", hours);
                break;
            }
                
            case 5: {
                std::string spotID;
                int hours;
                std::cout << "Enter Spot ID (e.g., V1, S5, D2): ";
                std::cin >> spotID;
                std::cout << "Enter parking hours: ";
                std::cin >> hours;
                lot.exitVehicle(spotID, hours);
                break;
            }
                
            case 6:
                lot.displayStatus();
                break;
                
            case 0:
                std::cout << "Thank you for using Smart Parking Lot System!" << std::endl;
                break;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    } while (choice != 0);
    
    return 0;
}