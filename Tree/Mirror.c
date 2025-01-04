#include <stdio.h>
#include <stdlib.h>

/*
The mirror of a binary tree is another binary tree in which the left and right
children of all nodes are swapped.
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


void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}


void mirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }


    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;


    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    printf("In-order traversal of the original tree:\n");
    inOrderTraversal(root);
    printf("\n");

    mirrorTree(root);

    printf("In-order traversal of the mirrored tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
