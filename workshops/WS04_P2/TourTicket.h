#ifndef SDDS_TOURTICKET_H_
#define SDDS_TOURTICKET_H_
#include <iostream>
namespace sdds {
   class TourTicket {
      char m_name[4][41];
      int m_ticketNumber[4];
      int ticketCount;
      int row;

   public:
      TourTicket();
      TourTicket& issue(const char* passengerName);
      std::ostream& display(std::ostream& coutRef = std::cout)const;
      bool valid()const;
   };
}
#endif // !SDDS_TOURTICKET_H_

