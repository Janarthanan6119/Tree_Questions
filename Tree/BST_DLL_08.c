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
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}


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


struct TreeNode* prevNode = NULL;


void convertToDLL(struct TreeNode* root, struct TreeNode** head) {
    if (root == NULL) {
        return;
    }


    convertToDLL(root->left, head);


    if (prevNode == NULL) {

        *head = root;
    } else {

        root->left = prevNode;
        prevNode->right = root;
    }
    prevNode = root;


    convertToDLL(root->right, head);
}

// Function to print the doubly linked list
void printDLL(struct TreeNode* head) {
    printf("Doubly Linked List:\n");
    struct TreeNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    struct TreeNode* head = NULL;
    convertToDLL(root, &head);

    printDLL(head);

    return 0;
}
