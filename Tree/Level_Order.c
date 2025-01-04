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


void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }


    struct TreeNode* queue[100];
    int front = 0, rear = 0;


    queue[rear++] = root;


    while (front < rear) {
        struct TreeNode* current = queue[front++];
        printf("%d ", current->data);


        if (current->left != NULL) {
            queue[rear++] = current->left;
        }


        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    printf("Level order traversal of the binary tree is:\n");
    levelOrderTraversal(root);

    return 0;
}
