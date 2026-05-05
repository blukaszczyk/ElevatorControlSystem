#include "Building.h"
#include <iostream>
#include <algorithm>

Building::Building(int numElevators) {
    for (int i = 0; i < numElevators; ++i) {
        elevators.push_back(Elevator(i + 1));
    }
    std::cout << "Building created with " << numElevators << " elevators\n";
}

Building::~Building() {
    std::cout << "Building destroyed.\n";
}

void Building::addRequest(const Request& req) {
    pendingRequests.push_back(req);
    std::cout << "New request: Floor " << req.getPickupFloor() 
              << " -> Floor " << req.getDestinationFloor() << "\n";
}

void Building::assignRequests() {
    for (auto& req : pendingRequests) {
        // Find idle elevator
        auto it = std::find_if(elevators.begin(), elevators.end(), 
                               [](const Elevator& e) { return e.idle(); });
        if (it != elevators.end()) {
            std::cout << "Assigning to idle Elevator " << it->getId() << "\n";
            it->addRequest(req);
        } else {
            // Assign to elevator with fewest requests
            auto best = std::min_element(elevators.begin(), elevators.end(),
                         [](const Elevator& a, const Elevator& b) {
                             return a.idle() < b.idle();
                         });
            std::cout << "All elevators busy, assigning to Elevator " << best->getId() << "\n";
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
    std::cout << "\n=== Building Status ===\n";
    for (const auto& e : elevators) {
        e.displayStatus();
    }
    std::cout << "======================\n\n";
}