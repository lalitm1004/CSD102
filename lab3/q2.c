/*
Write a program in C to create a singly linked list of n nodes and display it in reverse order.

Example 1:
    Input: n = 4, Input data for nodes = [2, 5, 7, 4]
    Output: 4 7 5 2

Example 2:
    Input: n = 5, Input data for nodes = [2, 3, 7, 5, 1]
    Output: 1 5 7 3 2
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
    int num;                // Data for the node
    struct node *nextptr;   // Address of the next node
} *stnode;                  // Pointer to the starting node

void createNodeList(int n) {

    struct node *prevnode;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (i == 0) {
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

void reverseList() {
    struct node *prev = NULL;
    struct node *curr = stnode;
    struct node *next;
    while (next != NULL) {
        next = curr -> nextptr;
        curr ->  nextptr = prev;
        prev = curr;
        curr = next;
    }
    stnode = prev;
}

void displayList() {
    struct node *p = stnode;
    while (p -> nextptr != NULL) {
        printf("%d ", p -> num);
        p = p -> nextptr;
    }
    printf("%d ", p -> num);
}


// Main function
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);

    stnode = (struct node *)malloc(sizeof(struct node));

    createNodeList(n);
    reverseList();
    displayList();

    return 0;
}
