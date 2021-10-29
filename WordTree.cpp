#include "WordTree.hpp"

#include <array>
#include <cctype>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

WordTree::WordTree() :
    root(new TreeNode()) {}

void addRecursive(std::shared_ptr<TreeNode> node, std::string word, std::size_t &s)
{
    if (word.length() == 0)
    {
        if(!node->endOfWord)
        {
            s += 1;
            node->endOfWord = true;
        }
        return;
    }

    // otherwise grab next child
    int index = static_cast<int>(std::tolower(word[0])) - 97;
    // if child is null create a new TreeNode for it
    if (node->children[index] == NULL)
    {
        node->children[index] = std::make_shared<TreeNode>();
    }

    addRecursive(node->children[index], word.substr(1, word.length() - 1), s);
}

void WordTree::add(std::string word)
{
    if(word.length() != 0)
        addRecursive(root, word, s);
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
    if (node->children[index] == NULL)
    {
        return NULL;
    }

    return getNodeRecursive(node->children[index], partial.substr(1, partial.length() - 1));
}

std::vector<std::string> breadthFirstSearch(std::shared_ptr<TreeNode> node, std::string partial, std::uint8_t howMany)
{
    std::queue<std::pair<std::shared_ptr<TreeNode>, std::string>> fifo;

    std::vector<std::string> words;
    if (partial == "" || node == NULL)
        return words;
    // Add the children of the prefix node
    for (size_t i = 0; i < node->children.size(); i++)
    {
        std::shared_ptr<TreeNode> child = node->children[i];
        if (child != NULL)
        {
            fifo.push(std::make_pair(child, partial + static_cast<char>(i + 97)));
        }
    }

    while (fifo.size() > 0 && words.size() < howMany)
    {
        std::pair<std::shared_ptr<TreeNode>, std::string> current = fifo.front();
        fifo.pop();
        // add all children if they exist
        for (size_t i = 0; i < std::get<0>(current)->children.size(); i++)
        {
            std::shared_ptr<TreeNode> child = std::get<0>(current)->children[i];
            if (child != NULL)
            {
                fifo.push(std::make_pair(child, std::get<1>(current) + static_cast<char>(i + 97)));
            }
        }
        // add this word if it is one
        if (std::get<0>(current)->endOfWord)
        {
            words.push_back(std::get<1>(current));
        }
    }
    return words;
}

std::vector<std::string> WordTree::predict(std::string partial, std::uint8_t howMany)
{
    // navigate to the end of the partial
    std::shared_ptr node = getNodeRecursive(root, partial);
    // breadth first search
    return breadthFirstSearch(node, partial, howMany);
    // create queue
    // add all current children to it
    // empty queue
    // search condition
    // return the top howMany results of breadth first
}

std::size_t WordTree::size()
{
    return s;
}
