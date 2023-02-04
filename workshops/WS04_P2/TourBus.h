#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include "TourTicket.h"

namespace sdds {

    class TourBus
    {
        private:
        int busNum;
        TourTicket* t;

        public:
        bool validTour() const;
        TourBus(int num);
        ~TourBus();
        TourBus& board();
        void startTheTour() const;
    };
}
#endif
