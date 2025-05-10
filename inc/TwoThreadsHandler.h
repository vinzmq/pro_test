#ifndef TWOTHRAEDSHANDLER_H
#define TWOTHRAEDSHANDLER_H


#include "DataProcessor.h"
#include "IOProcessor.h"
#include "Breaker.h"

#include "queue"
#include <tuple>
#include <thread>


template <typename T>

class TwoThreadsHandler 
{
public:

    template<typename Task1 = pro::IOProcessor<T>, typename Task2 = pro::DataProcessor<T>>
    TwoThreadsHandler(Task1 &v1 = pro::IOProcessor<T>{}, Task2 &v2 = pro::DataProcessor<T>{})
    {
        runTasks(v1, v2);
    }

    template<typename Task1, typename Task2>
    void runTasks( Task1 &t,  Task2 &t2)
    {
        thread1 = std::thread(&TwoThreadsHandler::process_thread_1<Task1>,this, std::ref(input_queue),std::ref(double_queue), std::ref(t));
        thread2 = std::thread(&TwoThreadsHandler::process_thread_2<Task2>,this, std::ref(input_queue),std::ref(double_queue), std::ref(t2));
        if(thread1.joinable())
                thread1.join();
        if(thread2.joinable())
                thread2.join();
    }

    template<typename Task1>
    void process_thread_1(std::queue<T>& inputQueue, std::queue<T>& doubleQueue, Task1 &task1)
    {
        while (true) {
            if (!doubleQueue.empty()) 
            {
                T data = doubleQueue.front();
                doubleQueue.pop();
                task1.write(data);
            } else 
            {
                T in = task1.read(T{});
                inputQueue.push(in);
            
                // wait until DoubleThread fills the queue
                while(doubleQueue.empty())
                {}
                // finish work condition
                if (breaker.shouldBreak(in))
                    break;
            }
        }
    }

    template<typename Task2>
    void process_thread_2(std::queue<T>& inputQueue, std::queue<T>& doubleQueue,  Task2 &task2)
    {
        while (true) {
            if (!inputQueue.empty()) {
                T in = inputQueue.front();
                inputQueue.pop();
                if (doubleQueue.empty())
                    doubleQueue.push(task2.processData(in));
                if (breaker.shouldBreak(in))
                    break;            
            }
        }
    }
 

private:
    pro::Breaker breaker;
    std::thread thread1;
    std::thread thread2;

    std::queue<T> input_queue;
    std::queue<T> double_queue;

    

   
};

#endif
