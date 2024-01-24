/*
Given a sorted integer array, find the index of a given number's first occurence.
If the element is not present in the array, return -1. Write an algorithm with
O(logn) time complexity.

Example 1:
    Input: n = 4, nums = [3, 6, 6,8], target = 6
    Output: 1

Example 2:
    Input: n = 6, nums = [4, 6, 8, 8, 9, 10], target = 7
    Output: -1
*/

#include <stdio.h>

int binary_search(int *arr, int left, int right, int target) {
    if (left == right) {
        return (arr[left] == target) ? arr[left] : -1;
    }
    if (right - left == 1) {
        if (arr[left] == target) return left;
        if (arr[right] == target) return right;
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binary_search(arr, mid+1, right, target);
    } else if (arr[mid] < target) {
        return binary_search(arr, left, mid-1, target);
    }
}

int main() {
    int nums[100], n, target;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);

    printf("%d", binary_search(nums, 0, n-1, target));

    return 0;
}