#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Motorcycle.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

namespace sdds {


    Parking::Parking(const char *title, int noOfSpots) {

        this->setEmpty();


        if (noOfSpots >= 10 && noOfSpots <= maxSpots) {

            numSpots = noOfSpots;

        } else {

            numSpots = 0;

        }

        if (title == nullptr || strlen(title) == 0) {
            park = nullptr;
        } else {
            park = new char[strlen(title) + 1];
            strcpy(park, title);
        }

        if (loadDataFile()) {

            Menu_element.setTitle("Parking Menu, select an action:");
            Menu_element << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle"
                         << "Close Parking (End of day)" << "Exit Program";
            Vehicle_element.setTitle("Select type of the vehicle:");
            Vehicle_element.setIndent(1);
            Vehicle_element << "Car" << "Motorcycle" << "Cancel";
        } else {
            cout << "Error in data file" << endl;
        }
    }


    bool Parking::isEmpty() {
        if (park == nullptr && numSpots == 0 && parkedVehicles == 0) {
            return true;
        }


        return false;
    }


    void Parking::Parkingstatus() {
        cout << "****** Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout << numSpots - parkedVehicles;
        cout << "    *****" << endl; //How to left indent 4 spaces justified?
    }


    void Parking::VehicleFunction() {
        int choice;
        choice = Vehicle_element.run();
        Vehicle* myVehicle;
        string myModel;
        char mylicense[9];
        char myWash;
        switch (choice) {
            case 1:
                cout << endl;
                cout << "Car information entry" << endl;
                cout << "Enter License Plate Number: ";
                cin >> mylicense;
                cout << "Enter Make and Model: ";
                for(unsigned int i = 0; i < strlen(mylicense); i++) {
                    mylicense[i] = toupper(mylicense[i]);
                }
                cin >> myModel;
                cout << "Carwash while parked? (Y)es/(N)o: ";
                cin >> myWash;
                myVehicle = new Car(mylicense, myModel.c_str());
                if(myWash == 'y') {
                    ((Car *) myVehicle)->carwash = true;
                } else {
                    ((Car *) myVehicle)->carwash = false;
                }
                break;
            case 2:
                cout << endl;
                cout << "Motorcycle information entry" << endl;
                cout << "Enter License Plate Number: ";
                cin >> mylicense;
                for(unsigned int i = 0; i < strlen(mylicense); i++) {
                    mylicense[i] = toupper(mylicense[i]);
                }
                cout << "Enter Make and Model: ";
                cin.ignore();
                getline(cin, myModel);
                cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
                cin >> myWash;
                myVehicle = new Motorcycle(mylicense, myModel.c_str());
                while(true) {
                    if(myWash == 'y') {
                        ((Motorcycle *) myVehicle)->sidecar = true;
                        break;
                    }else if(myWash == 'n'){
                        ((Motorcycle *) myVehicle)->sidecar = false;
                        break;
                    } else{
                        cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                        cin >> myWash;

                    }
                }

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
        for(int i = 0; i < numSpots; i++) {
            if(spots[i] == nullptr) {
                spots[i] = myVehicle;
                cout << endl;
                cout << "Parking Ticket" << endl;
                myVehicle->setParkingSpot(i+1);
                myVehicle->setCsv(false);
                cout << *myVehicle << endl;
                cout << "Press <ENTER> to continue...." << endl;
                parkedVehicles++;
                return;
            }
        }
    }

    void Parking::FindingVehicle() {

        cout << "Vehicle Search" << endl;
        cout << "Enter License Plate Number: ";
        char var_id[9] = {'\0'};
        cin.getline(var_id, 9);
        cout << endl;
        while(strlen(var_id) < 1 || strlen(var_id) > 8) {
            cout << "Invalid Licence Plate, try again: " << endl;
            cin.getline(var_id, 9);
        }
        for(unsigned int i = 0; i < strlen(var_id); i++) {
            var_id[i] = toupper(var_id[i]);
        }
        for(int i = 0; i < numSpots; i++) {
            if(spots[i] != nullptr) {
                Vehicle* myVehicle = spots[i];
                if(*myVehicle == var_id) {
                   myVehicle->setCsv(false);
                    cout << "Vehicle found:" << endl;
                    cout << *myVehicle << endl;
                return;
                }
            }
        }
        cout << "License plate " << var_id << " Not found" << endl;
        cout << endl;
    }

    void Parking::ReturningVehicle() {
        cout << "Return Vehicle" << endl;

        char licensePlate[MAXLEN + 1] = { '\0' };

        bool invalid;

        cout << "Enter License Plate Number: ";

        do {

            invalid = false;

            cin >> licensePlate;

            cin.ignore();

            if (strlen(licensePlate) < 1 || strlen(licensePlate) > 8) {

                cout << "Invalid Licence Plate, try again: ";

                invalid = true;

            }

        } while (invalid);

        for(unsigned int i = 0; i < strlen(licensePlate); i++) {
           licensePlate[i] = toupper(licensePlate[i]);
        }



        bool flag = true;

        for (int i = 0; i < numSpots && flag; i++) {

            if (spots[i] != nullptr && *spots[i] == licensePlate) {

                cout << "\nReturning:" << endl;

                spots[i]->setCsv(false);

                cout << *spots[i];

                cout << endl;

                delete spots[i];

                spots[i] = nullptr;

                parkedVehicles--;

                flag = false;

            }

        }



        if (flag) {

            cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;

        }

    }


}


