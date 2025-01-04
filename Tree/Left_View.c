#include <stdio.h>
#include <stdlib.h>
/*
The left view of a binary tree includes the first node visible when the tree
is viewed from the left side. This includes one node per level:
the leftmost node in each level:
Use a level-order traversal (BFS) to traverse the binary tree level by level.
At each level, print the first node encountered.
Maintain the level count and keep track of nodes visited at each level.
*/
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* node;
    int level;
    struct QueueNode* next;
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

struct QueueNode* createQueueNode(struct TreeNode* node, int level) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->node = node;
    newQueueNode->level = level;
    newQueueNode->next = NULL;
    return newQueueNode;
}

void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* node, int level) {
    struct QueueNode* newQueueNode = createQueueNode(node, level);
    if (*rear == NULL) {
        *front = *rear = newQueueNode;
        return;
    }
    (*rear)->next = newQueueNode;
    *rear = newQueueNode;
}

struct QueueNode* dequeue(struct QueueNode** front) {
    if (*front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    return temp;
}

void printLeftView(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root, 0);

    int currentLevel = -1;

    printf("Left view of the binary tree: ");

    while (front != NULL) {
        struct QueueNode* queueNode = dequeue(&front);
        struct TreeNode* treeNode = queueNode->node;
        int level = queueNode->level;


        if (level > currentLevel) {
            printf("%d ", treeNode->data);
            currentLevel = level;
        }


        if (treeNode->left != NULL) {
            enqueue(&front, &rear, treeNode->left, level + 1);
        }
        if (treeNode->right != NULL) {
            enqueue(&front, &rear, treeNode->right, level + 1);
        }

        free(queueNode);
    }

    printf("\n");
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    printf("Left view of the binary tree is:\n");
    printLeftView(root);

    return 0;
}
