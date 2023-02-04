#include <iostream>
#include <cstring>
#include "TourBus.h"

using namespace std;
namespace sdds {

    bool TourBus::validTour() const
    {
        bool is_ok = false;

        if(busNum == 4 || busNum == 16 || busNum == 22)
        {
            is_ok = true;
        }

        return is_ok;
    }

    TourBus::TourBus(int num)
    {
      this->busNum = num;
      this->t = new TourTicket[num];
    }

    TourBus::~TourBus(){
      delete[] t;
    }
    
    TourBus& TourBus::board() 
    {
      string name;
      int i;

      cout << "Boarding " << busNum << " Passengers: "
 <<endl;

      for (i = 0; i < busNum; i++) 
      {
        cout << i+1 << "/4- Passenger Name: ";
        getline(cin, name);
        
        TourTicket ticket = TourTicket();  
        ticket.issue(name.c_str());
        t[i] = ticket;
      }
      return *this;
    }							

    void TourBus::startTheTour() const
    {
        if (busNum != 4)
        {
            cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
        }else{
          
            cout << "Starting the tour...." << endl;
            cout << "Passenger List:" << endl;
            cout << "|Row | Passenger Name                           | Num |" << endl;
          cout << "+----+------------------------------------------+-----+" << endl;
          for(int i=0; i < busNum; i++){
            //cout << "+----+------------------------------------------+-----+" << endl;
            TourTicket ticket = t[i];
            ticket.display();
            //cout << "+----+------------------------------------------+-----+" << endl;  
          }
          cout << "+----+------------------------------------------+-----+" << endl;  
          
        }

    }		
}