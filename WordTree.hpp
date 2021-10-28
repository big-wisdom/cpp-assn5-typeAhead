#include <iostream>
#include <vector>
#include <array>
#include <memory>

class TreeNode {
    public:
        TreeNode(){std::cout << "Initializing TreeNode" << std::endl;}
        bool endOfWord;
        std::array<std::shared_ptr<TreeNode>, 26> children;
};

class WordTree {
    public:
        std::shared_ptr<TreeNode> root;

        void add(std::string word);
        bool find(std::string word);
        std::vector<std::string> predict(std::string partial, std::uint8_t howMany);
        std::size_t size();
};
