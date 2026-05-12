#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>
#include "Request.h"

using namespace std;

struct Trip {
    int pickupFloor;
    int destinationFloor;
};

//Declaration of the elevator class which handles movement and request processing
class Elevator {
private:
    int id; // Unique id for all the elevators
    int currentFloor; // The elevators current position
    bool movingUp; // A bool which specifies if the elevator is moving up or down (1/true=up, 0/false=down)
    bool isBusy; //Bool specifying the status of the elevator (true/1 = moving/has requests, false/0 = idle)
    vector<Request> assignedRequests; // Vector storing the user requests that need to be carried out
    vector<Trip> tripHistory;//Will be used to display the elevators trip history

public:
    Elevator(int id, int startFloor); // Constructor for the elvator which takes the unique id and starting floor as input
    ~Elevator(); // Destructor for the elevator

    int getId() const; // Returns the elevator id
    int getCurrentFloor() const; // Returns the elevator's current floor
    bool isMovingUp() const; // Returns the state of the elevator's movement
    bool busy() const; // Returns if the elevator is idle or busy

    void addRequest(const Request& req); // Adding of requests to the queue
    void processNextRequest(); // Proccesses the next request
    int calculateDistance(int floor) const; // The command that will calculate how far the elevator is from the request, in order to see which elevator should carry it out
    void displayStatus() const; // Prints the status of the elevator
    void displayTripHistory() const; //Trip history of the elevators
};

#endif