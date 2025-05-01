#ifndef MAINLOGIK_H
#define MAINLOGIK_H


#include "queue"
#include <tuple>
#include <thread>

template <typename T, typename... Args>
class MainLogik 
{
public:
    MainLogik() : tasks(std::make_tuple(Args()...)){}

    void runTasks()
    {
        std::apply([&](auto&... args) {            
            (args.startThread(input_queue, double_queue) , ...);
        }, tasks);

        std::apply([](auto&... args) {          
            (args.joinThread() , ...);
        }, tasks);
    }
 

private:
    std::queue<T> input_queue;
    std::queue<T> double_queue;

    std::tuple<Args...> tasks;

};

#endif
