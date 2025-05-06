#ifndef TERMINALINPUTOUTPUT_H
#define TERMINALINPUTOUTPUT_H

#include "IOProcessor.h"

#include <iostream>



namespace pro
{
    class TerminalInputOutput : public IOProcessor<TerminalInputOutput>
    {
        public:

            template<typename T>
            void write(T val) 
            {
                std::cout << val<< std::endl;  
            }
            template<typename T>
            T read(T)
            {
                T val;
                std::cin >> val;
                return val;
            }

    };

}

#endif
