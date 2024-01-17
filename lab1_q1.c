/*
Write a program in which the main program assigns values to two variables P and Q.
Then it sends P and Q to a function which returns back P^2 and Q^2.
The main program prints P, Q, P^2, Q^2

Example 1:
    Input: P = 4, Q = 6
    Output: 4 6 16 36

Example 2:
    Input: P = 1, Q = 7
    Output: 1 7 1 49
*/

#include <stdio.h>

int getSquare(int num) {
    return num * num;
}

int main() {
    int P, Q;
    scanf("%d%d", &P, &Q);

    printf("%d %d %d %d", P, Q, getSquare(P), getSquare(Q));
    return 0;
}   