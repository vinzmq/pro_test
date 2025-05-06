#ifndef REVERSESTRIG_H
#define REVERSESTRIG_H

#include "DataProcessor.h"

#include <algorithm>
#include <string>
#include <type_traits>



namespace pro
{   
    class ReverseString : public DataProcessor<ReverseString>
    {
        public:

            template<typename T, typename = std::enable_if_t<std::is_same_v<std::string, std::decay_t<T>>>>
            T task(const T & val) 
            {
                T reversedStr = val; // Create a copy
                std::reverse(reversedStr.begin(), reversedStr.end());
                return reversedStr;
            }      

    };

}

#endif
