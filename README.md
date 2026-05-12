# Elevator Control System
An elevator dispatching system built in C++ that simulates multiple elevators handling passenger requests.
The system assigns the closest available elevator to each request and processes tasks in sequence.


## Table of contents
* [Description](#description)
* [Current Features](#current-features)
* [How to Run](#how-to-run)
* [Example Output](#example-output)
* [Authors](#authors)


## Description
This project simulates an elevator control system for a building with 2 elevators. 
Elevators start on random floors (0-10). Users can add multiple pickup/destination tasks through a control panel,
and the system automatically assigns each task to the closest elevator. 
Once all tasks are added, the simulation runs and shows step-by-step elevator movement.

##Current Features
- 2 elevators
- Task queue
- Closest elevator task assigning
- Status display
- Direction tracking

## Planned Features

## How to run
```bash
g++ main.cpp Elevator.cpp Building.cpp Request.cpp ControlPanel.cpp -o elevator
elevator.exe

## Authors
- Bart³omiej £ukaszczyk
- £ukasz Nowak