#include <iostream>
#include <string.h>
#include "TourTicket.h"
using namespace std;
namespace sdds {
  int next_ticketNumber = 100;
  int background_row = 1;
  
  TourTicket::TourTicket() {
    ticketCount = 0;
  }
   
  TourTicket& TourTicket::issue(const char* passengerName) {
    if(passengerName && passengerName[0]) {
      // copyName(passengerName);
      strcpy(m_name[ticketCount],passengerName);
      m_ticketNumber[ticketCount] = next_ticketNumber;
      next_ticketNumber++;
      row = background_row;
      background_row++;
      ticketCount++;
    }
    return *this;
  }

   std::ostream& TourTicket::display(std::ostream& coutRef) const {

      // for(int i=0;i<ticketCount;i++)
        if(valid()) {
          cout << "| ";
          coutRef.width(2);
          cout<< row;
          coutRef.width(3);
                   cout << "| ";
                   coutRef.width(40);
                   coutRef.setf(ios::left);
                   coutRef << m_name[0] << " | " << m_ticketNumber[0] << " |";
                   coutRef.unsetf(ios::left);
          cout<<endl;
      }
      else {
         coutRef << "Invalid TourTicket information" << endl;
      }
      return coutRef;
   }


   bool TourTicket::valid() const {
      return bool(m_name[0]);
   }
}