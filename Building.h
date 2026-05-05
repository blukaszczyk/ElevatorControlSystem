#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "Elevator.h"

using namespace std;

class Building {
private:
    Elevator elevator;
    int currentUserFloor;

public:
    Building();
    ~Building();

    void callElevator();
    void goToFloor(int destination);
    void displayStatus() const;
    Elevator& getElevator();
};

#endif