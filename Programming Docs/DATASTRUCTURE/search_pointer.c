#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to search for a node with value 'x' in the list
struct Node* search(struct Node* root, int x) 
{
    while (root != NULL) {
        if (root->data == x) {
            return root; // Found the node with value 'x'
        }
        root = root->next;
    }
    return NULL; // Node with value 'x' not found
}

// Function to search and insert 'x' into the list
struct Node* srchinsrt(struct Node* l, int x) {
    struct Node* foundNode = search(l, x);

    if (foundNode != NULL) {
        return foundNode; // Node with value 'x' already exists
    }

    // Create a new node with value 'x'
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = l; // Add the new node at the beginning of the list

    return newNode; // Return pointer to the new node
}

// Function to display the linked list
void displayList(struct Node* l) {
    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* l) {
    struct Node* temp;
    while (l != NULL) {
        temp = l;
        l = l->next;
        free(temp);
    }
}

int main() {
    // Example usage
    struct Node* myList = NULL;

    myList = srchinsrt(myList, 5);
    myList = srchinsrt(myList, 1);
    myList = srchinsrt(myList, 15);

    printf("Original List: ");
    displayList(myList);

    struct Node* searchResult = search(myList, 10);
    if (searchResult != NULL) {
        printf("seach successful!\n");
    } else {
        printf("search unsuccessful.\n");
    }


    printf("Updated List: ");
    displayList(myList);

    // Free allocated memory for the linked list
    freeList(myList);

    return 0;
}
