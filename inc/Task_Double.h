#ifndef TASK_DOUBLE_H
#define TASK_DOUBLE_H

#include <iostream>
#include <queue>
#include <thread>

namespace pro
{
    class Task_Double 
    {
        private:
            std::thread thread;
            public:

        Task_Double(){} 
        
        template<typename T>
        void startThread(std::queue<T> &input_queue, std::queue<T> &double_queue)
        {
            thread = std::thread(&Task_Double::job<T>,this, std::ref(input_queue),std::ref(double_queue));
        }
        void joinThread()
        {
            if(thread.joinable())
                thread.join();
        }
        template<typename T>
        void job(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
        {
            while (true) {
                if (!inputQueue.empty()) {
                    T in = inputQueue.front();
                    inputQueue.pop();
                    if (doubleQueue.empty())
                        doubleQueue.push(in*2);
                    if (in == 0)
                        break;            
                }
            }
        }

    };

}

#endif