#include <iostream>
#include "Building.h"
#include "Request.h"

int main() {
    std::cout << "=== ELEVATOR CONTROL SYSTEM ===\n\n";
    
    // Create building with 2 elevators
    Building building(2);
    
    // Display initial state
    building.displayAllElevators();
    
    // Add some requests
    std::cout << "--- Adding Requests ---\n";
    building.addRequest(Request(0, 5));
    building.addRequest(Request(3, 8));
    building.addRequest(Request(6, 2));
    
    // Simulate
    std::cout << "\n--- Simulating ---\n";
    building.simulateStep();
    
    // Final state
    building.displayAllElevators();
    
    // Add more requests to test
    std::cout << "--- Adding More Requests ---\n";
    building.addRequest(Request(1, 4));
    building.addRequest(Request(7, 3));
    
    std::cout << "\n--- Simulating Again ---\n";
    building.simulateStep();
    
    building.displayAllElevators();
    
    std::cout << "Simulation complete!\n";
    return 0;
}