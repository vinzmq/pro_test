#include "queue"
#include <tuple>
#include <thread>

template <typename T, typename... Args>
class MainLogik {
public:
    MainLogik() : tasks(std::make_tuple(Args(input_queue, double_queue)...))
    {
        
    }

    void runTasks()
    {
        std::apply([](auto&... args) {
            // args... is a pack of the elements in the tuple
            (args.startThread() , ...);
        }, tasks);

        std::apply([](auto&... args) {
            // args... is a pack of the elements in the tuple
            (args.joinThread() , ...);
        }, tasks);
    }
 

private:
    std::queue<T> input_queue;
    std::queue<T> double_queue;

    std::tuple<Args...> tasks;


    

};
