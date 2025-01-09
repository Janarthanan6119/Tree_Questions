#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


int Chk(struct TreeNode* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }


    if (root->data <= min || root->data >= max) {
        return 0;
    }


    return Chk(root->left, min, root->data) &&
           Chk(root->right, root->data, max);
}

int isBST(struct TreeNode* root) {
    return Chk(root, INT_MIN, INT_MAX);
}

int main() {
     struct TreeNode* root = NULL;
     int data;

    printf("Enter data (-1 to stop): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = insert(root, data);
    }

    if (isBST(root)) {
        printf("The binary tree is a Binary Search Tree.\n");
    } else {
        printf("The binary tree is NOT a Binary Search Tree.\n");
    }

    return 0;
}
