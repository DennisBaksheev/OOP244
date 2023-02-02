#pragma once
#ifndef SDDS_READWRITEABLE_H
#define SDDS_READWRITEABLE_H
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sdds {
    class ReadWritable {
    protected:
        bool flag = false;
    public:
        ReadWritable();

        bool isCsv()const;

        void setCsv(bool value);
        virtual ~ReadWritable();

        virtual istream& read(istream& is = cin) = 0;

        virtual ostream& write(ostream& os = cout) const = 0;
    };

    ostream& operator<<(ostream& os, const ReadWritable& rw);

    istream& operator>>(istream& is, ReadWritable& rw);
}

#endif