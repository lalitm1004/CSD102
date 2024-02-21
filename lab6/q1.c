#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

/*
HOW TO USE:
Input;
1. Input size of linked list (integer greater than 1)
2. Input data for the individul nodes
3. Input 0-index of node where you want to connect the loop to. (1 for 2nd)
*/

int main() {
    
    // Creation of singly linked list of size 5
    int listSize;
    scanf("%d", &listSize);
    node *node0 = (node *)malloc(sizeof(node));
    node *prevNode = node0;
    for (int i = 0; i < listSize; i++) {
        int data;
        scanf("%d", &data);
        if (i == 0) {
            node0 -> data = data;
            node0 -> next = NULL;
            continue;
        }
        node *nextNode = (node *)malloc(sizeof(node));
        nextNode -> data = data;
        prevNode -> next = nextNode;
        prevNode = nextNode;
    }
    prevNode -> next = NULL;
    
    
    // Connecting the loop
    int loopIndex; // 0-index of where the list should loop, i.e, 1 is 2nd node
    scanf("%d", &loopIndex);
    if (loopIndex < 0 || loopIndex > listSize - 1) {
        printf("Invalid loop point");
        return 1;
    }
    node *temp1 = node0; // Final Node
    node *temp2 = node0; // Node to connect loop to
    while (temp1 -> next != NULL) {
        temp1 = temp1 -> next;
    }
    for (int i = 0; i < loopIndex; i++) {
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2; // Connecting final node to looping node
    
    // Diagnostic
    node *diag1 = node0;
    for (int i = 0; i < listSize; i++) {
        printf("%d %p %p\n", diag1 -> data, diag1, diag1 -> next);
        diag1 = diag1 -> next;
    }
    
    // Detecting and removing the loop
    node *set[listSize]; // Create a cache for node addresses
    int setSize = 0; 
    
    node *prev;
    node *curr = node0;
    while (1) {
        
        // To check if a node has been previously found
        int isUnique = 1;
        for (int i = 0; i < setSize; i++) {
            if (curr == set[i]) {
                isUnique = 0;
                break;
            }
        }
        
        if (!isUnique) {
            // If it is not unique, we change the previous node to point to null.
            // Since first duplicate will always be after the looping starts.
            prev -> next = NULL;
            break;
        }
        // If it is unique, we move the pointers by one value and store new nodes in set.
        prev = curr;
        curr = curr -> next;
        set[setSize++] = prev;
    }
    printf("-----\n");
    // Diagnostic
    node *diag2 = node0;
    for (int i = 0; i < listSize; i++) {
        printf("%d %p %p\n", diag2 -> data, diag2, diag2 -> next);
        diag2 = diag2 -> next;
    }
}
