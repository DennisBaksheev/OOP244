#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
class Numbers {
  double* m_numbers;
  char* m_filename;
  int m_numCount;
  bool m_isOriginal;
  bool isEmpty() const;
  void setEmpty();
  void setFilename(const char *filename);
  Numbers& sort(bool ascending);
  

public:
  Numbers();
  Numbers(const char *filename);
  Numbers(const Numbers &n);
  double average() const;
  double max() const;
  double min() const;
  Numbers &operator=(const Numbers &n);
  int numberCount();
  bool load();
  void save();
  Numbers& operator+=(double value);
  std::ostream &display(std::ostream &ostr) const;
  ~Numbers();
  void deallocate();
  Numbers operator-()const;
  Numbers operator+()const;


};

std::ostream &operator<<(std::ostream &os, const Numbers &N);
std::istream &operator>>(std::istream &istr, Numbers &N);
} 
#endif 