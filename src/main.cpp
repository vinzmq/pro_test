#include <QCoreApplication>
#include "../inc/DoubleInt.h"
#include "../inc/TerminalInputOuput.h"
#include "../inc/TwoThreadsHandler.h"
#include "../inc/ReverseString.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TwoThreadsHandler<int, pro::TerminalInputOutput, pro::DoubleInt> show;
    show.runTasks();

    return a.exec();
}
