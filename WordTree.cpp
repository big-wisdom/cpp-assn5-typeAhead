#include "WordTree.hpp"

#include <array>
#include <cctype>
#include <iostream>
#include <memory>
#include <vector>

WordTree::WordTree() :
    root(new TreeNode()) {}

void addRecursive(std::shared_ptr<TreeNode> node, std::string word)
{
    // if word is now empty set endOfWord to true
    if (word.length() == 0)
    {
        std::cout << "set endOfWord to true" << std::endl;
    }

    // otherwise grab next child
    int index = static_cast<int>(std::tolower(word[0])) - 97;
    if (node->children[index] == NULL)
    {
        std::cout << "child equals NULL" << std::endl;
        node->children[index] = std::make_shared<TreeNode>();
    }
    std::cout << "node after replacement" << node->children[index] << std::endl;
    // std::cout << "index " << (int)std::tolower(word[0]) - 97 << std::endl;
    // std::shared_ptr<TreeNode> child = node->children[(int)std::tolower(word[0]) - 97];
    //std::cout << child << std::endl;
    //addRecursive(child, word.substr(1,word.length()-1));
    //std::cout << word[0] << std::endl;
}

void WordTree::add(std::string word)
{
    addRecursive(root, word);
}

bool WordTree::find(std::string word)
{
    std::cout << "Finding " << word << std::endl;
    return true;
}

std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    std::vector<std::string> prediction;
    std::cout << "Finding " << partial << " " << howMany << "times" << std::endl;
    return prediction;
}
std::size_t WordTree::size()
{
    std::size_t temp = 8;
    return temp;
}
