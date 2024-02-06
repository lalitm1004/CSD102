/*
Write a C program to merge two sorted singly linked lists into a single sorted linked list.

Example 1:
    Input:  n1 = 4, Input data for list1 = [2, 5, 6, 7]
            n2 = 3, Input data for list2 = [1, 3, 4]
    Output: 1 2 3 4 5 6 7
Example 2:
    Input:  n1 = 0, Input data for list1 = []
            n2 = 3, Input data for list2 = [1, 3, 4]
    Output: 1 3 4
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

void displayList(struct Node *node0) {
    struct Node *p = node0;
    while (p -> next != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("%d", p -> data);
}

struct Node *mergeLists(struct Node *l1, struct Node *l2, int n1, int n2) {
    struct Node *l3 = NULL;
    
    // Base Case
    if (l1 == NULL || n1 == 0) {
        return l2;
    } else if (l2 == NULL || n2 == 0) {
        return l1;
    }
    
    if (l1 -> data <= l2 -> data) {
        l3 = l1;
        l3 -> next = mergeLists(l1 -> next, l2, n1, n2);
    } else {
        l3 = l2;
        l3 -> next = mergeLists(l1, l2 -> next, n1, n2);
    }
    return l3;

}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    struct Node *l1_node0 = (struct Node *)malloc(sizeof(struct Node));
    l1_node0 -> next = NULL;
    createNodeList(l1_node0, n1);
    
    scanf("%d", &n2);
    struct Node *l2_node0 = (struct Node *)malloc(sizeof(struct Node));
    l2_node0 -> next = NULL;
    createNodeList(l2_node0, n2);

    struct Node *l3_node0;
    l3_node0 = mergeLists(l1_node0, l2_node0, n1, n2);
    displayList(l3_node0);

}