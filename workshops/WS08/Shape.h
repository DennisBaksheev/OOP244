#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
    class Shape  {
    public:
        virtual void drawShape(std::ostream& os)const=0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape () {};
    };
    std::ostream& operator<<(std::ostream& os, const Shape & s);
    std::istream& operator>>(std::istream& is, Shape & s);

}

#endif // !SDDS_SHAPE_H