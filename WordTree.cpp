#include "WordTree.hpp"
#include <queue>
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

void breadthFirstSearch(std::shared_ptr<TreeNode> node)
{
    std::queue<std::shared_ptr<TreeNode>> fifo;
    fifo.push(node);

    std::vector<std::string> words;

    while(fifo.size() > 0)
    {
        std::cout << "Fifo Size before pop: " << fifo.size() << std::endl;
        std::shared_ptr<TreeNode> current = fifo.front();
        fifo.pop();
        std::cout << "Fifo Size after pop: " << fifo.size() << std::endl;
        // add all children if they exist
        for(std::shared_ptr<TreeNode> child : current->children) 
        {
            if(child != NULL)
            {
                fifo.push(child); 
                std::cout << "not null" << std::endl;
            }
        }
        // add this word if it is one
        if(current->endOfWord) std::cout << "end of word" << std::endl;
    }
}

std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    // navigate to the end of the partial
    std::shared_ptr node = getNodeRecursive(root, partial);
    // breadth first search
    breadthFirstSearch(node);
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
