/*
Write a program in C to create and display a singly Linked list.

Example 1:
    Input: n = 4, Input data for nodes = [2, 5, 7, 4]
    Output: 2 5 7 4

Example 2:
    Input: n = 5, Input data for nodes = [2, 3, 5, 7, 1]
    Output: 2 3 5 7 1
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
    int num;                // Data of the node
    struct node *nextptr;   // Address of the next node
} *stnode;                  // Pointer to the starting node

// Function prototypes
void createNodeList(int n);
void displayList();

int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);

    createNodeList(n);
    displayList();

    return 0;
}

void createNodeList(int n) {
    
    struct node *prevnode;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (i == 0) {
            stnode = (struct node *)malloc(sizeof(struct node));
            stnode -> num = num;
            prevnode = stnode;
            continue;
        }

        struct node *nextnode = (struct node *)malloc(sizeof(struct node));
        nextnode -> num = num;
        prevnode -> nextptr = nextnode;
        nextnode -> nextptr = NULL;
        prevnode = nextnode;
    }
}

void displayList() {
    struct node *p = stnode;
    while (p -> nextptr != NULL) {
        printf("%d ", p -> num);
        p = p -> nextptr;
    }
    printf("%d ", p -> num);
}