#ifndef IOPROCESSOR_H
#define IOPROCESSOR_H

namespace pro
{
    template<typename Derived>
    class IOProcessor
    {
        public:

            template<typename T>
            void writeData(T val) 
            {
                static_cast<Derived*>(this)->write(val);
            }
            template<typename T>
            T readData(T)
            {
                T val= static_cast<Derived*>(this)->read(T{});
                return val;
            }

    };

}

#endif
