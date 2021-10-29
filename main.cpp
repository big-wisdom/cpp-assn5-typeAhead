#include "WordTree.hpp"
#include "rlutil.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>
#include <utility>
//#include <string>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

void showPredictions(std::pair<int, int> cursor, std::shared_ptr<WordTree> wt, std::string partial, std::uint8_t howMany)
{
    // move cursor to where we start words
    rlutil::locate(1, 2);
    // clear previous words
    for (int i = 0; i < 20; i++)
    {
        std::cout << std::string(40, ' ') << std::endl;
    }
    rlutil::locate(1, 2); // put it back
    // print words
    if(partial.length() > 0)
    {
        for (std::string word : wt->predict(*split(partial, ' ').rbegin(), howMany))
        {
            std::cout << word << std::endl;
        }
    }
    // move cursor back
    rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
}

void debug(std::string partial, std::pair<int, int> cursor)
{
    // move cursor down to debug area
    rlutil::locate(1, 15);
    // print stuff
    std::cout << "partial: " << partial << std::endl;
    std::cout << "cursor: " << std::get<0>(cursor) << ", " << std::get<1>(cursor) << std::endl;
    // move it back
    rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
}


std::shared_ptr<WordTree> readDictionary(std::string filename)
{
    auto wordTree = std::make_shared<WordTree>();
    std::ifstream inFile = std::ifstream(filename, std::ios::in);
    while (!inFile.eof())
    {
        std::string word;
        std::getline(inFile, word);
        // Need to consume the carriage return character for some systems, if it exists
        if (!word.empty() && word[word.size() - 1] == '\r')
        {
            word.erase(word.end() - 1);
        }
        // Keep only if everything is an alphabetic character -- Have to send isalpha an unsigned char or
        // it will throw exception on negative values; e.g., characters with accent marks.
        if (std::all_of(word.begin(), word.end(), [](unsigned char c) { return std::isalpha(c); }))
        {
            std::transform(word.begin(), word.end(), word.begin(), [](char c) { return static_cast<char>(std::tolower(c)); });
            wordTree->add(word);
        }
    }

    return wordTree;
}


int main()
{
    // create WordTree
    auto wt = readDictionary("dictionary.txt");
    rlutil::cls();                      // Clear screen
    auto cursor = std::make_pair(1, 1); // CURSOR
    std::string partial = "";
    // wait for input
    while (true)
    {
        int i = rlutil::getkey();
        if (i == rlutil::KEY_BACKSPACE)
        {
            if (partial.length() > 0)
            {
                std::get<0>(cursor) -= 1;
                rlutil::locate(std::get<0>(cursor), std::get<1>(cursor));
                rlutil::setChar(' ');
                partial = partial.substr(0, partial.length() - 1);
            }
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
        showPredictions(cursor, wt, partial, static_cast<std::uint8_t>(9));
        // debug(partial, cursor);
    }
    return 0;
}
