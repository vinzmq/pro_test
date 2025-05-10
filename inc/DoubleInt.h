#ifndef DOUBLEINT_H
#define DOUBLEINT_H

#include "DataProcessor.h"

#include <type_traits>

namespace pro
{
    template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    class DoubleInt : public DataProcessor<T>
    {
        T m_v = 0;

        public:
        DoubleInt(T s) : m_v(s){};
        DoubleInt(){};
                 
            T processData(const T & val)  override
            {
                return val *2 + m_v;  
            }      

    };

}

#endif
