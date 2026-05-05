#include "ControlPanel.h" 
#include <iostream> 
 
using namespace std; 
 
ControlPanel::ControlPanel() { 
    cout << "Control Panel ready. Add tasks before running simulation.\n"; 
} 
 
ControlPanel::~ControlPanel() { 
    cout << "Control Panel destroyed.\n"; 
} 
 
void ControlPanel::addTask(int pickup, int destination) { 
    if (pickup < 0 || pickup > 10 || destination < 0 || destination > 10) { 
        cout << "INVALID FLOOR! Use 0-10. Task not added.\n"; 
        return; 
    } 
    taskList.push_back(Request(pickup, destination)); 
    cout << "TASK " << taskList.size() << " added: Floor " << pickup 
         << " -> Floor " << destination << "\n"; 
} 
 
void ControlPanel::displayAllTasks() const { 
    cout << "\n=== CURRENT TASKS ===\n"; 
    if (taskList.empty()) { 
        cout << "No tasks added yet.\n"; 
        return; 
    } 
    for (size_t i = 0; i < taskList.size(); i++) { 
        cout << "Task " << (i+1) << ": Floor " << taskList[i].getPickupFloor() 
             << " -> Floor " << taskList[i].getDestinationFloor() << "\n"; 
    } 
    cout << "=====================\n"; 
} 
 
int ControlPanel::getTaskCount() const { 
    return taskList.size(); 
} 
 
Request ControlPanel::getTask(int index) const { 
    return taskList[index]; 
} 
 
vector<Request> ControlPanel::getAllTasks() const { 
    return taskList; 
} 
 
void ControlPanel::clearTasks() { 
    taskList.clear(); 
    cout << "All tasks cleared.\n"; 
} 
