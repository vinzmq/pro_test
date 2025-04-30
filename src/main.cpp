#include <QCoreApplication>
#include "../inc/Task_InputOuput.h"
#include "../inc/Task_Double.h"
#include "../inc/MainLogik.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainLogik<int, pro::Task_InputOutput<int>, pro::Task_Double<int>> show;
    show.runTasks();

    return a.exec();
}
