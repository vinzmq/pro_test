
#include "../inc/Task_InputOuput.h"
#include "../inc/Task_Double.h"
#include "../inc/MainLogik.h"




int main() {

    MainLogik<int, pro::Task_InputOutput, pro::Task_Double> show;
    show.runTasks();
    return 0;
}