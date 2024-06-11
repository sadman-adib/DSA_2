#include<bits/stdc++.h>

using namespace std;

// Structure to represent a tree node
struct TreeNode {
    int val;                // Value stored in the node
    struct TreeNode* left;  // Pointer to the left child
    struct TreeNode* right; // Pointer to the right child
};

// Function to create a new tree node with the given value
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the Binary Search Tree (BST)
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value); // Create a new node if the current node is NULL
    }

    if (value < root->val) {
        root->left = insert(root->left, value); // Recursively insert into the left subtree
    } else if (value > root->val) {
        root->right = insert(root->right, value); // Recursively insert into the right subtree
    }

    return root;
}

// Function to find the node with the minimum value in a BST
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left; // Traverse to the leftmost node to find the minimum value
    }
    return node;
}

// Function to delete a node from the Binary Search Tree (BST)
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root; // Return NULL if the current node is NULL (base case)
    }

    if (value < root->val) {
        root->left = deleteNode(root->left, value); // Recursively delete from the left subtree
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value); // Recursively delete from the right subtree
    } else {
        // Node to be deleted is found

        if (root->left == NULL) {
            // Node has only a right child or no child
            struct TreeNode* temp = root->right;
            free(root); // Free the memory of the node to be deleted
            return temp; // Return the right child as the new root
        } else if (root->right == NULL) {
            // Node has only a left child
            struct TreeNode* temp = root->left;
            free(root); // Free the memory of the node to be deleted
            return temp; // Return the left child as the new root
        }

        // Node has two children
        struct TreeNode* temp = findMin(root->right); // Get the inorder successor (smallest in right subtree)
        root->val = temp->val; // Copy the value of the inorder successor to this node
        root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
    }

    return root;
}

// Function to perform an inorder traversal of the BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left); // Traverse the left subtree
        printf("%d ", root->val);     // Print the current node's value
        inorderTraversal(root->right); // Traverse the right subtree
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert values into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);

    // Display the tree before deletion
    printf("Inorder Traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int deleteValue = 3;
    // Delete a node from the BST
    root = deleteNode(root, deleteValue);

    // Display the tree after deletion
    printf("Inorder Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
