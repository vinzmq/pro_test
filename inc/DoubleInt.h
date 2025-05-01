#ifndef DOUBLEINT_H
#define DOUBLEINT_H

#include <iostream>
#include <queue>
#include <thread>

#include "WorkerThread.h"

namespace pro
{
    class DoubleInt : public WorkerThread<DoubleInt>
    {
        public:
        template<typename T>
        T task(const T & val) 
        {
            return val *2;  
        }      

    };

}

#endif
