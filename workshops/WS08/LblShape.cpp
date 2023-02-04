#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
    const char* LblShape::label() const
    {
        return m_label;
    }
    LblShape::LblShape() {}
    LblShape::LblShape(const char* label)
    {

        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
    LblShape::~LblShape()
    {
        delete[] m_label;
    }
    void LblShape::getSpecs(std::istream& is)
    {
        string label;
        getline(is, label, ',');
        delete[] m_label;
        m_label = new char[strlen(label.c_str()) + 1];
        strcpy(m_label, label.c_str());
    }
}