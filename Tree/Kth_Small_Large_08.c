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


void findKthSmallest(struct TreeNode* root, int* k, int* result) {
    if (root == NULL || *k <= 0) {
        return;
    }


    findKthSmallest(root->left, k, result);


    (*k)--;
    if (*k == 0) {
        *result = root->data;
        return;
    }


    findKthSmallest(root->right, k, result);
}


void findKthLargest(struct TreeNode* root, int* k, int* result) {
    if (root == NULL || *k <= 0) {
        return;
    }


    findKthLargest(root->right, k, result);


    (*k)--;
    if (*k == 0) {
        *result = root->data;
        return;
    }


    findKthLargest(root->left, k, result);
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

int main() {
    struct TreeNode* root = buildTree();

    int k;
    printf("Enter the value of k to find the kth smallest and kth largest elements: ");
    scanf("%d", &k);

    int kthSmallest = -1, kthLargest = -1;

    int k1 = k;
    int k2 = k;

    findKthSmallest(root, &k1, &kthSmallest);
    findKthLargest(root, &k2, &kthLargest);

    if (kthSmallest != -1) {
        printf("The %dth smallest element is: %d\n", k, kthSmallest);
    } else {
        printf("The tree has fewer than %d elements. No kth smallest found.\n", k);
    }

    if (kthLargest != -1) {
        printf("The %dth largest element is: %d\n", k, kthLargest);
    } else {
        printf("The tree has fewer than %d elements. No kth largest found.\n", k);
    }

    return 0;
}
