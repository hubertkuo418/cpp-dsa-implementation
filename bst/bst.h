#ifndef BST_H
#define BST_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, int x);
    TreeNode* searchRec(TreeNode* node, int x);

    void inorderRec(TreeNode* node);
    void preorderRec(TreeNode* node);
    void postorderRec(TreeNode* node);

    void destroy(TreeNode* node);

public:
    BST();
    ~BST();

    void insert(int x);
    bool search(int x);

    void inorder();
    void preorder();
    void postorder();
};

#endif