#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node* buildTree() {
    int value;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct Node* node = newNode(value);
    printf("Enter left child of %d:\n", value);
    node->left = buildTree();

    printf("Enter right child of %d:\n", value);
    node->right = buildTree();

    return node;
}


void printPath(int path[], int pathLength) {
    for (int i = 0; i < pathLength; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}


void findPaths(struct Node* root, int sum, int path[], int pathLength) {
    if (root == NULL) {
        return;
    }


    path[pathLength] = root->data;
    pathLength++;


    if (root->left == NULL && root->right == NULL && sum == root->data) {
        printf("Path found: ");
        printPath(path, pathLength);
    }


    findPaths(root->left, sum - root->data, path, pathLength);
    findPaths(root->right, sum - root->data, path, pathLength);
}


void findPathsWithSum(struct Node* root, int sum) {
    int path[1000];
    findPaths(root, sum, path, 0);
}


int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Paths with sum %d:\n", targetSum);
    findPathsWithSum(root, targetSum);

    return 0;
}
