#include <stdio.h>
#include <stdlib.h>
/*
Floor: The largest value in the BST that is less than or equal to the given key.
Ceiling: The smallest value in the BST that is greater than or equal to the given key.
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


struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}


int findFloor(struct TreeNode* root, int key) {
    int floor = -1;
    while (root != NULL) {
        if (root->data == key) {
            return root->data;
        } else if (key > root->data) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}


int findCeiling(struct TreeNode* root, int key) {
    int ceiling = -1;
    while (root != NULL) {
        if (root->data == key) {
            return root->data;
        } else if (key < root->data) {
            ceiling = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceiling;
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
    int n, key;


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


    printf("Enter the key to find the floor and ceiling: ");
    scanf("%d", &key);


    int floor = findFloor(root, key);
    int ceiling = findCeiling(root, key);

    if (floor == -1) {
        printf("No floor exists for %d in the BST.\n", key);
    } else {
        printf("Floor of %d is: %d\n", key, floor);
    }

    if (ceiling == -1) {
        printf("No ceiling exists for %d in the BST.\n", key);
    } else {
        printf("Ceiling of %d is: %d\n", key, ceiling);
    }

    return 0;
}
