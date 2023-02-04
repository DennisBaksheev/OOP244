#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"

using namespace std;



namespace sdds
{

    const char &Text::operator[](int index) const
    {

        if (strlen(m_content) < size_t(index) || size_t(strlen(m_content)) < 0)
        {
            return m_content[strlen(m_content)];
        }

        return m_content[index];
    }

    Text ::Text()
    {
        m_content = nullptr;
    }

    Text ::Text(const Text &ro)
    {
        m_content = new char[strlen(ro.m_content) + 1];
        strcpy(m_content, ro.m_content);
    }

    int Text ::getFileLength(std::istream &is)
    {
        int len{};
        if (is)
        {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }

        return len;
    }

    Text &Text ::operator=(const Text &ro)
    {   delete[] m_content;
        m_content = new char[strlen(ro.m_content) + 1];
        strcpy(m_content, ro.m_content);

        return *this;
    }

    Text ::~Text()
    {
        delete[] m_content;
    }

    std::istream &Text ::read(std::istream &istr)
    {
        char ch;
        istr.clear();
        istr.seekg(0, ios::beg);
        int len = getFileLength(istr);
        istr.clear();
        istr.seekg(0, ios::beg);

        m_content = new char[len + 1];

        int i = 0;
        while (istr >> noskipws >> ch)
        {
            m_content[i++] = ch;
        }

        m_content[i] = '\0';
        return istr;
    }

    std::ostream &Text ::write(std::ostream &ostr) const
    {
        ostr << m_content;

        return ostr;
    }

    std::istream &operator>>(std::istream &istr, Text &ro)
    {
        return ro.read(istr);
    }

    std::ostream &operator<<(std::ostream &ostr, const Text &ro)
    {
        return ro.write(ostr);
    }

}