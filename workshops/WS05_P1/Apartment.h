#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment{

   public:
      int m_number = -1;
      double m_balance = 0.0;

      Apartment(int number, double balance);
      std::ostream& display()const;
      Apartment& operator= (int new_number);
      operator bool() const;
      operator int() const;
      operator double() const;
Apartment::operator bool() const{
      bool operator ~() const;
      Apartment& operator+= (double rentChange);
      Apartment& operator-= (double rentChange);
      Apartment& operator= (Apartment& otherApt);
      double operator+ (Apartment& otherApt);
      Apartment& operator<< (Apartment& otherApt);
      Apartment& operator>> (Apartment& otherApt);    
      
   };
  double operator+= (double& lhs, const Apartment rhs);
}

#endif // SDDS_APARTMENT_H_
