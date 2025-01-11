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


void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}


struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    struct QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    struct Node* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}


int isEmpty(struct Queue* q) {
    return q->front == NULL;
}


void diagonalTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* q = createQueue();
    enqueue(q, root);

    printf("Diagonal Traversal:\n");
    while (!isEmpty(q)) {
        int size = 0;
        struct QueueNode* temp = q->front;


        while (temp) {
            size++;
            temp = temp->next;
        }


        for (int i = 0; i < size; i++) {
            struct Node* current = dequeue(q);


            while (current != NULL) {
                printf("%d ", current->data);


                if (current->left != NULL) {
                    enqueue(q, current->left);
                }


                current = current->right;
            }
        }
        printf("\n");
    }
}


int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    printf("\nDiagonal Traversal of the Binary Tree:\n");
    diagonalTraversal(root);

    return 0;
}
