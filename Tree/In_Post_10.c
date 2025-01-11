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


struct Node* buildTree(int* inorder, int* postorder, int start, int end, int* postorderIndex) {
    if (start > end) {
        return NULL;
    }


    int current = postorder[*postorderIndex];
    (*postorderIndex)--;
    struct Node* node = newNode(current);


    if (start == end) {
        return node;
    }


    int inorderIndex = findIndex(inorder, start, end, current);


    node->right = buildTree(inorder, postorder, inorderIndex + 1, end, postorderIndex);
    node->left = buildTree(inorder, postorder, start, inorderIndex - 1, postorderIndex);

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
    int inorder[100], postorder[100];

    printf("Enter inorder traversal:\n");
    int inorderSize = getInput(inorder);

    printf("Enter postorder traversal:\n");
    int postorderSize = getInput(postorder);

    if (inorderSize != postorderSize) {
        printf("Error: Inorder and postorder arrays must have the same size.\n");
        return 1;
    }

    int postorderIndex = postorderSize - 1;


    struct Node* root = buildTree(inorder, postorder, 0, inorderSize - 1, &postorderIndex);


    printf("Inorder traversal of the constructed tree:\n");
    printInorder(root);
    printf("\n");

    return 0;
}
