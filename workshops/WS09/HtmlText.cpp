#include <iostream>
#include <fstream>
#include <string.h>
#include "HtmlText.h"

namespace sdds{
    HtmlText ::HtmlText() : Text()
    {
        m_title = nullptr;
    }

    HtmlText::HtmlText(const char *ro) : Text()
    {
        m_title = new char[strlen(ro) + 1];
        strcpy(m_title, ro);
    }

    HtmlText &HtmlText ::operator=(const HtmlText &ro)
    {

        delete m_title;

        m_title = new char[strlen(ro.m_title) + 1];
        strcpy(m_title, ro.m_title);

        Text::operator=(ro);

        return *this;
    }

    HtmlText ::~HtmlText()
    {
        delete[] m_title;
    }

    std::ostream &HtmlText::write(std::ostream &ostr) const
    {
        // ostr << this->operator[](1);
        ostr << "<html><head><title>";
        if (m_title != nullptr)
        {
            ostr << m_title;
        }
        else
        {
            ostr << "No Title";
        }
        ostr << "</title></head>\n<body>\n";
        if (m_title != nullptr)
        {
            ostr << "<h1>" << m_title << "</h1>\n";
        }
        bool MS = false;
        int i = 0;
        while (this->operator[](i) != '\0')
        {
            const char ch = this->operator[](i);

            if (ch == ' ')
            {
                if (MS)
                {

                    ostr << "&nbsp;";
                }
                else
                {

                    MS = true;

                    ostr << ' ';
                }
            }
            else if (ch == '<')
            {
                MS = false;
                ostr << "&lt;";
            }
            else if (ch == '>')
            {
                MS = false;
                ostr << "&gt;";
            }
            else if (ch == '\n')
            {

                MS = false;
                ostr << "<br />\n";
            }
            else
            {
                MS = false;
                ostr << ch;
            }

            i++;
        }
        ostr << "</body>\n</html>";
        return ostr;
    }


    std::istream &operator>>(std::istream &istr, HtmlText &ro)
    {
        return ro.read(istr);
    }


    std::ostream &operator<<(std::ostream &ostr, const HtmlText &ro)
    {
        return ro.write(ostr);
    }
}