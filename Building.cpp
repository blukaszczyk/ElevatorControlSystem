#include "Building.h"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

Building::Building(int numElevators) {
    // Start elevators on RANDOM floors (0-10)
    srand(time(nullptr));
    
    for (int i = 0; i < numElevators; i++) {
        int randomFloor = rand() % 11;  // 0 to 10
        elevators.push_back(Elevator(i + 1, randomFloor));
    }
    
    cout << "\n========================================\n";
    cout << "BUILDING CREATED WITH " << numElevators << " ELEVATORS\n";
    cout << "========================================\n";
}

Building::~Building() {
    cout << "Building destroyed.\n";
}

void Building::addRequest(const Request& req) {
    pendingRequests.push_back(req);
    cout << "REQUEST ADDED: Floor " << req.getPickupFloor() 
         << " -> Floor " << req.getDestinationFloor() << "\n";
}

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
    
    pendingRequests.clear();
}

void Building::simulateAll() {
    cout << "\n=== STARTING SIMULATION ===\n";
    
    dispatchRequests();
    
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

void Building::displayAllElevators() const {
    cout << "\n--- ELEVATOR STATUS ---\n";
    for (const auto& e : elevators) {
        e.displayStatus();
    }
    cout << "------------------------\n";
}