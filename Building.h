#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Elevator.h"
#include "Request.h"

// Declaration of the building class which handles the elevators and the dispatching using the closest elevator.

using namespace std;

class Building {
private:
    vector<Elevator> elevators; // The elevators inside of the building
    vector<Request> pendingRequests; // Declaration of the assigments that are not yet processed

public:
    Building(int numElevators); // Creation of the specified amount of elevators inside the building
    ~Building(); // Destructor for the building class

    void addRequest(const Request& req); // Adding of requests to the current list
    void dispatchRequests(); // Assigns the requests to the nearest elevators
    void simulateAll(); // Runs the simulations
    void displayAllElevators() const; // Prints the status of all the elevators
    int getElevatorCount() const { return elevators.size(); } // Gives the amount of elevators
    void displayAllTrips() const; //Prints trip history
};

#endif