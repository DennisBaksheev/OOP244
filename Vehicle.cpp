#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Vehicle.h"
using namespace std;

namespace sdds
{
    Vehicle::Vehicle()
    {
        licensePlate[0] = '\0';
        model = nullptr;
        parkNum = 0;
    }

    Vehicle::Vehicle(const char lp[], const char* mdl, int pkn)
    {
        licensePlate[0] = '\0';
        model = nullptr;
        parkNum = 0;

        if (lp != nullptr && strlen(lp) > 0 && strlen(lp) < 9 && mdl != nullptr && strlen(mdl) > 2)
        {
            parkNum = pkn;
            strcpy(licensePlate, lp);
            model = new char[strlen(mdl) + 1];
            strcpy(model, mdl);
        }
    }
    int Vehicle::getParkingSpot() const
    {
        return parkNum;
    }

    void Vehicle::setParkingSpot(const int parkingNumber)
    {
        parkNum = -1;
        if (parkingNumber >= 0) {
            parkNum = parkingNumber;
        }
    }

    bool Vehicle::operator== (const char* lp) const
    {
        bool flag = false;
        if (lp != nullptr && !isEmpty())
        {

            char* temporary1 = new char[strlen(licensePlate) + 1];
            temporary1[0] = '\0';
            for (std::size_t i = 0; i <= strlen(licensePlate); i++)
            {
                temporary1[i] = toupper(licensePlate[i]);
            }


            char* temporary2 = new char[strlen(lp) + 1];
            temporary2[0] = '\0';
            for (std::size_t i = 0; i <= strlen(lp); i++)
            {
                temporary2[i] = toupper(lp[i]);
            }

            if (strcmp(temporary1, temporary2) == 0)
                flag = true;

            delete[] temporary1;
            delete[] temporary2;
        }
        return flag;
    }
    bool Vehicle::operator==(const Vehicle& object) const
    {
        return (*this == object.licensePlate);

    }


    void Vehicle::setEmpty()
    {
        licensePlate[0] = '\0';
        if (model != nullptr)
            delete[] model;
        model = nullptr;
        parkNum = 0;
    }

    bool Vehicle::isEmpty() const
    {
        bool check;
        if (licensePlate[0] == '\0' || model == nullptr || parkNum < 0) {
            check = true;
        }
        else {
            check = false;
        }
        return check;
    }

    char* Vehicle::getLicensePlate() const
    {
        char* temporary = new char[strlen(licensePlate) + 1];
        strcpy(temporary, licensePlate);
        return temporary;
    }

    char* Vehicle::getMakeModel() const
    {
        return model;
    }

    void Vehicle::setMakeModel(const char* mdl)
    {
        if (model != nullptr) {
            delete[] model;
        }
        model = nullptr;
        if (mdl != nullptr)
        {
            int size = strlen(mdl);
            model = new char[size + 1];
            strcpy(model, mdl);
        }
    }
    istream& Vehicle::read(istream& is)
    {
        setEmpty();
        char lp[9];
        lp[0] = '\0';
        int pNumber = 0;
        string tmp;
        int size = 0;
        if (this->isCsv())
        {

            if (getline(is, tmp, ',')) pNumber = stoi(tmp);
            this->setParkingSpot(pNumber);


            if (std::getline(is, tmp, ','))
            {
                size = tmp.length();

                for (int i = 0; i < size; i++)
                {
                    lp[i] = toupper(tmp[i]);
                }
                lp[size] = '\0';
            }
            strcpy(licensePlate, lp);


            if (std::getline(is, tmp, ','))
            {
                this->setMakeModel(tmp.c_str());
            }
        }

        else
        {

            std::cout << "Enter License Plate Number: ";
            while (!is.getline(lp, 9))
            {
                std::cin.clear();
                std::cin.ignore(2000, '\n');
                std::cout << "Invalid License Plate, try again: ";
            }
            size = strlen(lp);
            for (int i = 0; i < size; i++)
            {
                lp[i] = toupper(lp[i]);
            }

            strcpy(licensePlate, lp);


            cout << "Enter Make and Model: ";
            if (getline(is, tmp))
            {

                while (tmp.length() < 2 || tmp.length() > 60)
                {
                    cout << "Invalid Make and model, try again: ";
                    getline(is, tmp);
                }

                setMakeModel(tmp.c_str());
            }

            setParkingSpot(0);
        }
        return is;
    }

    ostream& Vehicle::write(ostream& os) const
    {
        if (isEmpty())
        {
            os << "Invalid Vehicle Object" << std::endl;
        }
        else if (isCsv())
        {
            char* licenseTemp = this->getLicensePlate();
            os << this->getParkingSpot() << "," << licenseTemp << "," << getMakeModel() << ",";
            delete[] licenseTemp;
        }
        else
        {
            os << "Parking Spot Number: ";
            if (getParkingSpot() == 0) os << "N/A";
            else os << getParkingSpot();
            os << std::endl;

            char* lpTmp = getLicensePlate();
            os << "License Plate: " << lpTmp << std::endl;
            delete[] lpTmp;
            os << "Make and Model: " << getMakeModel() << std::endl;
        }
        return os;
    }

    Vehicle::Vehicle(Vehicle& otherVehicle) {
        this->parkNum = otherVehicle.parkNum;
        model = new char[strlen(otherVehicle.model) + 1];
        for (unsigned int i = 0; i < strlen(otherVehicle.licensePlate) ; i++) {
            this->licensePlate[i] = otherVehicle.licensePlate[i];
        }
        licensePlate[strlen(otherVehicle.licensePlate)] = '\0';

        for (unsigned int i = 0; i < strlen(otherVehicle.model) ; i++) {
            this->model[i] = otherVehicle.model[i];
        }
        model[strlen(otherVehicle.model)] = '\0';
    }

    Vehicle& Vehicle::operator=(const Vehicle& otherVehicle) {
        setEmpty();
        this->flag = otherVehicle.flag;
        this->parkNum = otherVehicle.parkNum;
        model = new char[strlen(otherVehicle.model) + 1];
        for (unsigned int i = 0; i < strlen(otherVehicle.licensePlate) ; i++) {
            this->licensePlate[i] = otherVehicle.licensePlate[i];
        }
        licensePlate[strlen(otherVehicle.licensePlate)] = '\0';

        for (unsigned int i = 0; i < strlen(otherVehicle.model) ; i++) {
            this->model[i] = otherVehicle.model[i];
        }
        model[strlen(otherVehicle.model)] = '\0';
        return *this;
    }
}
