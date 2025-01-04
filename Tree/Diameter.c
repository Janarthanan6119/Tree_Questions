#include <stdio.h>
#include <stdlib.h>
/*
The diameter of a binary tree is the length of the longest path between
any two nodes in the tree. This path may or may not pass through the root.
The length is measured by the number of edges between the nodes on the
path.
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


int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int diameter(struct TreeNode* root, int* maxDiameter) {
    if (root == NULL) {
        return 0;
    }


    int leftHeight = diameter(root->left, maxDiameter);
    int rightHeight = diameter(root->right, maxDiameter);


    int currentDiameter = leftHeight + rightHeight;
    if (currentDiameter > *maxDiameter) {
        *maxDiameter = currentDiameter;
    }


    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int findDiameter(struct TreeNode* root) {
    int maxDiameter = 0;
    diameter(root, &maxDiameter);
    return maxDiameter;
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    int treeDiameter = findDiameter(root);
    printf("The diameter of the binary tree is: %d\n", treeDiameter);

    return 0;
}
