#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H


namespace pro
{
    template<typename T>
    class DataProcessor {
        public:
        
        virtual T processData(const T &val)=0;
  
    };

}

#endif
