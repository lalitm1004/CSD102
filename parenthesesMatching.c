#include <stdio.h>

int isOpening(char c) {
    /*
        I can not be bothered to write better code kys
    */
    return (
        c == '{' ||
        c == '[' ||
        c == '('
    );
}

int isClosing(char c) {
    /*
        Same here
    */
    return (
        c == '}' ||
        c == ']' ||
        c == ')'
    );
}

int isMatch(char c1, char c2) {
    return (
        c1 == '(' && c2 == ')' ||
        c1 == '{' && c2 == '}' ||
        c1 == '[' && c2 == ']'
    );
}

void push(char *stack, int *top, char data) {
    stack[(*top)++] = data;   
}

void pop(char *stack, int *top) {
    stack[--(*top)];
}

char peek(char *stack, int top) {
    return (stack[top - 1]);
}

int parenthesesMatch(char *array, int len) {
    char stack[len];
    int top = 0;

    for (int i = 0; i < len; i++) {
        char curr = array[i];
        if (isOpening(curr)) {
            push(stack, &top, curr);
        } else if (isClosing(curr)) {
            char topChar = peek(stack, top);
            // Wrong match
            if (isMatch(curr, topChar)) {
                printf("curr - %c | topChar - %c\n", curr, topChar);
                return 0;
            }

            // Nothing to match against
            if (top == 0) {
                return 0;
            }

            // All matches succeed
            pop(stack, &top);
        }
    }
    if (top == 0) {
        return 1;
    } else {
        return 0;
    }

}

int main() {
    // Edit string below. Could automate, but no.
    char check[] = "d[(awdaw(d{wadadawd}awdad))]adadwwa";
    int len = sizeof(check) / sizeof(check[0]);

    printf("%s", parenthesesMatch(check, len) ? "MATCH\n" : "MISMATCH\n");
}