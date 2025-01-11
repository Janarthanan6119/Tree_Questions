#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


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


struct Node* buildTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* node = newNode(data);
    printf("Enter left child of %d:\n", data);
    node->left = buildTree();
    printf("Enter right child of %d:\n", data);
    node->right = buildTree();

    return node;
}


struct QueueNode {
    struct Node* treeNode;
    int hd;
    struct QueueNode* next;
};


struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(struct Queue* q, struct Node* treeNode, int hd) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->hd = hd;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}


struct QueueNode* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    struct QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return temp;
}


struct Hashmap {
    int hd;
    int data[100];
    int count;
};


void verticalOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }


    struct Hashmap map[100];
    for (int i = 0; i < 100; i++) {
        map[i].hd = INT_MIN;
        map[i].count = 0;
    }

    struct Queue* q = createQueue();
    enqueue(q, root, 50);

    while (q->front != NULL) {
        struct QueueNode* temp = dequeue(q);
        struct Node* treeNode = temp->treeNode;
        int hd = temp->hd;
        free(temp);


        if (map[hd].hd == INT_MIN) {
            map[hd].hd = hd;
        }
        map[hd].data[map[hd].count++] = treeNode->data;


        if (treeNode->left != NULL) {
            enqueue(q, treeNode->left, hd - 1);
        }
        if (treeNode->right != NULL) {
            enqueue(q, treeNode->right, hd + 1);
        }
    }


    for (int i = 0; i < 100; i++) {
        if (map[i].hd != INT_MIN) {
            printf("Vertical line %d: ", map[i].hd - 50);
            for (int j = 0; j < map[i].count; j++) {
                printf("%d ", map[i].data[j]);
            }
            printf("\n");
        }
    }
}


int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    printf("\nVertical Order Traversal:\n");
    verticalOrderTraversal(root);

    return 0;
}
