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

int max(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

int main() {
    int nums[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int bag[n];
    bag[0] = nums[0];
    bag[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        bag[i] = max(bag[i-1], bag[i-2] + nums[i]);
    }
    printf("%d", bag[n-1]);
    return 0;
}