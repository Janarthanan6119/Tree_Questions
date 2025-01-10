#include <stdio.h>
#include <stdlib.h>


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


struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value <= root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}


int currentCount = 0;
int maxCount = 0;
int currentValue = 0;
int mode = 0;


void updateMode(int value) {
    if (value == currentValue) {
        currentCount++;
    } else {
        currentValue = value;
        currentCount = 1;
    }
    if (currentCount > maxCount) {
        maxCount = currentCount;
        mode = currentValue;
    }
}


void findModeInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    findModeInOrder(root->left);

    updateMode(root->data);

    findModeInOrder(root->right);
}


void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int n;

    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    findModeInOrder(root);
    printf("The mode (most frequent value) in the BST is: %d\n", mode);

    return 0;
}
