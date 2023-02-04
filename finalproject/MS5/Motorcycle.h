#ifndef SDDS_Motorcycle_H__
#define SDDS_Motorcycle_H__
#include "Vehicle.h"
#include <iostream>
using namespace std;
namespace sdds
{
    class Motorcycle : public Vehicle
    {
    public:
        bool sidecar = false;
        Motorcycle();
        Motorcycle(const char lp[], const char* mdl);
        std::istream& read(std::istream& in);
        std::ostream& write(std::ostream& os) const;
        virtual ostream& writeType(ostream& os) const override;
    };
}


#endif