/*
Write a C program to check if a singly linked list is a palindrome or not.

Example 1:
    Input: n = 4, Input data for nodes = [2, 5, 7, 4]
    Output: NO

EXAMPLE 2:
    Input: n = 5, Input data for nodes = [1, 2, 3, 2, 1]
    Output: YES
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked lists
struct Node {
    int data;
    struct Node *next;
};

void createNodeList(struct Node *node0, int n) {
    struct Node *prevNode = node0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (i == 0) {
            node0 -> data = num;
            continue;
        }

        struct Node *nextNode = (struct Node *)malloc(sizeof(struct Node));
        nextNode -> data = num;
        prevNode -> next = nextNode;
        nextNode -> next = NULL;
        prevNode = nextNode;
    }
}

struct Node *copyList(struct Node *node0, int n) {
    struct Node *cpyNode0 = (struct Node *)malloc(sizeof(struct Node));
    cpyNode0 -> next = NULL;

    struct Node *cpyPrevNode = cpyNode0;
    struct Node *ogPrevNode = node0;
    for (int i = 0; i < n; i++) {
        int data = ogPrevNode -> data;
        if (i == 0) {
            cpyPrevNode -> data = data;
            ogPrevNode = ogPrevNode -> next;
            continue;
        }

        struct Node *cpyNextNode = (struct Node *)malloc(sizeof(struct Node));
        cpyNextNode -> data = ogPrevNode -> data;
        cpyPrevNode -> next = cpyNextNode;
        cpyNextNode -> next = NULL;
        cpyPrevNode = cpyNextNode;
        ogPrevNode = ogPrevNode -> next;
    }

    return cpyNode0;
}

void displayList(struct Node *node0) {
    struct Node *p = node0;
    while (p -> next != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("%d", p -> data);
}

int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);

    struct Node *node0 = (struct Node *)malloc(sizeof(struct Node));
    node0 -> next = NULL;
    createNodeList(node0, n);
    struct Node *cpyNode0 = copyList(node0, n);


    struct Node *prev = NULL;
    struct Node *curr = cpyNode0;
    struct Node *next = 1;
    while(next != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    cpyNode0 = prev;


    struct Node *l1 = node0;
    struct Node *l2 = cpyNode0;
    int isPalindrome = 1;
    for (int i = 0; i < n; i++) {
        if (l1 -> data != l2 -> data) {
            isPalindrome = 0;
            break;
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    printf("%s", (isPalindrome) ? "YES" : "NO");

    return 0;
}