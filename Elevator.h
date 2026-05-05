#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "Request.h"

class Elevator {
private:
    int id;
    int currentFloor;
    bool movingUp;
    bool isIdle;
    std::vector<Request> assignedRequests;

public:
    Elevator(int id);
    ~Elevator();

    int getId() const;
    int getCurrentFloor() const;
    bool isMovingUp() const;
    bool idle() const;

    void addRequest(const Request& req);
    void processNextRequest();
    void moveOneStep();
    void displayStatus() const;
};

#endif