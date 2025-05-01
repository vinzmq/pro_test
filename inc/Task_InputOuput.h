#ifndef TASK_INPUTOUTPUT_H
#define TASK_INPUTOUTPUT_H

#include <iostream>
#include <queue>
#include <thread>
#include "Thread.h"



namespace pro
{
    
    class Task_InputOutput : public Thread<Task_InputOutput>
    {

        public:
            template<typename T>
            void process(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
            {
                while (true) {
                    if (!doubleQueue.empty()) 
                    {
                        T data = doubleQueue.front();
                        doubleQueue.pop();
                        std::cout << data << std::endl;
                    } else 
                    {
                        T in ;
                        std::cin >> in;
                        inputQueue.push(in);
                    
                        // wait until DoubleThread fills the queue
                        while(doubleQueue.empty())
                        {}
                        // finish work condition
                        if (in == 0)
                            break;
                    }
                }
            }
    };

}

#endif