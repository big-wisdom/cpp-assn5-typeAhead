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
    if (word.length() == 0)
    {
        node->endOfWord = true;
        return;
    }

    // otherwise grab next child
    int index = static_cast<int>(std::tolower(word[0])) - 97;
    // if child is null create a new TreeNode for it
    if (node->children[index] == NULL)
    {
        node->children[index] = std::make_shared<TreeNode>();
    }

    addRecursive(node->children[index], word.substr(1, word.length() - 1));
}

void WordTree::add(std::string word)
{
    addRecursive(root, word);
}

bool findRecursive(std::shared_ptr<TreeNode> node, std::string word)
{
    if (word.length() == 0) // end of word reached
    {
        return node->endOfWord;
    }

    // otherwise grab next child
    int index = static_cast<int>(std::tolower(word[0])) - 97;
    // if child is null create a new TreeNode for it
    if (node->children[index] == NULL)
    {
        return false;
    }

    return findRecursive(node->children[index], word.substr(1, word.length() - 1));
}

bool WordTree::find(std::string word)
{
    return findRecursive(root, word);
}

void breadthFirstSearch()
{
    std::cout << "bfs" << std::endl;
}

std::shared_ptr<TreeNode> getNodeRecursive(std::shared_ptr<TreeNode> node, std::string partial)
{
    if (partial.length() == 0)
        return node;

    // otherwise grab next child
    int index = static_cast<int>(std::tolower(partial[0])) - 97;
    // if child is null create a new TreeNode for it
    if (node->children[index] == NULL)
    {
        return NULL;
    }

    return getNodeRecursive(node->children[index], partial.substr(1, partial.length() - 1));
}

std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    // navigate to the end of the partial
    std::shared_ptr node = getNodeRecursive(root, partial);
    // breadth first search
    // create queue
    // add all current children to it
    // empty queue
    // search condition
    // return the top howMany results of breadth first
    std::vector<std::string> prediction;
    return prediction;
}
std::size_t WordTree::size()
{
    std::size_t temp = 8;
    return temp;
}
