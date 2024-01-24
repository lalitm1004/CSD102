/*
Ask the user to enter a number N. The program should print the largest value of integer M
such that M x M does not exceed N.

Example 1:
    Input: N = 50
    Output: 7

Example 2:
    Input: N = 65
    Output: 8
*/

#include <stdio.h>

int main() {
    int N;
    int M;
    scanf("%d", &N);
    M = 0
    while (M * M < N) {
        M+=1;
    }
    printf("%d", M-1);
    return 0;
}