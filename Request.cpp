#include "Request.h"

Request::Request(int pickup, int destination) 
    : pickupFloor(pickup), destinationFloor(destination) {}

Request::~Request() {}

int Request::getPickupFloor() const { return pickupFloor; }
int Request::getDestinationFloor() const { return destinationFloor; }