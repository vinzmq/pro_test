
#include "../inc/DoubleInt.h"
#include "../inc/TerminalInputOuput.h"
#include "../inc/TwoThreadsHandler.h"
#include "../inc/ReverseString.h"


int main() {

   
    TwoThreadsHandler<int, pro::TerminalInputOutput, pro::DoubleInt> show;
    //TwoThreadsHandler<std::string, pro::TerminalInputOutput, pro::ReverseString> show;
    show.runTasks();
    return 0;
}