#ifndef REQUEST_H
#define REQUEST_H

class Request {
private:
    int pickupFloor;
    int destinationFloor;

public:
    Request(int pickup, int destination);
    ~Request();

    int getPickupFloor() const;
    int getDestinationFloor() const;
};

#endif