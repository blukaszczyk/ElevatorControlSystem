#include "Building.h"
#include <iostream>
#include <algorithm>
#include <climits>
#include <ctime>
using namespace std;

//Creates "numElevators" amount of elevators in the building on random floors 1-10
Building::Building(int numElevators) {
    // Start elevators on RANDOM floors (0-10)
    srand(time(nullptr));//random num gen
    
    for (int i = 0; i < numElevators; i++) {
        int randomFloor = rand() % 11;  // 0 to 10
        elevators.push_back(Elevator(i + 1, randomFloor));
    }
    
    cout << "\n========================================\n";
    cout << "BUILDING CREATED WITH " << numElevators << " ELEVATORS\n";
    cout << "========================================\n";
}

//cleanup message
Building::~Building() {
}

// Adds a request to the pending list 
void Building::addRequest(const Request& req) {
    pendingRequests.push_back(req);
    cout << "REQUEST ADDED: Floor " << req.getPickupFloor() 
         << " -> Floor " << req.getDestinationFloor() << "\n";
}

// Assigns pending requests to the closest elevator
void Building::dispatchRequests() {
    cout << "\n--- DISPATCHING " << pendingRequests.size() << " REQUESTS ---\n";
    
    for (auto& req : pendingRequests) {
        int bestElevator = -1;
        int shortestDistance = INT_MAX;
        
        // Find the closest IDLE elevator
        for (size_t i = 0; i < elevators.size(); i++) {
            if (!elevators[i].busy()) {
                int distance = elevators[i].calculateDistance(req.getPickupFloor());
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    bestElevator = i;
                }
            }
        }
        
        // If all elevators busy, find closest regardless of busy status
        if (bestElevator == -1) {
            cout << "All elevators busy! Finding closest anyway...\n";
            for (size_t i = 0; i < elevators.size(); i++) {
                int distance = elevators[i].calculateDistance(req.getPickupFloor());
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    bestElevator = i;
                }
            }
        }
        
        cout << "Assigning request (pickup floor " << req.getPickupFloor() 
             << ") to Elevator " << (bestElevator + 1) 
             << " (distance: " << shortestDistance << " floors)\n";
        
        elevators[bestElevator].addRequest(req);
    }
    
    pendingRequests.clear(); //all requests are assigned
}

//Runs the full simulation
void Building::simulateAll() {
    cout << "\n=== STARTING SIMULATION ===\n";
    
    dispatchRequests();
    
    //While any elevators are non-idle the simulation keeps running
    bool anyBusy = true;
    while (anyBusy) {
        anyBusy = false;
        for (auto& e : elevators) {
            if (e.busy()) {
                e.processNextRequest();
                anyBusy = true;
            }
        }
    }
    
    cout << "=== SIMULATION COMPLETE ===\n";
}
// Prints status of all elevators in the building
void Building::displayAllElevators() const {
    cout << "\n--- ELEVATOR STATUS ---\n";
    for (const auto& e : elevators) {
        e.displayStatus();
    }
    cout << "------------------------\n";
}

void Building::displayAllTrips() const {
    cout << "\n=== TRIP HISTORIES ===\n";
    for (const auto& e : elevators) {
        e.displayTripHistory();
    }
    cout << "=====================\n";
}