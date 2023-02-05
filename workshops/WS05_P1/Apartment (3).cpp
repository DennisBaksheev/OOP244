#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

namespace sdds
{ 
  Apartment::Apartment(int number, double balance) {
    string str_number = to_string(number);
    int size = str_number.length(); 
    if (size == 4 && balance > 0) {
      m_number = number;
      m_balance = balance;
    }
  }

    
    
  std::ostream& Apartment::display() const {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
  }

  Apartment& Apartment::operator= (int new_number){
    std::string str_number = std::to_string(new_number);
    int size = str_number.length();
    if (size == 4) {
      m_number = new_number;
    }
    else {
      m_number = -1;
      m_balance = 0;
    }
    return *this;
  }

  Apartment::operator int() const {
    return m_number;
  }
  
  Apartment::operator double() const {
    return m_balance;
  }
  bool Apartment::operator~ () const {
    if (m_balance < 0.00001 && m_balance >= 0.0) {
      return true;
    }
    else {
      return false;
    }
  }
  Apartment& Apartment::operator+= (double rentChange) {
    std::string str_number = std::to_string(m_number);
    int size = str_number.length();
    if (m_balance < 0 || size < 4 || size > 4 || rentChange < 0){
      return *this;
    }
  else {
      m_balance = m_balance + rentChange;
      return *this;
    }
  }

  double Apartment::operator+ (Apartment& otherApt) {
    std::string str_number = std::to_string(m_number);
    int size = str_number.length();
    std::string apt_number =       
    std::to_string(otherApt.m_number);
    int size_apt = apt_number.length();
     
    if (size == 4 && m_balance >= 0 && size_apt == 4 && otherApt.m_balance >= 0){
       return this->m_balance + otherApt.m_balance;
    }
     return 0.0; 
   }
   
  
  Apartment& Apartment::operator-= (double rentChange) {
    std::string str_number = std::to_string(m_number);
    int size = str_number.length();
    if (m_balance < 0 || size < 4 || size > 4 || rentChange < 0 || m_balance - rentChange < 0){
      return *this;
    }
    else {
      m_balance = m_balance - rentChange;
      return *this;
    }
}
  


  Apartment::operator bool() const{
   std::string str_number = std::to_string(m_number);
    int size = str_number.length();
    if (size == 4 && m_balance >= 0) {
      return true;
    } 
    return false;
  }

  Apartment& Apartment::operator= (Apartment& otherApt) {
   // A is known as 'this'
   // B is kown as 'otherApt'
   int original_A_number = this->m_number;
   int original_A_balance = this->m_balance;

   this->m_number = otherApt.m_number;
   this->m_balance = otherApt.m_balance;

   otherApt.m_number = original_A_number;
   otherApt.m_balance = original_A_balance;
  
   return *this;
   
  }

  Apartment& Apartment::operator<< (Apartment& otherApt){
    std::string str_number = std::to_string(m_number);
    int size = str_number.length();
    std::string apt_number = 
    std::to_string(otherApt.m_number);
    int size_apt = apt_number.length();
  if (size && size_apt == 4 && otherApt.m_balance && m_balance >= 0 && &otherApt != this) {
         m_balance = m_balance + otherApt.m_balance;
      otherApt.m_balance = 0;
      }
      return *this;
    }

Apartment& Apartment::operator>> (Apartment& otherApt)
{ 
  
  std::string str_number = std::to_string(m_number);
    int size = str_number.length();
  std::string apt_number = std::to_string(otherApt.m_number);
    int size_apt = apt_number.length();
  if (size == 4 && size_apt == 4 && otherApt.m_balance && m_balance >= 0 && this != &otherApt) {
      otherApt.m_balance = m_balance + otherApt.m_balance;
      m_balance = 0;
    }  
      return *this;
  }

  double operator+= (double& lhs, const Apartment rhs){
    lhs += rhs.m_balance;
    return lhs;
  }
}
   







