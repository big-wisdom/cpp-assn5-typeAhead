#include <iostream>
#include "WordTree.hpp"
//#include <string>

void printOut(std::string message)
{
    std::cout << message << std::endl;
}

int main() {
    // create WordTree
    WordTree wt;
    // add a word
    wt.add("Eli");
    return 0;
}
