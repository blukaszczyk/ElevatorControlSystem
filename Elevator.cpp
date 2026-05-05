#include "Elevator.h"
#include <iostream>
#include <cmath>

using namespace std;

Elevator::Elevator(int id, int startFloor) : id(id), currentFloor(startFloor), movingUp(true), isBusy(false) {
    cout << "Elevator " << id << " initialized on floor " << currentFloor << "\n";
}

Elevator::~Elevator() {
    cout << "Elevator " << id << " destroyed.\n";
}

int Elevator::getId() const { return id; }
int Elevator::getCurrentFloor() const { return currentFloor; }
bool Elevator::isMovingUp() const { return movingUp; }
bool Elevator::busy() const { return isBusy; }

void Elevator::addRequest(const Request& req) {
    assignedRequests.push_back(req);
    isBusy = true;
}

int Elevator::calculateDistance(int floor) const {
    return abs(currentFloor - floor);
}

void Elevator::processNextRequest() {
    if (assignedRequests.empty()) {
        isBusy = false;
        return;
    }

    Request next = assignedRequests.front();
    assignedRequests.erase(assignedRequests.begin());

    // Go to pickup floor
    cout << "Elevator " << id << " moving from floor " << currentFloor 
         << " to pickup at floor " << next.getPickupFloor() << "\n";
    
    while (currentFloor != next.getPickupFloor()) {
        if (currentFloor < next.getPickupFloor()) {
            currentFloor++;
            movingUp = true;
        } else {
            currentFloor--;
            movingUp = false;
        }
        cout << "  Elevator " << id << " -> Floor " << currentFloor << "\n";
    }
    cout << "Elevator " << id << " PICKED UP at floor " << currentFloor << "\n";

    // Go to destination floor
    cout << "Elevator " << id << " moving from floor " << currentFloor 
         << " to destination floor " << next.getDestinationFloor() << "\n";
    
    while (currentFloor != next.getDestinationFloor()) {
        if (currentFloor < next.getDestinationFloor()) {
            currentFloor++;
            movingUp = true;
        } else {
            currentFloor--;
            movingUp = false;
        }
        cout << "  Elevator " << id << " -> Floor " << currentFloor << "\n";
    }
    cout << "Elevator " << id << " DROPPED OFF at floor " << currentFloor << "\n\n";
}

void Elevator::displayStatus() const {
    cout << "Elevator " << id << " | Floor: " << currentFloor 
         << " | Direction: " << (movingUp ? "UP" : "DOWN") 
         << " | Status: " << (isBusy ? "BUSY" : "IDLE")
         << " | Queue size: " << assignedRequests.size() << "\n";
}