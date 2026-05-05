#ifndef CONTROL_PANEL_H 
#define CONTROL_PANEL_H 
 
#include <vector> 
#include "Request.h" 
 
using namespace std; 
 
class ControlPanel { 
private: 
    vector<Request> taskList; 
 
public: 
    ControlPanel(); 
    ~ControlPanel(); 
 
    void addTask(int pickup, int destination); 
    void displayAllTasks() const; 
    int getTaskCount() const; 
    Request getTask(int index) const; 
    vector<Request> getAllTasks() const; 
    void clearTasks(); 
}; 
 
#endif 
