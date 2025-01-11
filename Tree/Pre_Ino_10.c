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


int findIndex(int* arr, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


struct Node* buildTree(int* preorder, int* inorder, int start, int end, int* preorderIndex) {
    if (start > end) {
        return NULL;
    }


    int current = preorder[*preorderIndex];
    (*preorderIndex)++;
    struct Node* node = newNode(current);


    if (start == end) {
        return node;
    }


    int inorderIndex = findIndex(inorder, start, end, current);


    node->left = buildTree(preorder, inorder, start, inorderIndex - 1, preorderIndex);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, end, preorderIndex);

    return node;
}


void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}


int getInput(int* arr) {
    int count = 0;
    printf("Enter numbers (enter -1 to stop):\n");
    while (1) {
        int value;
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        arr[count++] = value;
    }
    return count;
}


int main() {
    int preorder[100], inorder[100];

    printf("Enter preorder traversal:\n");
    int preorderSize = getInput(preorder);

    printf("Enter inorder traversal:\n");
    int inorderSize = getInput(inorder);

    if (preorderSize != inorderSize) {
        printf("Error: Preorder and inorder arrays must have the same size.\n");
        return 1;
    }

    int preorderIndex = 0;


    struct Node* root = buildTree(preorder, inorder, 0, inorderSize - 1, &preorderIndex);


    printf("Inorder traversal of the constructed tree:\n");
    printInorder(root);
    printf("\n");

    return 0;
}

