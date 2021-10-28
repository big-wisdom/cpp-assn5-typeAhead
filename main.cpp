#include "WordTree.hpp"
#include "rlutil.h"
#include <iostream>
#include <utility>
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
    // clear console
    rlutil::cls();
    auto cursor = std::make_pair(1, 1);

    // wait for input 
    while(true)
    {
        int i = rlutil::getkey();
        if(i == rlutil::KEY_BACKSPACE) 
        {
            std::get<0>(cursor) -= 1;
            rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
            rlutil::setChar(' ');
        }
        else if(i == 10)
        {
            continue;
        }
        else
        {
            char c = static_cast<char>(i);
            std::cout << c;
            std::get<0>(cursor) += 1; // increment x?
        }
    }
    return 0;
}
