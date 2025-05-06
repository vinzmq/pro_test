#ifndef BREAKER_H
#define BREAKER_H

#include <limits>
#include <string>
#include <type_traits>
#include <iostream>


namespace pro
{

    class Breaker 
    {
        public:
        template <typename T>
        bool shouldBreak(const T& value) 
        {
            if constexpr (std::is_same_v<T, int>) 
            {
                return value == 0;
            } 
            else if constexpr (std::is_same_v<T, double>) 
            {
                return value < std::numeric_limits<double>::epsilon();
            } 
            else if constexpr (std::is_same_v<T, std::string>) 
            {
                return value == "stop";
            } 
            else 
            {
                std::cerr << "Warning: No specific break condition for this type." << std::endl;
                return false;
            }
        }
      

    };

}

#endif