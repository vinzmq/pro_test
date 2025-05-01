#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <iostream>
#include <queue>
#include <thread>

#include "Thread.h"

namespace pro
{
    template<typename Derived>
    class WorkerThread : public Thread<WorkerThread<Derived>>
    {
        public:
        template <typename T>
        T action(const T &val)
        {
           return static_cast<Derived*>(this)->task(val);
        }

        template<typename T>
        void process(std::queue<T>& inputQueue, std::queue<T>& doubleQueue)
        {
            while (true) {
                if (!inputQueue.empty()) {
                    T in = inputQueue.front();
                    inputQueue.pop();
                    if (doubleQueue.empty())
                        doubleQueue.push(this->action(in));
                    if (this->shouldBreak(in))
                        break;            
                }
            }
        }

    };

}

#endif
