#ifndef REVERSESTRIG_H
#define REVERSESTRIG_H

#include <algorithm>
#include "WorkerThread.h"

namespace pro
{
    class ReverseString : public WorkerThread<ReverseString>
    {
        public:
        template<typename T>
        T task(const T & val) 
        {
            T reversedStr = val; // Create a copy
            std::reverse(reversedStr.begin(), reversedStr.end());
            return reversedStr;
        }      

    };

}

#endif
