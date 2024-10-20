#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int power_x;
    int power_y;
    struct Node* next;
};

// Function to create a new node with given coefficients and powers
struct Node* createNode(int coeff, int pow_x, int pow_y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newNode->coefficient = coeff;
    newNode->power_x = pow_x;
    newNode->power_y = pow_y;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
void insertTerm(struct Node** head, int coeff, int pow_x, int pow_y) {
    struct Node* newNode = createNode(coeff, pow_x, pow_y);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%dy^%d ", current->coefficient, current->power_x, current->power_y);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the polynomial
void freePolynomial(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Example usage
    struct Node* poly = NULL;

    // Insert terms into the polynomial
    insertTerm(&poly, 3, 2, 1);
    insertTerm(&poly, -1, 1, 2);
    insertTerm(&poly, 2, 0, 3);

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(poly);

    // Free the memory allocated for the polynomial
    freePolynomial(poly);

    return 0;
}
