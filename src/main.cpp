#include <iostream>
#include <thread>
#include <queue>


void interact(std::queue<int>& inputQueue, std::queue<int>& doubleQueue) 
{
    while (true) {
        if (!doubleQueue.empty()) 
        {
            int data = doubleQueue.front();
            doubleQueue.pop();
            std::cout << data << std::endl;
        } else 
        {
            int in ;
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

void doubleInt(std::queue<int>& inputQueue, std::queue<int>& doubleQueue ) {
    while (true) {
        if (!inputQueue.empty()) {
            int in = inputQueue.front();
            inputQueue.pop();
            if (doubleQueue.empty())
                doubleQueue.push(in*2);
            if (in == 0)
                break;            
        }
    }
}

int main() {
    std::queue<int> input_queue;
    std::queue<int> double_queue;

    std::thread interactThread(interact, std::ref(input_queue),std::ref(double_queue));
    std::thread doubleThread(doubleInt, std::ref(input_queue),std::ref(double_queue));

    interactThread.join();
    doubleThread.join();
    return 0;
}