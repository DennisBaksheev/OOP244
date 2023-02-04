#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"
namespace sdds
{
    class Dumper : public VehicleBasic
    {
        double m_capacity;
        double m_cargo;

    public:
        Dumper(const char* plate, int year, double capacity, const char* address);

        bool loaddCargo(double cargo);
        bool unloadCargo();

        std::istream& read(std::istream& in);
        std::ostream& write(std::ostream& out) const;
    };

    std::istream& operator>>(std::istream& in, Dumper& c);
    std::ostream& operator<<(std::ostream& out, const Dumper& c);
}
#endif