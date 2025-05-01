#ifndef TASK_INPUTOUTPUT_H
#define TASK_INPUTOUTPUT_H

#include <iostream>
#include <queue>
#include <thread>



namespace pro
{
    
    class Task_InputOutput 
    {
        private:
            std::thread thread;
        
        public:
       
            Task_InputOutput(){} 
            template<typename T>
            void startThread(std::queue<T> &input_queue, std::queue<T> &double_queue)
            {
                thread = std::thread(&Task_InputOutput::job<T>,this, std::ref(input_queue),std::ref(double_queue));
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