#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Elevator.h"

class Building {
private:
    std::vector<Elevator> elevators;
    std::vector<Request> pendingRequests;

public:
    Building(int numElevators);
    ~Building();

    void addRequest(const Request& req);
    void assignRequests();
    void simulateStep();
    void displayAllElevators() const;
};

#endif