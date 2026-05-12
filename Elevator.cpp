#include "Elevator.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor - initializes elevator
Elevator::Elevator(int id, int startFloor) : id(id), currentFloor(startFloor), movingUp(true), isBusy(false) {
    cout << "Elevator " << id << " initialized on floor " << currentFloor << "\n";
}

Elevator::~Elevator() {
}

int Elevator::getId() const 
{
	return id;
} // Returns the elevator id

int Elevator::getCurrentFloor() const {
	return currentFloor;
} // Returns the elevator's current floor

bool Elevator::isMovingUp() const {
	return movingUp;
} // Returns the state of the elevator's movement

bool Elevator::busy() const 
{
	return isBusy;
} //Bool specifying the status of the elevator (true/1 = moving/has requests, false/0 = idle)

// Adds request to the elevator and marks it as busy
void Elevator::addRequest(const Request& req) {
    assignedRequests.push_back(req);
    isBusy = true;
}

//Calculates the distance from the elevator to the target floor
int Elevator::calculateDistance(int floor) const {
    return abs(currentFloor - floor);
}

// Process the next request inside the queue
void Elevator::processNextRequest() {
	//If no request, elevator becomes idle
    if (assignedRequests.empty()) {
        isBusy = false;
        return;
    }
	// gets first request and removes it from the queue
    Request next = assignedRequests.front();
    assignedRequests.erase(assignedRequests.begin());

    int pickup = next.getPickupFloor();
    int destination = next.getDestinationFloor();
    
    // Record the trip (pickup -> destination)
  	tripHistory.push_back({pickup, destination});

    // Go to pickup floor
    cout << "Elevator " << id << " moving from floor " << currentFloor 
         << " to pickup at floor " << pickup << "\n";
    
    while (currentFloor != pickup) {
        if (currentFloor < pickup) {
            currentFloor++; //moves up
            movingUp = true;
        } else {
            currentFloor--;//moves down
            movingUp = false;
        }
        cout << "  Elevator " << id << " -> Floor " << currentFloor << "\n";
    }
    cout << "Elevator " << id << " PICKED UP at floor " << currentFloor << "\n";

    // Go to destination floor
    cout << "Elevator " << id << " moving from floor " << currentFloor 
         << " to destination floor " << destination << "\n";
    
    while (currentFloor != destination) {
        if (currentFloor < destination) {
            currentFloor++;//up
            movingUp = true;
        } else {
            currentFloor--;//down
            movingUp = false;
        }
        cout << "  Elevator " << id << " -> Floor " << currentFloor << "\n";
    }
    cout << "Elevator " << id << " DROPPED OFF at floor " << currentFloor << "\n\n";
}

//prints the current status of the elevator
void Elevator::displayStatus() const {
    cout << "Elevator " << id << " | Floor: " << currentFloor 
         << " | Direction: " << (movingUp ? "UP" : "DOWN") 
         << " | Status: " << (isBusy ? "BUSY" : "IDLE")
         << " | Queue size: " << assignedRequests.size() << "\n";
}

//prints out the entire trip history of the elevator
void Elevator::displayTripHistory() const {
    if (tripHistory.empty()) {
        cout << "Elevator " << id << " had no trips.\n";
        return;
    }
    
    cout << "Elevator " << id << " trips: ";
    for (size_t i = 0; i < tripHistory.size(); i++) {
        cout << tripHistory[i].pickupFloor << " -> " << tripHistory[i].destinationFloor;
        if (i != tripHistory.size() - 1) {
            cout << ", ";
        }
    }
    cout << "\n";
}