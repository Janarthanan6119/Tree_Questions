#include <stdio.h>
#include <stdlib.h>

#define MARKER -1  // Special marker for NULL nodes

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to serialize the binary tree
void serialize(struct Node* root, FILE* file) {
    if (root == NULL) {
        fprintf(file, "%d ", MARKER);  // Write marker for NULL
        return;
    }
    fprintf(file, "%d ", root->data); // Write the current node's data
    serialize(root->left, file);     // Serialize the left subtree
    serialize(root->right, file);    // Serialize the right subtree
}

// Function to deserialize the binary tree
struct Node* deserialize(FILE* file) {
    int val;
    if (!fscanf(file, "%d", &val) || val == MARKER) {
        return NULL; // Return NULL if marker or end of file
    }
    struct Node* root = newNode(val); // Create a new node with the value
    root->left = deserialize(file);   // Deserialize the left subtree
    root->right = deserialize(file);  // Deserialize the right subtree
    return root;
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to take user input to build a binary tree
struct Node* buildTree() {
    int val;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &val);
    if (val == MARKER) return NULL;
    struct Node* root = newNode(val);
    printf("Enter left child of %d:\n", val);
    root->left = buildTree();
    printf("Enter right child of %d:\n", val);
    root->right = buildTree();
    return root;
}

// Driver code
int main() {
    struct Node* root = NULL;
    FILE* file;

    // Step 1: Build tree from user input
    printf("Build the binary tree:\n");
    root = buildTree();

    // Step 2: Serialize the tree to a file
    file = fopen("tree.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    serialize(root, file);
    fclose(file);
    printf("Tree serialized to 'tree.txt'.\n");

    // Step 3: Deserialize the tree from the file
    file = fopen("tree.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    struct Node* deserializedRoot = deserialize(file);
    fclose(file);

    // Step 4: Print the deserialized tree
    printf("Inorder traversal of the deserialized tree:\n");
    inorderTraversal(deserializedRoot);
    printf("\n");

    return 0;
}
