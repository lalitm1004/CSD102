#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

node *createNode() {
    /*
        Returns a new node pointing to NULL
        O(1)
    */
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> next = NULL;
    return newNode;
}

void displayStack(node *top) {
    /*
        Displays stack
        O(n)
    */
    printf("|     |\n");
    node *curr = top;
    while (curr != NULL) {
        printf("| %3d |\n", curr -> data);
        curr = curr -> next;
    }
    printf("+-----+\n");

}

void push(node **top, int data) {
    /*
        Pre-appends a node to list and changes top
        O(1)
    */
    node *newNode = createNode();
    newNode -> data = data;
    if ((*top) == NULL) {
        (*top) = newNode;
    } else {
        newNode -> next = (*top);
        (*top) = newNode;
    }
}

int pop(node **top) {
    /*
        Returns data value of top and moves top forward
        O(1)
    */
    if ((*top) == NULL) {
        return -1;
    } else {
        int data = (*top) -> data;
        (*top) = (*top) -> next;
        return data;
    }
}

int peek(node *top) {
    /*
        Returns data value of top
        O(1)
    */
    if (top == NULL) {
        return -1;
    } else {
        return top -> data;
    }
}

int main() {
    node *top = NULL;

    printf("---------------\n");
    printf("A - Display Stack\nB - Push to stack\nC - Pop from stack\n");
    printf("---------------\n");
    char c;
    int data;
    while (1) {
        switch((c = getchar())) {
            case 'A':
                displayStack(top);
                break;
            case 'B':
                printf("Data to push > "); scanf("%d", &data);
                push(&top, data);
                break;
            case 'C':
                data = pop(&top);
                printf("Popped element > %d\n", data);
                break;
            case '\n':
                break;
            default:
                break;
        }
    }

}