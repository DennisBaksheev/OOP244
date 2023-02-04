#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {


    Parking::Parking(const char* title) {

        if (title == nullptr || strlen(title) == 0) {
            park = nullptr;
        }
        else {
            park = new char[strlen(title) + 1];
            strcpy(park, title);
        }

        if (loadDataFile()) {

            Menu_element.setTitle("Parking Menu, select an action:");
            Menu_element << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
            Vehicle_element.setTitle("Select type of the vehicle:");
            Vehicle_element.setIndent(1);
            Vehicle_element << "Car" << "Motorcycle" << "Cancel";
        }
        else {
            cout << "Error in data file" << endl;
        }
    }


    bool Parking::isEmpty() {
        return Menu_element.isEmpty();
    }


    void Parking::Parkingstatus() {
        cout << "****** Valet Parking ******" << endl;
    }


    void Parking::VehicleFunction() {
        int choice;
        choice = Vehicle_element.run();
        switch (choice) {
            case 1:
                cout << fixed << setprecision(0) << setw(32) << left << "---------------------------------" << endl;
                cout << "Parking Car" << endl;
                cout.width(32); cout << left << "---------------------------------" << endl;
                cout << endl;
                break;
            case 2:
                cout << "---------------------------------" << endl;
                cout << "Parking Motorcycle" << endl;
                cout << "---------------------------------" << endl;
                cout << endl;
                break;
            case 3:
                cout << "---------------------------------" << endl;
                cout << "Cancelled parking" << endl;
                cout << "---------------------------------" << endl;
                cout << endl;
                break;
            default:
                cout << "Sorry no such";
        }
    }
    void Parking::FindingVehicle() {
        cout << "---------------------------------" << endl;
        cout << "Finding a Vehicle" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }

    void Parking::ReturningVehicle() {
        cout << "---------------------------------" << endl;
        cout << "Returning Vehicle" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }


    void Parking::PrintParked() {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }


    bool Parking::closeParking() {

        char letter[10];
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        cin >> letter;
        cin.ignore(2000, '\n');
        while (true) {
            if (!strcmp(letter, "y")) {
                cout << "Ending application!" << endl;
                return true;
            }
            else if (!strcmp(letter, "n")) {

                return false;
            }
            else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin >> letter;
                cin.ignore(2000, '\n');
            }
        }
        return false;
    }


    bool Parking::exitApp() {

        char letter[10];

        cout << "This will terminate the application and save the data!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        cin >> letter;
        cin.ignore(2000, '\n');
        while (true) {
            if (strcmp(letter, "y") == 0 || strcmp(letter, "Y") == 0 ){

                cout << "Exiting application!" << endl;
                cout << "---------------------------------" << endl;
                cout << "Saving data into " << park << endl;
                cout << "---------------------------------" << endl;
                return true;
            }
            else if (strcmp(letter, "n") == 0 || strcmp(letter, "N") == 0 ) {

                return false;
            }
            else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin >> letter;
                cin.ignore(2000, '\n');
            }
        }
        return false;
    }


    bool Parking::loadDataFile() {
        if (park != nullptr) {
            cout << "---------------------------------" << endl;
            cout << "loading data from ";
            cout << park << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
            return true;
        }
        else {
            return false;
        }
    }


    void Parking::saveDataFile() {
        if (!isEmpty()) {
            cout << "Saving data info ";
            cout << park << endl;
        }
    }


    int Parking::run() {

        if (!isEmpty()) {

            bool flag = true;
            int choice;
            while (flag) {
                Parkingstatus();
                choice = Menu_element.run();

                switch (choice) {
                    case 1:

                        this->VehicleFunction();
                        break;
                    case 2:
                        this->ReturningVehicle();
                        break;
                    case 3:

                        this->PrintParked();
                        break;

                    case 4:

                        this->FindingVehicle();
                        break;

                    case 5:

                        this->closeParking();
                        flag = false;
                        break;

                    case 6:

                        bool out;
                        out = this->exitApp();
                        flag = !out;
                        break;
                    default:
                        cout << "something good";
                }

            }
            return 1;
        }
        return 0;
    }


    Parking::~Parking() {
        delete[] park;
        park = nullptr;
    }
}