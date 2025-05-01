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