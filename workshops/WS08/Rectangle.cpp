#include <iomanip>
#include <cstring>
#include <string>
#include <iostream>
#include "Rectangle.h"
using namespace std;
namespace sdds {
    Rectangle::Rectangle(){}
    Rectangle::Rectangle(const char* label, int width, int spaces)
            :LblShape(label), m_width(width), m_spaces(spaces)
    {
        if (width < int(strlen(label) + spaces + 2)) m_width = 0;
    }
    void Rectangle::drawShape(std::ostream& os)const {

        if(m_width!=0)
        {
            os<<"+";

            for(int i=0;i<(m_width - 2);i++) os<<'-';

            os<<"+\n";

            os<<"|";

            os << left << setw (m_width-m_spaces-2) << label();

            for(int i=0;i<(m_spaces);i++) os<<' ';

            os<<"|\n";

            for(int i=0;i<(m_spaces - 3);i++)
            {
                os<<"|";

                os << left << setw (m_width-m_spaces-2) << " ";

                for(int i=0;i<(m_spaces);i++) os<<' ';

                os<<"|\n";
            }

            os<<"+";

            for(int i=0;i<(m_width - 2);i++) os<<'-';

            os<<"+";
        }

    }





    void Rectangle::getSpecs(std::istream& is)
    {

        this->LblShape::getSpecs(is);

        int a,b;

        char ch;

        is>> a;

        is>>ch;

        is>> b;

        is.ignore();

        m_spaces=b;
        m_width=a;

    }


}