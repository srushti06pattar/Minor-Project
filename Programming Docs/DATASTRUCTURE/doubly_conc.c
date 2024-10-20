#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to append list2 to list1
struct Node* append(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    // Traverse to the end of list1
    struct Node *temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the last node of list1 to the first node of list2
    temp->next = list2;
    list2->prev = temp;

    return list1;
}

// Function to display the doubly linked list
void displayList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Create sample doubly linked lists
    struct Node *list1 = NULL, *list2 = NULL;

    // Append some elements to list1
    for (int i = 1; i <= 5; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = NULL;

        list1 = append(list1, newNode);
    }

    // Append some elements to list2
    for (int i = 6; i <= 10; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = NULL;

        list2 = append(list2, newNode);
    }

    // Display the original lists
    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    // Append list2 to list1
    list1 = append(list1, list2);

    // Display the appended list
    printf("Appended List: ");
    displayList(list1);

    return 0;
}
