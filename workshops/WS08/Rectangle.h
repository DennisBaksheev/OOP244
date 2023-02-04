// Name:Dennis Baksheev
// ID:114797186
// Email:dbaksheev@myseneca.ca
// Date:07/20/2021
// Section: NFF

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
    class Rectangle : public LblShape {
        int m_width, m_spaces;
        char *m_label{};
    public:
        Rectangle();
        Rectangle(const char* label, int width, int spaces);
        void drawShape(std::ostream& os)const;
        void getSpecs(std::istream& is);

    };
}
#endif

