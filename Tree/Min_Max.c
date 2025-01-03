#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int findMax(struct TreeNode* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return (root->data > leftMax ? (root->data > rightMax ? root->data : rightMax) : (leftMax > rightMax ? leftMax : rightMax));
}


int findMin(struct TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;
    }

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return (root->data < leftMin ? (root->data < rightMin ? root->data : rightMin) : (leftMin < rightMin ? leftMin : rightMin));
}


int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    int maxValue = findMax(root);
    int minValue = findMin(root);

    printf("The maximum value in the binary tree is: %d\n", maxValue);
    printf("The minimum value in the binary tree is: %d\n", minValue);

    return 0;
}
