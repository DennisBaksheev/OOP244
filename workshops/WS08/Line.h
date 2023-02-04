#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void drawShape(std::ostream& os)const;
        void getSpecs(std::istream& is);
    };
}
#endif // !SDDS_LINE_H