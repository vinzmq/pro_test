#ifndef TWOTHRAEDSHANDLER_H
#define TWOTHRAEDSHANDLER_H


#include "DataProcessor.h"
#include "IOProcessor.h"
#include "Breaker.h"

#include "queue"
#include <tuple>
#include <thread>


template <typename T, typename Task1, typename Task2, typename = std::enable_if_t<std::is_base_of_v<pro::IOProcessor<Task1>, Task1> &&
std::is_base_of_v<pro::DataProcessor<Task2>, Task2>>>
class TwoThreadsHandler 
{
public:
    TwoThreadsHandler(){}

    void runTasks()
    {
        thread1 = std::thread(&TwoThreadsHandler::process_thread_1,this, std::ref(input_queue),std::ref(double_queue));
        thread2 = std::thread(&TwoThreadsHandler::process_thread_2,this, std::ref(input_queue),std::ref(double_queue));
        if(thread1.joinable())
                thread1.join();
        if(thread2.joinable())
                thread2.join();
    }

    void process_thread_1(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
    {
        while (true) {
            if (!doubleQueue.empty()) 
            {
                T data = doubleQueue.front();
                doubleQueue.pop();
                task1.writeData(data);
            } else 
            {
                T in = task1.readData(T{});
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

    void process_thread_2(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
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
    pro::IOProcessor<Task1> task1;
    pro::DataProcessor<Task2> task2;

    pro::Breaker breaker;
    std::thread thread1;
    std::thread thread2;

    std::queue<T> input_queue;
    std::queue<T> double_queue;

    

   
};

#endif
