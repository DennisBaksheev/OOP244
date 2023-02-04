#ifndef SDDS_Car_H__
#define SDDS_Car_H__
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace sdds
{
    class Car : public Vehicle
    {
        bool carwash = false;
    public:
        Car();
        Car(const char lp[], const char* mdl);
        std::istream& read(std::istream& in);
        std::ostream& write(std::ostream& os) const;
        virtual ostream& writeType(ostream& os) const override;
    };
}


#endif