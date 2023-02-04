#ifndef SDDS_Vehicle_H__
#define SDDS_Vehicle_H__
#include "ReadWritable.h"
#include <iostream>
using namespace std;

const int MAXLEN = 8;

namespace sdds
{
    class Vehicle : public ReadWritable
    {
        char licensePlate[MAXLEN + 1];
        char* model;
        int parkNum;
    protected:
        void setEmpty();

        bool isEmpty() const;

        char* getLicensePlate() const;

        char* getMakeModel() const;

        void setMakeModel(const char*);

    public:
        Vehicle();

        Vehicle(const char[], const char*, int pkn = 0);

        Vehicle(Vehicle& otherVehicle);
        Vehicle& operator=(const Vehicle&);

        virtual ~Vehicle() {
            delete[] model;
        }

        virtual ostream& writeType(ostream& os) const = 0;

        int getParkingSpot() const;

        void setParkingSpot(const int);

        bool operator==(const char*) const;

        bool operator==(const Vehicle&) const;

        ostream& write(ostream&) const;

        istream& read(istream&);
    };
}


#endif