#ifndef TERMINALINPUTOUTPUT_H
#define TERMINALINPUTOUTPUT_H

#include "IOProcessor.h"

#include <iostream>



namespace pro
{
    template<typename T>
    class TerminalInputOutput : public IOProcessor<T>
    {
        public:

           
            void write(T val) override
            {
                std::cout << val<< std::endl;  
            }

            T read(T) override
            {
                T val;
                std::cin >> val;
                return val;
            }

    };

}

#endif
