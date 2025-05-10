#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "IOProcessor.h"

#include <iostream>
#include <fstream>



namespace pro
{
    template<typename T>
    class FileWriter : public IOProcessor<T>
    {
        
        std::ofstream filetowrite;
        std::ifstream filetoread;
        public:

        FileWriter(std::string s_r,std::string s_w) : filetoread(s_r),filetowrite(s_w){}
           
            void write(T val) override
            {
                filetowrite << val<< std::endl;  
            }

            T read(T) override
            {
                T val;
                if(getline (filetoread, val))
                    return val;
                else
                 return "stop";
            }

    };

}

#endif
