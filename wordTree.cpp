#include <iostream>

void add(std::string word)
{
    std::cout << "adding " << word << std::endl;
}

bool find(std::string word);
std::vector<std::string> predict(std::string partial, std::uint8_t howMany);
std::size_t size();
