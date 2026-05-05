#include <iostream>
#include <limits>
#include "Building.h"
#include "ControlPanel.h"

using namespace std;

void displayMenu() {
    cout << "\n========================================\n";
    cout << "     ELEVATOR CONTROL SYSTEM           \n";
    cout << "========================================\n";
    cout << "1. Add task (pickup -> destination)\n";
    cout << "2. Show all pending tasks\n";
    cout << "3. RUN SIMULATION (elevators start doing tasks)\n";
    cout << "4. Clear all tasks\n";
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
    cout << "========================================\n";
    cout << "   WELCOME TO ELEVATOR CONTROL SYSTEM   \n";
    cout << "========================================\n";
    
    ControlPanel panel;
    Building building(2);  // 2 elevators starting on random floors
    
    int choice;
    do {
        displayMenu();
        choice = getValidIntInput();
        
        switch(choice) {
            case 1: {
                int pickup, destination;
                cout << "Pickup floor (0-10): ";
                pickup = getValidIntInput();
                cout << "Destination floor (0-10): ";
                destination = getValidIntInput();
                panel.addTask(pickup, destination);
                break;
            }
            
            case 2: {
                panel.displayAllTasks();
                building.displayAllElevators();
                break;
            }
            
            case 3: {
                if (panel.getTaskCount() == 0) {
                    cout << "\n*** NO TASKS TO RUN! Add tasks first. ***\n";
                } else {
                    cout << "\n=== RUNNING SIMULATION WITH " << panel.getTaskCount() << " TASKS ===\n";
                    
                    // Add all tasks to building
                    vector<Request> tasks = panel.getAllTasks();
                    for (const auto& task : tasks) {
                        building.addRequest(task);
                    }
                    
                    // Run simulation
                    building.simulateAll();
                    
                    // Show final elevator positions
                    building.displayAllElevators();
                    
                    // Clear tasks from panel after simulation
                    panel.clearTasks();
                }
                break;
            }
            
            case 4: {
                panel.clearTasks();
                break;
            }
            
            case 0: {
                cout << "\nGoodbye!\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Enter 0-4.\n";
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}