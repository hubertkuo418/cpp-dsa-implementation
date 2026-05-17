#include "bst.h"
#include <iostream>
using namespace std;

BST::BST() {
    root = nullptr;
}

// destructor（避免 memory leak）
BST::~BST() {
    destroy(root);
}

void BST::destroy(TreeNode* node) {
    if (node == nullptr) return;

    destroy(node->left);
    destroy(node->right);
    delete node;
}

TreeNode* BST::insertRec(TreeNode* node, int x) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode();
        newNode->data = x;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (x < node->data)
        node->left = insertRec(node->left, x);
    else
        node->right = insertRec(node->right, x);

    return node;
}

void BST::insert(int x) {
    root = insertRec(root, x);
}



TreeNode* BST::searchRec(TreeNode* node, int x) {
    if (node == nullptr || node->data == x)
        return node;

    if (x < node->data)
        return searchRec(node->left, x);
    else
        return searchRec(node->right, x);
}

bool BST::search(int x) {
    return searchRec(root, x) != nullptr;
}


void BST::preorderRec(TreeNode* node) {
    if (node == nullptr) return;

    std::cout << node->data << " ";
    preorderRec(node->left);
    preorderRec(node->right);
}

void BST::preorder() {
    preorderRec(root);
    std::cout << std::endl;
}

void BST::inorderRec(TreeNode* node) {
    if (!node) return;

    inorderRec(node->left);
    cout << node->data << " ";
    inorderRec(node->right);
}

void BST::inorder() {
    inorderRec(root);
    cout << endl;
}

void BST::postorderRec(TreeNode* node) {
    if (node == nullptr) return;

    postorderRec(node->left);
    postorderRec(node->right);
    std::cout << node->data << " ";
}

void BST::postorder() {
    postorderRec(root);
    std::cout << std::endl;
}