#include "lab_bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

bool isBST(Node* curr, Node* min, Node* max){
    if(curr==nullptr) return true;
    if( (min!= nullptr) && (curr->key <= min->key)) return false;
    if( (max != nullptr) && (curr->key >= max->key)) return false;
    return isBST(curr->left, min, curr) && isBST(curr->right, curr, max);
}

//Helper functions?
bool isBST(Node *root) {
    return isBST(root, nullptr, nullptr);
}

int height(Node* root)
{
    if(!root) return 0;
    int l = 1 + height(root->left);
    int r = 1 + height(root->right);
    return l > r ? l : r;
}

//Helper functions?
bool isBalanced(Node *root) {
	if(!root) return true;
    int l = height(root->left);
    int r = height(root->right);
    return ((l + 1 == r) || (l == r) || (l == r + 1)) &&
        isBalanced(root->left) && isBalanced(root->right);
}

