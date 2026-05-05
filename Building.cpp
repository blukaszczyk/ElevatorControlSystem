#include "Building.h"
#include <iostream>
#include <algorithm>

using namespace std;

Building::Building(int numElevators) {
    for (int i = 0; i < numElevators; ++i) {
        elevators.push_back(Elevator(i + 1));
    }
    cout << "Building created with " << numElevators << " elevators\n";
}

Building::~Building() {
    cout << "Building destroyed.\n";
}

void Building::addRequest(const Request& req) {
    pendingRequests.push_back(req);
    cout << "New request: Floor " << req.getPickupFloor() 
         << " -> Floor " << req.getDestinationFloor() << "\n";
}

void Building::assignRequests() {
    for (auto& req : pendingRequests) {
        // Find idle elevator
        auto it = find_if(elevators.begin(), elevators.end(), 
                               [](const Elevator& e) { return e.idle(); });
        if (it != elevators.end()) {
            cout << "Assigning to idle Elevator " << it->getId() << "\n";
            it->addRequest(req);
        } else {
            // Assign to elevator with fewest requests
            auto best = min_element(elevators.begin(), elevators.end(),
                         [](const Elevator& a, const Elevator& b) {
                             return a.idle() < b.idle();
                         });
            cout << "All elevators busy, assigning to Elevator " << best->getId() << "\n";
            best->addRequest(req);
        }
    }
    pendingRequests.clear();
}

void Building::simulateStep() {
    assignRequests();
    for (auto& e : elevators) {
        if (!e.idle()) {
            e.processNextRequest();
        }
    }
}

void Building::displayAllElevators() const {
    cout << "\n=== Building Status ===\n";
    for (const auto& e : elevators) {
        e.displayStatus();
    }
    cout << "======================\n\n";
}