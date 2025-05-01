#ifndef TASK_DOUBLE_H
#define TASK_DOUBLE_H

#include <iostream>
#include <queue>
#include <thread>
#include "Thread.h"

namespace pro
{
    class Task_Double : public Thread<Task_Double>
    {
        public:
                     
        template<typename T>
        void process(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
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