#include <iostream>
#include <queue>
#include <thread>



namespace pro
{
    template<typename T>
    class Task_InputOutput 
    {
        private:
            std::thread thread;
            std::queue<T> &input_queue_;
            std::queue<T> &double_queue_;
    public:
        
        Task_InputOutput(std::queue<T> &input_queue, std::queue<T> &double_queue) : 
                                input_queue_(input_queue), double_queue_(double_queue)
        {} 

        void startThread()
        {
            thread = std::thread(&Task_InputOutput::job,this, std::ref(input_queue_),std::ref(double_queue_));
        }
        void joinThread()
        {
            if(thread.joinable())
                thread.join();
        }

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