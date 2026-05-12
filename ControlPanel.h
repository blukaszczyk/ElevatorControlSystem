#ifndef CONTROL_PANEL_H 
#define CONTROL_PANEL_H 
 
#include <vector> 
#include "Request.h" 
 
using namespace std; 
 
// Declaration of the control panel class which manages tasks before simulation
class ControlPanel { 
private: 
    vector<Request> taskList;  // List of tasks added by the user
 
public: 
    ControlPanel(); // Constructor for the control panel
    ~ControlPanel(); // Destructor
 
    void addTask(int pickup, int destination); //Adds task to list
    void displayAllTasks() const; //lists all tasks
    int getTaskCount() const; //number of tasks as return
    Request getTask(int index) const; // gives task at specified index
    vector<Request> getAllTasks() const; //gives all tasks
    void clearTasks(); //removes all the tasks
}; 
 
#endif 
