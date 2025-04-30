
#include "../inc/Task_InputOuput.h"
#include "../inc/Task_Double.h"
#include "../inc/MainLogik.h"




int main() {

    MainLogik<int, pro::Task_InputOutput<int>, pro::Task_Double<int>> show;
    show.runTasks();
    return 0;
}