#include "WordTree.hpp"
#include "rlutil.h"
#include <iostream>
//#include <string>

void printOut(std::string message)
{
    std::cout << message << std::endl;
}

int main()
{
    // create WordTree
    WordTree wt;
    // add a word
    wt.add("EliRules");
    wt.predict("Eli", 8);
    // clear console
    rlutil::cls();

    // wait for input 
    char c = static_cast<char>(rlutil::getkey());
    std::cout << c << std::endl;
    return 0;
}
