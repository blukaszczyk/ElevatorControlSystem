#include "Request.h"

using namespace std;

Request::Request(int pickup, int destination) 
    : pickupFloor(pickup), destinationFloor(destination) {}

Request::~Request() {}
//returns pickup floor
int Request::getPickupFloor() const 
{
	return pickupFloor; 
}
//Returns destination
int Request::getDestinationFloor() const {
	return destinationFloor;
}