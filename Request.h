#ifndef REQUEST_H
#define REQUEST_H
// Declaration of the request class which stores pickup and destination floors

class Request {
private:
    int pickupFloor; // The floor from which the elevator will pick up the passenger
    int destinationFloor; // Floor where the passenger will exit

public:
    Request(int pickup, int destination); // Constructor for the request
    ~Request(); // Destructor

    int getPickupFloor() const; // Returns the pickup floor
    int getDestinationFloor() const; // Returns the destination floor
};

#endif