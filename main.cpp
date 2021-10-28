#include "WordTree.hpp"
#include "rlutil.h"

#include <iostream>
#include <utility>
//#include <string>

void showPredictions(std::pair<int, int> cursor, WordTree wt, std::string partial)
{
    // move cursor to where we start words
    rlutil::locate(1, 2);
    // clear previous words
    for (int i = 0; i < 20; i++)
    {
        std::cout << std::string(20, ' ') << std::endl;
    }
    rlutil::locate(1, 2); // put it back
    // print words
    for (std::string word : wt.predict(partial, 8))
    {
        std::cout << word << std::endl;
    }
    // move cursor back
    rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
}

int main()
{
    // create WordTree
    WordTree wt;
    // add a word
    wt.add("EliRules");
    wt.add("element");
    rlutil::cls();                      // Clear screen
    auto cursor = std::make_pair(1, 1); // CURSOR
    std::string partial = "";

    // wait for input
    while (true)
    {
        int i = rlutil::getkey();
        if (i == rlutil::KEY_BACKSPACE)
        {
            std::get<0>(cursor) -= 1;
            rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
            rlutil::setChar(' ');
            partial = partial.substr(0, partial.length() - 1);
        }
        else if (i == 10)
        {
            continue;
        }
        else
        {
            char c = static_cast<char>(i);
            std::cout << c;
            partial += c;
            std::get<0>(cursor) += 1; // increment x?
        }
        showPredictions(cursor, wt, partial);
    }
    return 0;
}
