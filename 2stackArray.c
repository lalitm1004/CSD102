#include <stdio.h>

void displayStack(int *stack, int top) {
    if (top == 0) {
        printf("Stack empty\n");
        return;
    }
    for (int i = top - 1; i > -1; i--) {
        printf("| %3d |\n", stack[i]);
    }
    printf("+-----+\n");
}

void push(int *stack, int *top, int data) {
    stack[(*top)++] = data;
}

int pop(int *stack, int *top) {
    return (stack[--(*top)]);
}

int peek(int *stack, int top) {
    return (stack[top - 1]);
}

int main () {
    int size;
    int top = 0;
    printf("Enter max size of stack > "); scanf("%d", &size);
    int stack[size];

    char c;
    int insertElement;
    int poppedElement;
    int peekedElement;
    printf("---------------\nA - Display Stack\nB - Push to stack\nC - Pop from stack\nD - Peek stack\n");
    printf("---------------\n");
    while (1) {
        switch ((c=getchar())) {
            case 'A':
                displayStack(stack, top);
                break;
            case 'B':
                if (top < size) {
                    printf("Element to push > "); scanf("%d", &insertElement);
                    push(stack, &top, insertElement);
                } else {
                    printf("STACK OVERFLOW\n");
                }
                break;
            case 'C':
                if (top > 0) {
                    poppedElement = pop(stack, &top);
                    printf("Popped element > %d\n", poppedElement);
                } else {
                    printf("STACK UNDERFLOW\n");
                }
                break;
            case 'D':
                if (top > 0) {
                    peekedElement = peek(stack, top);
                    printf("Top element > %d\n", peekedElement);
                } else {
                    printf("Stack empty\n");
                }
            case '\n':
                break;
            default:
                break;
        }
    }   

}