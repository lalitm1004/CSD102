/*
Given an integer array representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police

Note: Adjacent houses have security systems connected and it will automatically contact
the police if two adjacent houses were broken into on the same night.

Example 1:
    Input: n = 4, nums = [1, 5, 7, 5]
    Output: 10
    Explanation: The thief will steal 5, and 5 from the house.

Example 2:
    Input: n = 5; nums = [3, 9, 4, 2, 8]
    Output: 17
    Explanation: The theif will steal 9, and 8 from the house.
*/

#include <stdio.h>

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int rob(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    } else if (end - start + 1 == 2) {
        return max(arr[start], arr[end]);
    } else if (end - start + 1 == 3) {
        return max(arr[start] + arr[end], arr[start + 1]);
    }

    return arr[start] + rob(arr, start+2, end);
}

int main() {
    int nums[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int rob_0 = rob(nums, 0, n-1);
    int rob_1 = rob(nums, 1, n-1);

    printf("%d", max(rob_0, rob_1));
    return 0;
}