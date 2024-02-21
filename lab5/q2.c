/*
Implement the given STACK ADT STRUCTURES:

void print_stack(Stack *s);             // Print stack in forward order, from top
void print_stack_reverse(Stack *s);     // Print stack in reverse order, from base
void push(Stack *s, char val);          // Push value onto stack
unsigned int count(Stack *s);           // Count elements of stack
void pop(Stack *s)                      // Pop top element
char top(Stack *s)                      // Retrieve top element
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *next;
} node;

typedef struct Stack {
    struct node* head;
    unsigned int size;
} Stack;

// Stack ADT
void print_stack(Stack *s);             // Print stack in forward order, from top
void print_stack_reverse(Stack *s);     // Print stack in reverse order, from base
void push(Stack *s, char val);          // Push value onto stack
unsigned int count(Stack *s);           // Count elements of stack
void pop(Stack *s);                     // Pop top element
char top(Stack *s);                     // Retrieve top element

int main() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s -> head = NULL;
    s -> size = 0;
    char temp[50];

    scanf("%s", temp);
    for (int i = 0; i < 50; i++) {
        if (temp[i] == '\0') {
            break;
        }
        push(s, temp[i]);
    }
    print_stack_reverse(s);
    pop(s);
    scanf("%s", temp);
    for (int i = 0; i < 50; i++) {
        if (temp[i] == '\0') {
            break;
        }
        push(s, temp[i]);
    }
    print_stack_reverse(s);

    return 0;
}

void push(Stack *s, char val) {
    int size = s -> size;
    s -> head = (node *)malloc(sizeof(node));
    s -> head -> next = NULL;
    node *temp = s -> head;
    for (int i = 0; i < size; i++) {
        temp = temp -> next; 
    }

    node *nextNode = (node *)malloc(sizeof(node));
    nextNode -> next = NULL;
    nextNode -> data = val;
    temp -> next = nextNode;
    s -> size = size + 1;
}

void pop(Stack *s) {
    int size = s -> size;
    // node *temp = s -> head;
    // for (int i = 0; i < size -1) {
    //     temp = temp -> next;
    // }
    // temp -> next = NULL;
    s -> size = size - 1;
}

char top(Stack *s) {
    int size = s -> size;
    node *temp = s -> head;
    for (int i = 0; i < size; i++) {
        temp = temp -> next;
    }
    return temp -> data;
}

void print_stack_reverse(Stack *s) {
    int size = s -> size;
    node *temp = s -> head;
    for (int i = 0; i < size; i++) {
        temp = temp -> next;
        printf("%c", temp -> data);
    }
}

void print_stack(Stack *s) {
    int size = s -> size;
    node *temp;
    for (int i = 0; i < size; i++) {
        temp = s -> head;
        for (int j = 0; j < (size - i); j++) {
            temp = temp -> next;
        }
        printf("%c", temp -> data);
    }
}