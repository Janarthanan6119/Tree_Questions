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


struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }


    int mid = (start + end) / 2;


    struct TreeNode* root = createNode(arr[mid]);


    root->left = sortedArrayToBST(arr, start, mid - 1);


    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}


void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;


    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    struct TreeNode* root = sortedArrayToBST(arr, 0, n - 1);


    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal of the BST: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
