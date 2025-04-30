#include <iostream>
#include <queue>
#include <thread>

namespace pro
{
    template<typename T>
    class Task_Double {
    private:
        std::thread thread;
        std::queue<T> &input_queue_;
        std::queue<T> &double_queue_;
    public:

    Task_Double(std::queue<T> &input_queue, std::queue<T> &double_queue) : 
    input_queue_(input_queue), double_queue_(double_queue)
    {} 
    
    void startThread()
    {
        thread = std::thread(&Task_Double::job,this, std::ref(input_queue_),std::ref(double_queue_));
    }
    void joinThread()
    {
        if(thread.joinable())
            thread.join();
    }



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