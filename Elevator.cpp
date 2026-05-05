#include "Elevator.h"
#include <iostream>
#include <algorithm>

using namespace std;

Elevator::Elevator(int id) : id(id), currentFloor(0), movingUp(true), isIdle(true) {}

Elevator::~Elevator() {
    cout << "Elevator " << id << " destroyed.\n";
}

int Elevator::getId() const { return id; }
int Elevator::getCurrentFloor() const { return currentFloor; }
void Elevator::setCurrentFloor(int floor) { currentFloor = floor; }
bool Elevator::isMovingUp() const { return movingUp; }
bool Elevator::idle() const { return isIdle; }

void Elevator::addRequest(const Request& req) {
    assignedRequests.push_back(req);
    isIdle = false;
}

void Elevator::processNextRequest() {
    if (assignedRequests.empty()) {
        isIdle = true;
        return;
    }

    Request next = assignedRequests.front();
    assignedRequests.erase(assignedRequests.begin());

    // Go to pickup floor
    cout << "Elevator moving from floor " << currentFloor 
         << " to floor " << next.getPickupFloor() << "\n";
    while (currentFloor != next.getPickupFloor()) {
        if (currentFloor < next.getPickupFloor()) {
            currentFloor++;
            movingUp = true;
        } else {
            currentFloor--;
            movingUp = false;
        }
        cout << "  -> Floor " << currentFloor << "\n";
    }
    
    if (next.getPickupFloor() == next.getDestinationFloor()) {
        cout << "Elevator arrived at floor " << currentFloor << " (waiting for destination)\n";
    } else {
        cout << "Elevator arrived at floor " << currentFloor << "\n";
        
        // Continue to destination
        cout << "Elevator moving from floor " << currentFloor 
             << " to floor " << next.getDestinationFloor() << "\n";
        while (currentFloor != next.getDestinationFloor()) {
            if (currentFloor < next.getDestinationFloor()) {
                currentFloor++;
                movingUp = true;
            } else {
                currentFloor--;
                movingUp = false;
            }
            cout << "  -> Floor " << currentFloor << "\n";
        }
        cout << "Elevator arrived at destination floor " << currentFloor << "\n";
    }
}

void Elevator::displayStatus() const {
    cout << "Elevator " << id << " | Current Floor: " << currentFloor 
         << " | Direction: " << (movingUp ? "UP" : "DOWN") 
         << " | Status: " << (isIdle ? "IDLE" : "BUSY") << "\n";
}