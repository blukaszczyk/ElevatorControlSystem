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
    bool isIdle;
    vector<Request> assignedRequests;

public:
    Elevator(int id);
    ~Elevator();

    int getId() const;
    int getCurrentFloor() const;
    void setCurrentFloor(int floor);
    bool isMovingUp() const;
    bool idle() const;

    void addRequest(const Request& req);
    void processNextRequest();
    void displayStatus() const;
};

#endif