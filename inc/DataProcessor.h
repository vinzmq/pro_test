#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H


namespace pro
{
    template<typename Derived>
    class DataProcessor {
        public:
        template<typename T>
        T processData(const T &val)
        {
           return static_cast<Derived*>(this)->task(val);
        }     
    };

}

#endif
