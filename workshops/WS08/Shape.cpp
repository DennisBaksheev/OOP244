#include "Shape.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Shape & s)
    {
        s.drawShape(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape & s)
    {
        s.getSpecs(is);
        return is;
    }

    // ~Shape () {};

}
