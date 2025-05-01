#include <QCoreApplication>
#include "../inc/InputOuputThread.h"
#include "../inc/DoubleInt.h"
#include "../inc/MainLogik.h"
#include "../inc/ReverseString.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainLogik<int, pro::InputOutputThread, pro::DoubleInt> show;
    show.runTasks();

    return a.exec();
}
