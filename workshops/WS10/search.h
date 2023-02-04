#ifndef SDDS_SEARCH_H_
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
namespace sdds {
    template<typename T, typename U>
    bool search(Collection<T>& obj, T arr[], int size, U key)
    {
        bool res = false;
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == key)
            {
                res = true;
                obj.add(arr[i]);
            }
        }
        return res;
    }


}
#endif