#ifndef MAINLOGIK_H
#define MAINLOGIK_H


#include "queue"
#include <tuple>
#include <thread>

template <typename T, typename... Args>
class MainLogik 
{
public:
    MainLogik() : tasks(std::make_tuple(Args(input_queue, double_queue)...)){}

    void runTasks()
    {
        std::apply([](auto&... args) {            
            (args.startThread() , ...);
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
