/*
The cost of a stock on each day is given in an array.
Find the maximum profit that you can make by buying and selling on those days.

Example 1:
    Input: n = 3, price = [4, 2, 6]
    Output: 4
    Explanation: Buy on day2(price=2) and sell on day3(price=6). Profit:6-2=4.

Example 2:
    Input: n = 5, price = [6, 2, 7, 3, 8]
    Output: 10
    Explanation: Buy on day2(price=2) and sell on day3(price=7). Profit:7-2=5.
    Then buy on day4(price=3) and sell on day5(price=8). Profit:5+8-3=10.
*/

#include <stdio.h>

int is_num_in_to_skip(int n, int *to_skip, int len_to_skip) {
    for (int i = 0; i < len_to_skip; i++) {
        if (to_skip[i] == n) {
            return 1;
        }
    }
    return 0;
}

int max_profit(int *price, int ub, int *to_skip, int len_to_skip, int to_skip_plus[2]) {
    if (ub - len_to_skip < 2) return 0;

    int max = 0, curr;
    to_skip[++len_to_skip] = to_skip_plus[0];
    to_skip[++len_to_skip] = to_skip_plus[1];
    for (int i = 0; i < ub; i++) {
        if (is_num_in_to_skip(i, to_skip, len_to_skip)) continue;

        for (int j = i + 1; j <= ub; j++) {
            if (is_num_in_to_skip(j, to_skip, len_to_skip)) continue;

            to_skip_plus[0] = i;
            to_skip_plus[1] = j;
            curr = price[j] - price[i] + max_profit(price, ub, to_skip, len_to_skip, to_skip_plus);
            if (curr > max) max = curr;
        }
    }
    return max;
}

int main() {
    int price[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    
    int to_skip[102];
    int dummy_to_skip_plus[2] = {-1, -1};
    printf("%d", max_profit(price, n-1, to_skip, 0, dummy_to_skip_plus));
    return 0;
}