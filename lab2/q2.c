/*
The cost of a stock on each day is given in an array.
Find the maximum profit that you can make by buying and selling on those days.

Example 1:
    Input: n = 3, price = [4, 2, 6]
    Output: 4
    Explanation: Buy on day2(price=2) and sell on day3(price=6). Profit:6-2=4.

Example 2:
    Input: n = 5, price = [6, 2, 7, 3, 8]
    Output: 5
    Explanation: Buy on day2(price=2) and sell on day3(price=7). Profit:7-2=5.
    Then buy on day4(price=3) and sell on day5(price=8). Profit:5+8-3=10.
*/

#include <stdio.h>

int main() {
    int price[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    return 0;
}