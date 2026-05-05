#include "Elevator.h"
#include <iostream>
#include <algorithm>

Elevator::Elevator(int id) : id(id), currentFloor(0), movingUp(true), isIdle(true) {}

Elevator::~Elevator() {
    std::cout << "Elevator " << id << " destroyed.\n";
}

int Elevator::getId() const { return id; }
int Elevator::getCurrentFloor() const { return currentFloor; }
bool Elevator::isMovingUp() const { return movingUp; }
bool Elevator::idle() const { return isIdle; }

void Elevator::addRequest(const Request& req) {
    assignedRequests.push_back(req);
    isIdle = false;
    std::cout << "Elevator " << id << " received request to floor " << req.getDestinationFloor() << "\n";
}

void Elevator::processNextRequest() {
    if (assignedRequests.empty()) {
        isIdle = true;
        return;
    }

    Request next = assignedRequests.front();
    assignedRequests.erase(assignedRequests.begin());

    // Go to pickup floor
    std::cout << "Elevator " << id << " moving from floor " << currentFloor 
              << " to pickup at floor " << next.getPickupFloor() << "\n";
    while (currentFloor != next.getPickupFloor()) {
        if (currentFloor < next.getPickupFloor()) {
            currentFloor++;
            movingUp = true;
        } else {
            currentFloor--;
            movingUp = false;
        }
        std::cout << "  -> Floor " << currentFloor << "\n";
    }
    std::cout << "Elevator " << id << " picked up at floor " << currentFloor << "\n";

    // Go to destination floor
    std::cout << "Elevator " << id << " moving from floor " << currentFloor 
              << " to destination floor " << next.getDestinationFloor() << "\n";
    while (currentFloor != next.getDestinationFloor()) {
        if (currentFloor < next.getDestinationFloor()) {
            currentFloor++;
            movingUp = true;
        } else {
            currentFloor--;
            movingUp = false;
        }
        std::cout << "  -> Floor " << currentFloor << "\n";
    }
    std::cout << "Elevator " << id << " dropped off at floor " << currentFloor << "\n";
}

void Elevator::moveOneStep() {
    // This method is kept for compatibility but not used in current implementation
    // Could be used for continuous movement simulation
}

void Elevator::displayStatus() const {
    std::cout << "Elevator " << id << " | Floor: " << currentFloor 
              << " | Direction: " << (movingUp ? "UP" : "DOWN") 
              << " | Pending requests: " << assignedRequests.size()
              << " | Status: " << (isIdle ? "IDLE" : "BUSY") << "\n";
}