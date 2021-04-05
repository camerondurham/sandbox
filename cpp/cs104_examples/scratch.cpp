#include <stdlib.h>
#include<memory>
#include<iostream>

class Tree {
 public:
    Tree() : root(nullptr) { std::cout << "tree created" << std::endl; }
    ~Tree() { std::cout << "tree destroyed" << std::endl; }
    bool add(int val);
    void inOrderTraversal() { inOrderTraversal(root); }

 private:
    struct Node {
        int data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        Node(int val) : data(val), left(nullptr), right(nullptr) { std::cout << "tree node created: " << data << std::endl; }
        ~Node() { std::cout << "tree node destroyed: " << data << std::endl; }
    };

    void inOrderTraversal(std::shared_ptr<Node> node);
    std::shared_ptr<Node> insert(int val, std::shared_ptr<Node> subTree);
    std::shared_ptr<Node> root;
};

std::shared_ptr<Tree::Node> Tree::insert(int val, std::shared_ptr<Node> subTree) {
    if (subTree == nullptr) {
        std::shared_ptr<Node> node = std::make_shared<Node>(val);
        return node;
    }

    if (val <= subTree->data) {
        subTree->left = insert(val, subTree->left);
    } else {
        subTree->right = insert(val, subTree->right);
    }
    return nullptr;
}

void Tree::inOrderTraversal(std::shared_ptr<Node> node) {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}
int main()
{

}
