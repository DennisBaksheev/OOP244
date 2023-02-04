#include <iostream>
using namespace std;


class Seat{
   char *passName;
   int rowNumber;
   char seatLetter;

  bool validate(int row, char letter)const;
  Seat& alAndCp(const char* str);

public: 
  Seat();
  Seat(const char* passengerName);
  Seat(const char* passengerName, int row, char letter);
  ~Seat();
  Seat& reset();
  bool isEmpty() const;
  bool assigned() const;
  Seat& set(int row, char letter);
  int row()const;
  char letter()const;
  const char* passenger()const;
  std::ostream& display(std::ostream& coutRef = std::cout) const;
  std::istream& read(std::istream& cinRef = std::cin);
};


