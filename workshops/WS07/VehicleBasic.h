#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>
namespace sdds
{

    class VehicleBasic
    {
        char m_licensePlate[32];
        char m_currentAddress[64];
        int m_year;

    public:
        VehicleBasic(const char* plate, int year);
        void NewAddress(const char* address);

        std::istream& read(std::istream& in);
        std::ostream& write(std::ostream& os) const;
    };

    std::istream& operator>>(std::istream& in, VehicleBasic& v);
    std::ostream& operator<<(std::ostream& os, const VehicleBasic& v);
}
#endif