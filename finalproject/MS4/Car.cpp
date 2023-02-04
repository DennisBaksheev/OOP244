#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Car.h"
#include "Vehicle.h"
using namespace std;

namespace sdds
{
    Car::Car() : Vehicle() {
        carwash = 0;
    }

    Car::Car(const char lp[], const char* mdl) : Vehicle(lp, mdl) {
        carwash = 0;
    }

    istream& Car::read(istream& is) {
        if (isCsv()) {
            Vehicle::read(is);
            is >> carwash;
            is.ignore(10000, '\n');
        }
        else {
            cout << endl;
            cout << "Car information entry" << endl;
            Vehicle::read(is);

            cout << "Carwash while parked? (Y)es/(N)o: ";

            bool check = true;
            char response[6];

            while (check)
            {
                is.getline(response, 6, '\n');
                if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0 || strcmp(response, "N") == 0 || strcmp(response, "n") == 0) {
                    check = false;

                    if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0) {
                        carwash = true;
                        check = false;
                    }
                    else {
                        carwash = false;
                    }
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

                }

            }
        }
        return is;
    }

    ostream& Car::write(ostream& os) const {
        if (!isEmpty()) {
            if (isCsv()) {
                cout << "C,";
            }
            else {
                cout << "Vehicle type: Car" << endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                cout << carwash << endl;

            }
            else if (carwash) {
                cout << "With Carwash" << endl;
            }
            else {
                cout << "Without Carwash" << endl;
            }
        }
        else {
            cout << "Invalid Car Object" << endl;
        }
        return os;
    }


    ostream& Car::writeType(ostream& os) const {
        if (isCsv() == true) {
            return os << "C,";
        }
        else {
            os << "Vehicle type: Car" << endl;
            return os;

        }




    }
}