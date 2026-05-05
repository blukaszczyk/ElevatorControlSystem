#include "Building.h"
#include <iostream>

using namespace std;

Building::Building() : elevator(1), currentUserFloor(0) {
    cout << "   ELEVATOR CONTROL SYSTEM READY       \n";
    cout << "You are on floor " << currentUserFloor << "\n";
    cout << "Elevator is on floor " << elevator.getCurrentFloor() << "\n";
}

Building::~Building() {
    cout << "Building destroyed.\n";
}

void Building::callElevator() {
    cout << "\n ELEVATOR COMING TO FLOOR " << currentUserFloor << " \n";
    
    if (elevator.getCurrentFloor() == currentUserFloor) {
        cout << "Elevator is already here!\n";
        return;
    }
    
    elevator.addRequest(Request(currentUserFloor, currentUserFloor));
    elevator.processNextRequest();
    cout << "\n ELEVATOR IS HERE! \n";
}

void Building::goToFloor(int destination) {
    cout << "\n GOING TO FLOOR " << destination << " \n";
    
    elevator.addRequest(Request(currentUserFloor, destination));
    elevator.processNextRequest();
    currentUserFloor = destination;
    cout << "\n ARRIVED AT FLOOR " << currentUserFloor << " \n";
}

void Building::displayStatus() const {
    cout << "You are on floor: " << currentUserFloor << "\n";
    cout << "Elevator on floor: " << elevator.getCurrentFloor() << "\n";
}

Elevator& Building::getElevator() {
    return elevator;
}