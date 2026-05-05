#include <iostream>
#include <limits>
#include "Building.h"

using namespace std;

void displayMenu(bool elevatorCalled) {
    cout << "         ELEVATOR CONTROL SYSTEM        \n";
    cout << "1. Call elevator to my floor\n";
    if (elevatorCalled) {
        cout << "2. Go to destination\n";
    }
    cout << "3. Show status\n";
    cout << "0. Exit\n";
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
    Building building;
    bool elevatorCalled = false;
    
    int choice;
    do {
        displayMenu(elevatorCalled);
        choice = getValidIntInput();
        
        if (!elevatorCalled && choice == 2) {
            cout << "\n Unavailable \n";
            continue;
        }
        
        switch(choice) {
            case 1: {
                building.callElevator();
                elevatorCalled = true;
                break;
            }
            
            case 2: {
                int destination;
                cout << "Which floor? (0-10): ";
                destination = getValidIntInput();
                
                if (destination < 0 || destination > 10) {
                    cout << "Invalid floor! Use 0-10.\n";
                } else {
                    building.goToFloor(destination);
                    elevatorCalled = false;
                }
                break;
            }
            
            case 3: {
                building.displayStatus();
                break;
            }
            
            case 0: {
                break;
            }
            
            default: {
                cout << "Invalid choice!\n";
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}