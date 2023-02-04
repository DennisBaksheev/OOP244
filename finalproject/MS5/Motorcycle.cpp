#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Motorcycle.h"
#include "Vehicle.h"
using namespace std;

namespace sdds
{
    Motorcycle::Motorcycle() : Vehicle() {
        sidecar = 0;
    }

    Motorcycle::Motorcycle(const char lp[], const char* mdl) : Vehicle(lp, mdl) {
        sidecar = 0;
    }

    istream& Motorcycle::read(istream& is) {
        if (isCsv()) {
            Vehicle::read(is);
            is >> sidecar;
        }
        else {
            cout << endl;
            cout << "Motorcycle information entry" << endl;
            Vehicle::read(is);

            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

            bool check = true;
            char response[6];
            while (check)
            {
                is.getline(response, 6, '\n');
                if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0 || strcmp(response, "N") == 0 || strcmp(response, "n") == 0) {
                    check = false;

                    if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0) {
                        sidecar = true;
                        check = false;
                    }
                    else {
                        sidecar = false;
                    }
                }
                else {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

                }

            }
        }
        return is;
    }

    ostream& Motorcycle::write(ostream& os) const {
        if (!isEmpty()) {
            if (isCsv()) {
                os << "M,";
            }
            else {
                os << "Vehicle type: Motorcycle" << endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                os << sidecar << endl;

            }
            else if (sidecar) { cout << "With Sidecar" << endl; }
        }
        else {
            os << "Invalid Motorcycle Object" << endl;
        }
        return os;
    }

    ostream& Motorcycle::writeType(ostream& os) const {
        if (isCsv() == true) {
            return os << "M,";
        }
        else {
            os << "Vehicle type: Motorcycle" << endl;
            return os;
        }
    }
}