    void sdds::Parking::PrintParked() {
        cout << "---------------------------------" << endl;
        cout << "Listing Parked Vehicles" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }


    bool sdds::Parking::closeParking() {
        bool close = false;

        if (parkedVehicles == 0) {

            cout << "Closing Parking" << endl;

            close = true;

        }

        else {

            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;

            cout << "Are you sure? (Y)es/(N)o: ";
            char input[2] = {'\0'};
            cin.getline(input, 2);
            if (strcmp(input, "y") == 0) {

                cout << "Closing Parking" << endl;

                for (int i = 0; i < numSpots; i++) {

                    if (spots[i] != nullptr) {

                        cout << endl << "Towing request" << endl;

                        cout << "*********************" << endl;
                        spots[i]->setCsv(false);
                        cout << *spots[i];

                        delete spots[i];

                        spots[i] = nullptr;

                        parkedVehicles--;

                    }

                }

                saveDataFile();

                close = true;

            }

            else {

                cout << "Aborted!" << endl;

                close = false;

            }

        }



        return close;

    }

        /*char letter[10];
        cout << "This will close the parking; All the vehicles will be removed!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        cin >> letter;
        cin.ignore(2000, '\n');
        while (true) {
            if (!strcmp(letter, "y")) {
                cout << "Ending application!" << endl;
                return true;
            } else if (!strcmp(letter, "n")) {

                return false;
            } else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin >> letter;
                cin.ignore(2000, '\n');
            }
          return false;
        }*/






    bool sdds::Parking::exitApp() {

        char letter[10];

        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        cin >> letter;
        cin.ignore(2000, '\n');
        while (true) {
            if (strcmp(letter, "y") == 0 || strcmp(letter, "Y") == 0) {
                saveDataFile();
                cout << "Exiting program!" << endl;
                return true;
            } else if (strcmp(letter, "n") == 0 || strcmp(letter, "N") == 0) {

                return false;
            } else {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                cin >> letter;
                cin.ignore(2000, '\n');
            }
        }
        return false;
    }


