#include "Seat.h"
#include <cstring>


  bool Seat::validate(int row, char letter) const{
    if (row < 1 || row == 5 || row == 6 || (15 < row && row < 20) || 
      38 < row ) {
      return false;
    }
    else if ('F' < letter || letter < 'A'){
      return false;
    }
    else if ((0 < row && row < 5) && (letter == 'C' || letter == 'D')){
      return false;
    }
    else{
      return true;
    }
  }

  Seat& Seat::alAndCp(const char* str){
    passName = nullptr;
    if(str == nullptr || strlen(str) == 0){
      passName = nullptr;
    } else {
      int passNumber = strlen(str) + 1;
      passName = new char[passNumber];
      strcpy(passName, str);
    }
    return *this;
  }

  Seat::Seat(){
    passName = nullptr;
    rowNumber = 0;
    seatLetter = '\0';
  }

  Seat::Seat(const char* passengerName){
    alAndCp(passengerName);
    rowNumber = 0;
    seatLetter = '\0';
  }

  Seat::Seat(const char* passengerName, int row, char letter){
    alAndCp(passengerName);
    rowNumber = row;
    seatLetter = letter;
  }
  Seat::~Seat(){
    delete[] passName;
  }
  Seat& Seat::reset(){
    delete[] passName;
    passName = nullptr;
    rowNumber = 0;
    seatLetter = '\0';
    return *this;
  }

  bool Seat::isEmpty() const{
    if(passName == nullptr){
      return true;
    }
    else{
      return false;
    }
  }

  bool Seat::assigned() const{
    if(rowNumber == 0) {
      return false;
    }
    else{
      return true;
    }
  }

  Seat& Seat::set(int row, char letter){

    if( validate(row, letter) == true){
      rowNumber = row;
      seatLetter = letter;
    } else {
      rowNumber = 0;
      seatLetter = '\0';
    }
    return *this;
  }
  int Seat::row() const{
    return rowNumber;
  }
  char Seat::letter() const {
    return seatLetter;
  }
  const char* Seat::passenger() const{
    return passName;
  }
  std::ostream& Seat::display(std::ostream& coutRef) const{
    
    if(isEmpty()){
      return coutRef << "Invalid Seat!";
      
    } else if(assigned() == false) {
      int passNumber = strlen(passName);
      if (passNumber > 40){
        char* nickName= new char[41];
        strncpy(nickName, passName, 40);
        nickName[40] = '\0';
        coutRef << nickName;
        delete[] nickName;
      } else {
        int dots = 40 - passNumber; 
        coutRef << passName;
        for (int i = 0; i < dots; i++) {
          coutRef << ".";
        }
      }
      return coutRef << " ___";
    } else{
      int passNumber = strlen(passName);
      if (passNumber > 40){
        char* nickName = new char[41];
        strncpy(nickName, passName, 40);
        nickName[40] = '\0';
        coutRef << nickName;
        delete[] nickName;
      } else {
        int dots = 40 - passNumber; 
        coutRef << passName;
        for (int i = 0; i < dots; i++) {
          coutRef << ".";
        }
      }
      return coutRef << " " << rowNumber << seatLetter;
    }
  }

  std::istream& Seat::read(std::istream& cinRef){
    reset();
    char* tmpName = new char[71];
    int row;
    char letter;

    
    cinRef.getline(tmpName, 70, ',');
    tmpName[70] = '\0';
    cinRef >> row;
    cinRef >> letter;

    if(cinRef.fail() == false){
      alAndCp(tmpName);
      set(row,letter);  
    } 
    cinRef.getline(tmpName,70);
    delete[] tmpName;
    return cinRef;
  }


