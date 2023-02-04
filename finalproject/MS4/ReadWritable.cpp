#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ReadWritable.h"

namespace sdds {
    ReadWritable::ReadWritable() {
        flag = false;
    }

    void ReadWritable::setCsv(bool value){
        flag = value;
    }

    bool ReadWritable::isCsv()const {
        return flag;
    }

    ostream& operator<<(ostream& os, const ReadWritable& rw) {
        rw.write(os);
        return os;
    }

    istream& operator>>(istream& is, ReadWritable& rw) {
        rw.read(is);
        return is;
    }
    ReadWritable::~ReadWritable() {

    }
}