#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
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

// Find the inorder predecessor
struct TreeNode* findPredecessor(struct TreeNode* node) {
    struct TreeNode* current = node->left;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Find the inorder successor
struct TreeNode* findSuccessor(struct TreeNode* node) {
    struct TreeNode* current = node->right;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Find the predecessor and successor for a given key
void findPredecessorAndSuccessor(struct TreeNode* root, int key, struct TreeNode** predecessor, struct TreeNode** successor) {
    if (root == NULL) {
        return;
    }

    if (root->data == key) {
        if (root->left != NULL) {
            *predecessor = findPredecessor(root);
        }
        if (root->right != NULL) {
            *successor = findSuccessor(root);
        }
    } else if (key < root->data) {
        *successor = root; // This node might be the successor
        findPredecessorAndSuccessor(root->left, key, predecessor, successor);
    } else {
        *predecessor = root; // This node might be the predecessor
        findPredecessorAndSuccessor(root->right, key, predecessor, successor);
    }
}

// Build the BST from user input
struct TreeNode* buildTree() {
    struct TreeNode* root = NULL;
    int n, value;

    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    printf("Enter the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    return root;
}

int main() {
    struct TreeNode* root = buildTree();

    int key;
    printf("Enter the key to find the predecessor and successor: ");
    scanf("%d", &key);

    struct TreeNode* predecessor = NULL;
    struct TreeNode* successor = NULL;

    findPredecessorAndSuccessor(root, key, &predecessor, &successor);

    if (predecessor != NULL) {
        printf("Predecessor of %d is: %d\n", key, predecessor->data);
    } else {
        printf("No predecessor found for %d.\n", key);
    }

    if (successor != NULL) {
        printf("Successor of %d is: %d\n", key, successor->data);
    } else {
        printf("No successor found for %d.\n", key);
    }

    return 0;
}
