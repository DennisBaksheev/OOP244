#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"
using namespace std;
namespace sdds
{
    Dumper::Dumper(const char* plate, int year, double capacity, const char* address) : VehicleBasic(plate, year)
    {
        this->m_capacity = capacity;
        this->m_cargo = 0;
        this->NewAddress(address);
    }

    bool Dumper::loaddCargo(double cargo)
    {
        bool loaded=false;
        if (this->m_cargo + cargo <= this->m_capacity)
        {
            this->m_cargo += cargo;
            loaded =true;
        }
        return loaded;
    }

    bool Dumper::unloadCargo()
    {
        bool unload = this->m_cargo > 0;
        this->m_cargo = 0;
        return unload;
    }

    std::istream& Dumper::read(std::istream& in)
    {
        VehicleBasic::read(in);
        cout << "Capacity: ";
        in >> this->m_capacity;
        cout << "Cargo: ";
        in >> this->m_cargo;
        return in;
    }

    std::ostream& Dumper::write(std::ostream& out) const
    {
        VehicleBasic::write(out);
        out << " | ";
        out << this->m_cargo << "/" << this->m_capacity;
        return out;
    }

    istream& operator>>(istream& in, Dumper& theDumper)
    {
        return theDumper.read(in);
    }

    ostream& operator<<(ostream& os, const Dumper& theDumper)
    {
        return theDumper.write(os);
    }
}
