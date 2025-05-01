#ifndef THREAD_H
#define THREAD_H

#include <iostream>
#include <queue>
#include <thread>

namespace pro
{
    template<typename Derived>
    class Thread 
    {
        private:
            std::thread thread;

        protected:
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
        public:

        Thread()=default; 
        
       template <typename T>
        void startThread(std::queue<T> &input_queue, std::queue<T> &double_queue)
        {
            thread = std::thread(&Thread::job<T>,this, std::ref(input_queue),std::ref(double_queue));
        }
        void joinThread()
        {
            if(thread.joinable())
                thread.join();
        }    
        
        template <typename T>
        void job(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
        {
            static_cast<Derived*>(this)->process(inputQueue, doubleQueue);
        }
       

    };

}

#endif