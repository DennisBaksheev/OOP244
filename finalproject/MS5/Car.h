#ifndef SDDS_Motorcycle_H__
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace sdds
{
    class Car : public Vehicle
    {

    public:
        bool carwash = false;
        Car();
        Car(const char lp[], const char* mdl);
        std::istream& read(std::istream& in);
        std::ostream& write(std::ostream& os) const;
        virtual ostream& writeType(ostream& os) const override;
    };
}


#endif