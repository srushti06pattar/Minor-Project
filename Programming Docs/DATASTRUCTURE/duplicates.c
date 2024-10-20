#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to perform an in-order traversal and print unique elements
void inorderTraversal(struct Node* root)
 {
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to remove duplicates using BST
struct Node* removeDuplicates(struct Node* root, int* arr, int n) 
{
    struct Node* newRoot = NULL;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == root->data) 
        {
            continue; // Skip duplicates
        } 
        else 
        {
            newRoot = insert(newRoot, arr[i]);
        }
    }

    return newRoot;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    struct Node* root = NULL;

    // Build BST with unique elements
    for (int i = 1; i < n; i++) 
    {
        root = insert(root, arr[i]);
    }

    printf("\nOriginal list with duplicates: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    root = removeDuplicates(root, arr, n);

    printf("\nList after removing duplicates using BST: ");
    inorderTraversal(root);

    return 0;
}