#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
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
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int leftLeafCount = countLeafNodes(root->left);
    int rightLeafCount = countLeafNodes(root->right);

    return leftLeafCount + rightLeafCount;
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();
    int leafNodeCount = countLeafNodes(root);
    printf("The total number of leaf nodes in the binary tree is: %d\n", leafNodeCount);
    return 0;
}

