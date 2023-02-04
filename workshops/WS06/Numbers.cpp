#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Numbers.h"
#include "Numbers.h"  

using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
    }
   

    Numbers::Numbers(const Numbers& n)
   {
       setEmpty();
       this->m_numbers = new double[n.m_numCount];
       for (int i = 0; i < n.m_numCount; i++) {
           this->m_numbers[i] = n.m_numbers[i];
       }
       setFilename(n.m_filename);
       this-> m_numCount = n.m_numCount;
       m_isOriginal = false;


   }

   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   
   Numbers& Numbers::sort(bool ascending) {
    int i, j, minIdx;
    double temp;
    for (i = 0; i < m_numCount; i++)
    {
        minIdx = i;

        for (j = i + 1; j < m_numCount; j++)
        {
          if (ascending == true) {
          if (m_numbers[j] < m_numbers[minIdx])
            {
                minIdx = j;
            }
          }
          else if (ascending == false) {
          if (m_numbers[j] > m_numbers[minIdx])
            {
                minIdx = j;
            }
          }
        }

        if (minIdx != i)
        {
            temp = m_numbers[i];
            m_numbers[i] = m_numbers[minIdx];
            m_numbers[minIdx] = temp;
        }
    }
}

   

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
     
          void Numbers::deallocate() {
            delete[] m_numbers;
            delete[] m_filename;
            m_numbers = nullptr;
            m_filename = nullptr;
          }
      Numbers Numbers::operator-()const {
      Numbers new_numbers = *this;
      new_numbers.sort(false);
      return new_numbers;
        
      }
      Numbers Numbers::operator+()const{
       Numbers new_numbers = *this;
       new_numbers.sort(true);
       return new_numbers;
        
      }

  double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   Numbers& Numbers::operator=(const Numbers& n)
   {
       delete[] this->m_numbers;
       setEmpty();
       this->m_isOriginal = false;
       this->m_numbers = new double[n.m_numCount];

       for (int i = 0;i < n.m_numCount;i++) {
           this->m_numbers[i] = n.m_numbers[i];
       }
       this->m_numCount = n.m_numCount;
       setFilename(n.m_filename);
       return *this;
   }

int Numbers::numberCount()
   {
       ifstream inFile(this->m_filename);
       int counter = 0;

       if (inFile.is_open()) {
           double i = 0;

           while (inFile >> i) {
               counter += 1;
           }
       }
       return counter;
   }
   

   bool Numbers::load()
   {
       if (m_numCount > 0) {
           this->m_numbers = new double[m_numCount];

           ifstream inFile(this->m_filename);

           double i = 0;
           int index = 0;

           if (inFile.is_open()) {
               while (inFile >> i) {
                   
                   m_numbers[index] = i;
                   index += 1;
               }
           }

           return (m_numCount == index);
       }
       return false;
   }

   void Numbers::save()
   { 
     setprecision(2);
       if (this->m_isOriginal && !this->isEmpty()) {
           ofstream outFile("numbers.txt");

           for (int i = 0;i < m_numCount;i++) {
               outFile << fixed << setprecision(2) << m_numbers[i] << endl;
           }
       }
   }

    Numbers& Numbers::operator+=(double value) 
   {
       if (!this->isEmpty()) {
           double* temp = new double[m_numCount + 1];

           for (int i = 0;i < m_numCount;i++) {
               temp[i] = m_numbers[i];
           }

           m_numCount += 1;

           temp[m_numCount-1] = value;

          
           delete[] m_numbers;

           m_numbers=temp;

           
       }
       
       return (*this);
   }
   ostream& Numbers::display(ostream& ostr) const
  
{
   ostr << fixed << setprecision(2);
  
       if (this->isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (!m_isOriginal) {
               ostr << "*** COPY ***" << endl;
           }
           else {
               ostr << this->m_filename << endl;
           }

           for (int i = 0;i < m_numCount;i++) {
               ostr << fixed << setprecision(2) << m_numbers[i];

               if (i != m_numCount-1) {
                   ostr << ", ";
               }

           }

           ostr << endl;

           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << this->max() << endl;
           ostr << "Smallest number: " << this->min() << endl;
           ostr << "Average:         " << this->average() << endl;
           ostr << "=========================";

       }
       return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N)
   {
      return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N)
   {
      double i = 0;
      cin >> i;
      N += i;
      return istr;
   }

   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }


   
}
