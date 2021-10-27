#include <iostream>
#include <vector>
#include <array>
#include <memory>

class TreeNode {
    public:
        bool endOfWord;

        std::array<std::shared_ptr<TreeNode>, 26> children;
};

class WordTree {
    public:
        TreeNode root;

        WordTree()
        {
            std::cout << "Initializing WordTree" << std::endl;
        }

        void add(std::string word)
        {
            std::cout << "adding " << word << std::endl;
            // pick out first letter
            std::cout << word[0] << std::endl;
            // check to see if child exists
            // if it doesn't create it
            // recursively call add on it
        }

        bool find(std::string word)
        {
            std::cout << "Finding " << word << std::endl;
            return true;
        }

        std::vector<std::string> predict(std::string partial, std::uint8_t howMany)
        {
            std::vector<std::string> prediction;
            std::cout << "Finding " << partial << " " << howMany << "times" << std::endl;
            return prediction;
        }
        std::size_t size()
        {
            std::size_t temp = 8;
            return temp;
        }
};
