/*
Write a C program to implement a stack using an array with push and pop operations.

Example 1:
    Input: n = 5, Input data to push: [2, 3, 6, 8, 4]
    Output: 4 8 6 3 2

Example 2:
    Input: n = 4, Input data to push: [7, 4, 6, 9]
    Output: 9 6 4 7
*/

#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int data) {
    stack[(*top)++] = data;
}

int pop(int *stack, int *top) {
    return stack[--(*top)];
}

int main() {
    int n;
    scanf("%d", &n);

    int *stack = (int *)malloc(n * sizeof(int));
    int top = 0;

    // Input n elements
    for (int i = 0; i < n; i++) {
        printf("%d", i);
        int data;
        scanf("%d", &data);
        push(stack, &top, data);
    }

    // Output n elements
    for (int i = 0; i < n; i++) {
        int popped = pop(stack, &top);
        printf("%d ", popped);
    }
}