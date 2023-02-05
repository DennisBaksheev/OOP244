#include "Mark.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace sdds {
	Mark::Mark() {
		m_mark = 0;
	}

	Mark::Mark(int mark) {
		if (mark <= 100 && mark >= 0) m_mark = mark;
		else m_mark = -1;
	}

	Mark::operator int() const {
		if (m_mark < 0 || m_mark > 100) return 0;
		else return m_mark;
	}

	Mark::operator double() const{
		if (m_mark >= 0 && m_mark < 50) return 0.0;
		else if (m_mark >= 50 && m_mark < 60) return 1.0;
		else if (m_mark >= 60 && m_mark < 70) return 2.0;
		else if (m_mark >= 70 && m_mark < 80) return 3.0;
		else if (m_mark >= 80 && m_mark <= 100) return 4.0;
		else return 0.0;
	}

	Mark::operator char() const {
		if (m_mark >= 0 && m_mark < 50) return 'F';
		else if (m_mark >= 50 && m_mark < 60) return 'D';
		else if (m_mark >= 60 && m_mark < 70) return 'C';
		else if (m_mark >= 70 && m_mark < 80) return 'B';
		else if (m_mark >= 80 && m_mark <= 100) return 'A';
		else return 'X';
	}

	Mark::operator bool() const{
   if (m_mark >= 0 && m_mark <= 100) {
      return true;
    } 
    return false;
  }

  bool Mark::operator== (const Mark& other) const{
    if (m_mark == other.m_mark) {
      return true;
    }
    return false;
  }
		

  bool Mark::operator!= (const Mark& other) const{
    if (m_mark != other.m_mark) {
       return true;
    }
    return false;
  }
    


  bool Mark::operator< (const Mark& other) const{
    if (m_mark < other.m_mark) {
      return true;
    }
    return false;
  }
    


  bool Mark::operator> (const Mark& other) const{
    if (m_mark > other.m_mark) {
      return true;
    }
    return false;
    
  }
  


  bool Mark::operator<= (const Mark& other) const{
    if (m_mark <= other.m_mark) {
      return true;
    }
    return false;
    
  }
    


  bool Mark::operator>= (const Mark& other) const{
    if (m_mark >= other.m_mark) {
      return true;
    }
    return false;
    
  }

  Mark& Mark::operator++ (){
  if (m_mark >= 0 && m_mark <= 100) {
    if (m_mark == 100) {
      return *this;
    }
    m_mark ++;
    return *this;
  } 
    return *this; 
    
  }

  Mark& Mark::operator-- () {
    if (m_mark >= 0 && m_mark <= 100) {
      if (m_mark == 0) {
        return *this;
      }
      m_mark --;
      return *this;
  }
    return *this; 
  }

  bool Mark::operator~ (){
    if (m_mark >= 50 && m_mark <= 100) {
      return true;
    }
    return false;
  }

  Mark Mark::operator++ (int temp){
   if (m_mark < 0 || m_mark > 100){
     return *this;
   }
    temp = *this;
   this->m_mark += 1;
   return temp;
 }
  
  Mark Mark::operator-- (int temp) {
    if (m_mark < 0 || m_mark > 100){
     return *this;
   }
   temp = *this;
   this->m_mark -= 1;
   return temp;
  } 

  Mark& Mark::operator= (int newVal) {
    if (newVal > 100 || newVal < 0) {
      m_mark = -1;
    }
    else {
      m_mark = newVal;
    }
    return *this;
}

  Mark& Mark::operator+= (int addedVal) {
    if (m_mark > 100 || m_mark < 0) {
      return *this;
    }
    else {
      m_mark = m_mark + addedVal;
      return *this;
    }
  }

 Mark& Mark::operator-= (int minusVal) {
   if (m_mark >100 || m_mark < 0) {
     return *this;
   }
   else {
     m_mark = m_mark - minusVal;
     return *this;
  }
}

  int Mark::getm_mark()const {
    return m_mark; 
  }

   int& operator +=(int& oldVal, const Mark& themark) {
   if(themark.getm_mark() >= 0 || themark.getm_mark() <= 100) {
     oldVal = oldVal + themark.getm_mark();
   }
   return oldVal;
  }
  
  int& operator -=(int& oldVal, const Mark& themark)  {
  if(themark.getm_mark() >= 0 || themark.getm_mark() <= 100) {
    oldVal = oldVal - themark.getm_mark();
  }
  return oldVal;
 }

    
  Mark& Mark::operator<< (Mark& otherMark) {
    this-> m_mark = otherMark.m_mark + this->m_mark;
    otherMark.m_mark = 0;
    return *this;
  }
  
  Mark& Mark::operator>> (Mark& otherMark) {
    otherMark.m_mark = this->m_mark + otherMark.m_mark;
    this->m_mark = 0;
    return *this;
}

  Mark Mark::operator+ (int otherVal) const {
  Mark newmark;
  newmark.m_mark = otherVal + this->m_mark;
  return newmark;
  
}
  Mark Mark::operator+ (const Mark& otherMark) const{
  Mark newmark;
  newmark.m_mark = otherMark.m_mark+ m_mark;
  return newmark;
}

int operator+ (int otherVal, const Mark& themark) {
  Mark newmark(otherVal + themark.getm_mark());
  return newmark.getm_mark();
  }
}  
