#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "Request.h"

using namespace std;

class Elevator {
private:
    int id;
    int currentFloor;
    bool movingUp;
    bool isBusy;
    vector<Request> assignedRequests;

public:
    Elevator(int id, int startFloor);
    ~Elevator();

    int getId() const;
    int getCurrentFloor() const;
    bool isMovingUp() const;
    bool busy() const;

    void addRequest(const Request& req);
    void processNextRequest();
    int calculateDistance(int floor) const;
    void displayStatus() const;
};

#endif