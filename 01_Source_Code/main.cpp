#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "ParkingLot.h"
using namespace std;

int main() {
    ParkingLot parkingLot(10); // 10 parking slots
    int choice;
    
    cout << "=====================================" << endl;
    cout << "       SMART PARKING LOT SYSTEM      " << endl;
    cout << "=====================================" << endl;
    
    while (true) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Park Vehicle (Entry)" << endl;
        cout << "2. Exit Vehicle (Calculate Fee)" << endl;
        cout << "3. Display Parking Status" << endl;
        cout << "4. Display Available Slots" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice (1-5): ";
        
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string vehicleNumber;
                cout << "Enter vehicle number: ";
                cin >> vehicleNumber;
                parkingLot.parkVehicle(vehicleNumber);
                break;
            }
            case 2: {
                string vehicleNumber;
                cout << "Enter vehicle number to exit: ";
                cin >> vehicleNumber;
                parkingLot.exitVehicle(vehicleNumber);
                break;
            }
            case 3:
                parkingLot.displayStatus();
                break;
            case 4:
                parkingLot.displayAvailableSlots();
                break;
            case 5:
                cout << "Thank you for using Smart Parking Lot!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}