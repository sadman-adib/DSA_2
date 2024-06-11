#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0; // Value not found
    }

    if (value == root->val) {
        return 1; // Value found
    } else if (value < root->val) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    int searchValue = 4;
    if (search(root, searchValue)) {
        printf("%d found in the BST.\n", searchValue);
    } else {
        printf("%d not found in the BST.\n", searchValue);
    }

    return 0;
}
