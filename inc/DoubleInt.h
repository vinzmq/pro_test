#ifndef DOUBLEINT_H
#define DOUBLEINT_H

#include "DataProcessor.h"

#include <type_traits>

namespace pro
{
    class DoubleInt : public DataProcessor<DoubleInt>
    {
        public:

            template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>        
            T task(const T & val) 
            {
                return val *2;  
            }      

    };

}

#endif
