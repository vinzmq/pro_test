#ifndef REVERSESTRIG_H
#define REVERSESTRIG_H

#include "DataProcessor.h"

#include <algorithm>
#include <string>
#include <type_traits>



namespace pro
{   
    template<typename T, typename = std::enable_if_t<std::is_same_v<std::string, std::decay_t<T>>>>
    class ReverseString : public DataProcessor<T>
    {
        public:          
            T processData(const T & val) override
            {
                T reversedStr = val; // Create a copy
                std::reverse(reversedStr.begin(), reversedStr.end());
                return reversedStr;
            }      

    };

}

#endif
