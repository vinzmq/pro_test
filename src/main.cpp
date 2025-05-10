#include "../inc/FileWriter.h"
#include "../inc/DoubleInt.h"
#include "../inc/TerminalInputOuput.h"
#include "../inc/TwoThreadsHandler.h"
#include "../inc/ReverseString.h"


int main() {

   // auto a = pro::FileWriter<std::string>{"Test.txt", "Test2.txt"};
   // auto b = pro::ReverseString<std::string>{};
   //
   // TwoThreadsHandler<std::string> show(a,b);

    auto c = pro::TerminalInputOutput<int>{};
    auto d = pro::DoubleInt<int>{};
    TwoThreadsHandler<int> show2(c,d);
    //TwoThreadsHandler<std::string, pro::TerminalInputOutput, pro::ReverseString> show;
    //show.runTasks();
    return 0;
}