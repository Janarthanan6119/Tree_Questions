#include <stdio.h>
#include <stdlib.h>

/*
A binary tree is symmetric if the left subtree is a mirror reflection of the
right subtree. This means:
The root nodes of both subtrees are the same.
The left subtree of the left tree is the mirror of the right subtree of the
right tree, and vice versa.
*/
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct TreeNode* buildTree() {
    int value;
    printf("Enter the value of the node (-1 for NULL): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct TreeNode* root = createNode(value);

    printf("Enter the left child of %d:\n", value);
    root->left = buildTree();

    printf("Enter the right child of %d:\n", value);
    root->right = buildTree();

    return root;
}


int isMirror(struct TreeNode* tree1, struct TreeNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }

    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }


    return (tree1->data == tree2->data) &&
           isMirror(tree1->left, tree2->right) &&
           isMirror(tree1->right, tree2->left);
}


int isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return 1;
    }


    return isMirror(root->left, root->right);
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    if (isSymmetric(root)) {
        printf("The binary tree is symmetric.\n");
    } else {
        printf("The binary tree is not symmetric.\n");
    }

    return 0;
}
