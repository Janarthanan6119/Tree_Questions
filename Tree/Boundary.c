#include <stdio.h>
#include <stdlib.h>

/*
The boundary of a binary tree includes(below order):

Left boundary: Nodes on the left edge, excluding leaf nodes and the root.
Leaf nodes: All leaf nodes in left-to-right order.
Right boundary: Nodes on the right edge, excluding leaf nodes and the root,
printed in reverse order.
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


int isLeaf(struct TreeNode* node) {
    return (node->left == NULL && node->right == NULL);
}


void printLeftBoundary(struct TreeNode* node) {
    while (node != NULL) {
        if (!isLeaf(node)) {
            printf("%d ", node->data);
        }
        node = (node->left != NULL) ? node->left : node->right;
    }
}


void printLeaves(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printLeaves(node->left);
    if (isLeaf(node)) {
        printf("%d ", node->data);
    }
    printLeaves(node->right);
}


void printRightBoundary(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }
    if (!isLeaf(node)) {
        if (node->right != NULL) {
            printRightBoundary(node->right);
        } else if (node->left != NULL) {
            printRightBoundary(node->left);
        }
        printf("%d ", node->data);
    }
}

void printBoundary(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Print the root node
    printf("%d ", root->data);

    // print the left boundary (excluding root and leaves)
    if (root->left != NULL) {
        printLeftBoundary(root->left);
    }

    // print all the leaf nodes
    printLeaves(root);

    // print right boundary nodes (excluding root and leaves)
    if (root->right != NULL) {
        printRightBoundary(root->right);
    }
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    printf("Boundary nodes of the binary tree are:\n");
    printBoundary(root);

    return 0;
}
