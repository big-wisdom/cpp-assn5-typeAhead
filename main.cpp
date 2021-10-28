#include "WordTree.hpp"

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
    return 0;
}
