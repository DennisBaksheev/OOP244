#include "Line.h"
#include <iomanip>
#include <string.h>
using namespace std;
namespace sdds {
    Line::Line() :m_length(0)
    {
        //m_length = 0;
    }
    Line::Line(const char* label, int length) : LblShape(label)//,m_length(length)
    {
        m_length = length;
    }
    void Line::drawShape(std::ostream& os)const
    {
        if (m_length > 0 && label() != nullptr)
        {
            int labelLeng = strlen(label());

            os << label();
            os << setw(m_length - labelLeng) << setfill('=')
               << '=';
            os.fill(' ');
        }
    }
    void Line::getSpecs(std::istream& is)
    {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
}