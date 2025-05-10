#ifndef IOPROCESSOR_H
#define IOPROCESSOR_H

namespace pro
{
    template<typename T>
    class IOProcessor
    {
        public:            
            virtual void write(T val) = 0;
            virtual T read(T) = 0;

    };

}

#endif
