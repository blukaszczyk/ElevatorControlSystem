#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "Building.h"
#include "Request.h"

using namespace std;

void displayMenu() {
    cout << "\n========================================\n";
    cout << "     ELEVATOR CONTROL SYSTEM MENU       \n";
    cout << "========================================\n";
    cout << "1. Call elevator to floor\n";
    cout << "2. Request elevator to take you to floor\n";
    cout << "3. Show all elevator status\n";
    cout << "4. Run automatic simulation\n";
    cout << "5. Add multiple custom requests\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
    cout << "Your choice: ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidIntInput() {
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input! Please enter a number: ";
        clearInputBuffer();
    }
    return input;
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    cout << "========================================\n";
    cout << "   WELCOME TO ELEVATOR CONTROL SYSTEM   \n";
    cout << "========================================\n";
    
    // Ask how many elevators
    int numElevators;
    cout << "How many elevators in the building? (1-5): ";
    numElevators = getValidIntInput();
    
    if (numElevators < 1) numElevators = 1;
    if (numElevators > 5) numElevators = 5;
    
    Building building(numElevators);
    
    int choice;
    do {
        displayMenu();
        choice = getValidIntInput();
        
        switch(choice) {
            case 1: {
                // Call elevator to floor
                int floor;
                cout << "Which floor are you on? (0-10): ";
                floor = getValidIntInput();
                
                if (floor < 0 || floor > 10) {
                    cout << "Invalid floor! Please use floor 0-10.\n";
                } else {
                    building.addRequest(Request(floor, floor));
                    cout << "\n--- Processing request ---\n";
                    building.simulateStep();
                }
                break;
            }
            
            case 2: {
                // Full request: from floor to destination
                int pickupFloor, destinationFloor;
                cout << "Current floor (where you are): ";
                pickupFloor = getValidIntInput();
                cout << "Destination floor (where you want to go): ";
                destinationFloor = getValidIntInput();
                
                if (pickupFloor < 0 || pickupFloor > 10 || 
                    destinationFloor < 0 || destinationFloor > 10) {
                    cout << "Invalid floor! Please use floor 0-10.\n";
                } else if (pickupFloor == destinationFloor) {
                    cout << "You're already on that floor!\n";
                } else {
                    building.addRequest(Request(pickupFloor, destinationFloor));
                    cout << "\n--- Processing request ---\n";
                    building.simulateStep();
                }
                break;
            }
            
            case 3: {
                // Show all elevators
                building.displayAllElevators();
                break;
            }
            
            case 4: {
                // Run automatic simulation
                cout << "\n--- Running Automatic Simulation ---\n";
                cout << "How many random requests? ";
                int numRequests = getValidIntInput();
                
                for (int i = 0; i < numRequests; i++) {
                    int pickup = rand() % 11;
                    int dest = rand() % 11;
                    while (dest == pickup) dest = rand() % 11;
                    
                    cout << "\nRequest " << (i+1) << ": Floor " << pickup 
                          << " -> Floor " << dest << "\n";
                    building.addRequest(Request(pickup, dest));
                    building.simulateStep();
                }
                break;
            }
            
            case 5: {
                // Add multiple custom requests
                cout << "How many requests to add? ";
                int numRequests = getValidIntInput();
                
                for (int i = 0; i < numRequests; i++) {
                    cout << "\n--- Request " << (i+1) << " ---\n";
                    cout << "Pickup floor: ";
                    int pickup = getValidIntInput();
                    cout << "Destination floor: ";
                    int dest = getValidIntInput();
                    
                    if (pickup >= 0 && pickup <= 10 && dest >= 0 && dest <= 10) {
                        building.addRequest(Request(pickup, dest));
                    } else {
                        cout << "Skipping invalid request (floors must be 0-10)\n";
                    }
                }
                
                cout << "\n--- Processing all requests ---\n";
                building.simulateStep();
                break;
            }
            
            case 0: {
                cout << "Thank you for using the Elevator Control System!\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Please enter 0-5.\n";
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}