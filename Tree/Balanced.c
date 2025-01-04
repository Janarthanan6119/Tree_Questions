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


int isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return 1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);


    if (abs(leftHeight - rightHeight) > 1) {
        return 0;
    }


    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    if (isBalanced(root)) {
        printf("The binary tree is balanced.\n");
    } else {
        printf("The binary tree is not balanced.\n");
    }

    return 0;
}
