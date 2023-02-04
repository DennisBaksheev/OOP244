#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"


namespace sdds
{
    class HtmlText : public Text
    {

        char *m_title{};

        //     less than operator(<) is replaced by "&lt;" characters
        // greater than operator(>) is replaced by "&gt;" characters
        // newline ('\n') is replaced by "<br />\n" characters
        // space character(' '): if more than one, except from the first, the rest are replaced by "&nbsp;"

    public:
        HtmlText();

        HtmlText(const char *ro);

        HtmlText &operator=(const HtmlText &ro);

        ~HtmlText();

        std::ostream &write(std::ostream &ostr) const;
    };
    std::istream &operator>>(std::istream &istr, HtmlText &ro);

    std::ostream &operator<<(std::ostream &ostr, const HtmlText &ro);
}

#endif // !SDDS_EMPPROFILE_H