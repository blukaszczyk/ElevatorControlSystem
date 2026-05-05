#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Elevator.h"
#include "Request.h"

using namespace std;

class Building {
private:
    vector<Elevator> elevators;
    vector<Request> pendingRequests;

public:
    Building(int numElevators);
    ~Building();

    void addRequest(const Request& req);
    void dispatchRequests();     
    void simulateAll();          
    void displayAllElevators() const;
    
    int getElevatorCount() const { return elevators.size(); }
};

#endif