    bool sdds::Parking::loadDataFile() {
        bool state = true;

        ifstream filein;

        if (!isEmpty()) {

            filein.open(park);

        }
        if (filein.is_open() == false) {
            cout << "could not find file";
            return false;
        }


        char vType;

        Vehicle *vp;

        parkedVehicles = 0;


        while (parkedVehicles < numSpots && state && filein) {

            vType = 'x';

            vp = nullptr;

            filein >> vType;

            filein.ignore();

            if (vType == 'C') {

                vp = new Car();

            } else if (vType == 'M') {

                vp = new Motorcycle();

            }


            if (vp) {

                vp->setCsv(true);

                filein >> *vp;

                if (filein) {

                    spots[vp->getParkingSpot() - 1] = vp;

                    parkedVehicles++;

                } else {

                    delete vp;

                    vp = nullptr;

                    state = false;

                }

            }

        }
        /*if (park != nullptr) {
            cout << "---------------------------------" << endl;
            cout << "loading data from ";
            cout << park << endl;
            cout << "---------------------------------" << endl;
            cout << endl;
            return true;
        }
        else {
            return false;
        }*/
        return state;
    }


    void sdds::Parking::saveDataFile() {

        if (!isEmpty()) {

            ofstream fileout(park);

            if (fileout) {

                for (int i = 0; i < numSpots; i++) {

                    if (spots[i] != nullptr) {

                        spots[i]->setCsv(true);

                        fileout << *spots[i];

                    }

                }

            }

        }

        if (!isEmpty()) {

        }
    }


    int sdds::Parking::run() {

        if (!isEmpty()) {

            bool flag = true;
            int choice;
            while (flag) {
                Parkingstatus();
                choice = Menu_element.run();

                switch  (choice) {
                    case 1:

                        this->VehicleFunction();
                        break;
                    case 2:
                        this->ReturningVehicle();
                        cout << "Press <ENTER> to continue...." << endl;
                        break;
                    case 3:

                        this->vehicleList();
                        cout << "Press <ENTER> to continue...." << endl;
                        break;


                    case 4:

                        this->FindingVehicle();
                        cout << "Press <ENTER> to continue...." << endl;
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


    sdds::Parking::~Parking() {
        for (int i = 0; i < maxSpots; i++) {
            delete spots[i];
        }
        delete[] park;
        park = nullptr;
    }

    void sdds::Parking::vehicleList() const {
        cout << "*** List of parked vehicles ***" << endl;

        for (int i = 0; i < numSpots; i++) {

            if (spots[i] != nullptr) {

                spots[i]->setCsv(false);

                cout << *spots[i];

                cout << "-------------------------------" << endl;

            }

        }

    }


    void sdds::Parking::setEmpty() {
        park = nullptr;
        numSpots = 0;
        for (int i = 0; i < 100; i++) {
            spots[i] = nullptr;
        }
        parkedVehicles = 0;
    }

    void sdds::Parking::parkVehicle() {

        if (numSpots == parkedVehicles) {

            cout << "Parking is full" << endl;

        } else {

            int selection = Vehicle_element.run();

            if (selection == 3) {

                cout << "Parking cancelled" << endl;

            } else {

                Vehicle *vp = nullptr;

                if (selection == 1) {

                    vp = new Car();

                } else if (selection == 2) {

                    vp = new Motorcycle();

                }


                vp->setCsv(false);

                cin >> *vp;


                bool valid = true;

                for (int i = 0; i < numSpots && valid; i++) {

                    if (spots[i] != nullptr && *spots[i] == *vp) {

                        cout << "\nCan not park; license plate already in the system!" << endl;

                        cout << *vp;

                        cout << endl;

                        valid = false;

                    }

                }

                if (valid && parkedVehicles < numSpots) {

                    for (int i = 0; i < numSpots && valid; i++) {

                        if (spots[i] == nullptr) {

                            spots[i] = vp;

                            spots[i]->setParkingSpot(i + 1);

                            cout << "\nParking Ticket" << endl;

                            cout << *spots[i];

                            cout << endl;

                            parkedVehicles++;

                            valid = false;

                        }

                    }

                }

            }
        }
    }
