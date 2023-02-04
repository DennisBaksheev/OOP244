#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"

using namespace std;

namespace sdds {


    class Parking {
        char* park;
        Menu Menu_element;
        Menu Vehicle_element;
        const int maxSpots = 100;
        int numSpots;
        Vehicle* spots[100];
        int parkedVehicles;



        void setEmpty();
        bool isEmpty(); // check if it is empty or not.
        void Parkingstatus(); //  function does not receive or return anything and only prints a message
        void VehicleFunction(); // the function for the Vehicle object to display, get user input and do accordingly
        void ReturningVehicle(); // the function for " Returning the Vehicle "
        void FindingVehicle(); //
        void PrintParked(); // the function prints the " parked vehicles"
        bool closeParking(); // the function to close the parking//void setIndent();
        void parkVehicle();
        bool exitApp(); // the function to exit the app
        bool loadDataFile(); // the function checks if the park value is loaded or not
        void saveDataFile(); // the function check if the function is empty or not
        void vehicleList() const; // the function prints the " parked vehicles"

    public:
        Parking(const char* title, int noOfSpots); // one argument constructor.

        int run();
        ~Parking(); // default destuctor

    };

}

#endif // !SDDS_PARKING_H


