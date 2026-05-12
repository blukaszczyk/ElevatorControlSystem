#include <iostream>
#include <limits>
#include <string>
#include "Building.h"
#include "ControlPanel.h"
#include <algorithm> //STL
using namespace std;

// Displays the main menu options
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

// Clears invalid input from the buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Gets a valid input from user 
int getValidIntInput() {
    int input;
    string line;
    
    while (true) {
        getline(cin, line);  // Read entire line 
        
        // Checks if the entire line is a valid integer
        bool isValid = true;
        if (line.empty()) {
            isValid = false;
        } else {
            for (size_t i = 0; i < line.length(); i++) {
                // dissallows negative sign
                if (i == 0 && !(line[i] == '-')) {
                    continue;
                }
                if (!isdigit(line[i])) {
                    isValid = false;
                    break;
                }
            }
        }
        
        if (isValid) {
            input = stoi(line);  // Convert string to int
            return input;
        } else {
            cout << "Invalid input! Please enter a valid number: ";
        }
    }
}

int main() {
    cout << "========================================\n";
    cout << "   WELCOME TO THE ELEVATOR CONTROL SYSTEM   \n";
    cout << "========================================\n";
    
    ControlPanel panel; //Creates the control panel
    Building building(2);  // States the amount of elevators inside the building
    
    int choice;
    do {
        displayMenu();
        choice = getValidIntInput();
        
        switch(choice) {
            case 1: { //adding of task
                int pickup, destination;
                cout << "Pickup floor (0-10): ";
                pickup = getValidIntInput();
                cout << "Destination floor (0-10): ";
                destination = getValidIntInput();
                panel.addTask(pickup, destination);
                break;
            }
            
            case 2: { //show all tasks
                panel.displayAllTasks();
                building.displayAllElevators();
                break;
            }
            
            case 3: { //run sim
                if (panel.getTaskCount() == 0) {
                    cout << "\n*** NO TASKS TO RUN! Add tasks first. ***\n";
                } else {
                    cout << "\n=== RUNNING SIMULATION WITH " << panel.getTaskCount() << " TASKS ===\n";
                    
                    // Add all tasks to building
                    vector<Request> tasks = panel.getAllTasks();
                    
                    //STL algorithm - This counts the requests which want to go to a floor higher than the one they start on
                    int goingUp=count_if(tasks.begin(),tasks.end(),
                    [](const Request& req) {
                    	return req.getDestinationFloor()>req.getPickupFloor();	
					});
					cout<<"======================"<<endl;
					cout<<"COUNT OF UP VS DOWN"<<endl;
					cout<<"Going up = "<<goingUp<<" and going down = "<<(tasks.size()-goingUp) <<endl;
					cout<<"======================"<<endl;
                    
                    for (const auto& task : tasks) {
                        building.addRequest(task);
                    }
                    
                    // Run simulation
                    building.simulateAll();
                    
                    // Show final elevator positions
                    building.displayAllElevators();
                    
                    //Shows the trips of the elevators
                    building.displayAllTrips();
                    
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
                cout << "\nSee you later \n"<<endl;
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