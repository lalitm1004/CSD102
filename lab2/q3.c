/*
Given a circularly sorted integer array, find the total number of times the array is rotated.
Assume there are no duplicates in the array, and the rotation is in the anti-clockwise direction.

Example 1:
    Input: n = 5, nums = [3, 5, 7, 1, 2]
    Output: 3

Example 2:
    Input: n = 6, nums = [3, 5, 6, 7, 11, 15]
    Output: 0

[Hint: apply binary search]
*/

#include <stdio.h>

int get_rotation(int *arr, int left, int right, int prev) {
    if (left == right) return left;
    if (right - left == 1) return (arr[right] > arr[left]) ? left : right;

    int mid = (left + right) / 2;
    if (prev < arr[mid]) {
        return get_rotation(arr, mid+1, right, arr[mid]);
    } else if (prev > arr[mid]) {
        return get_rotation(arr, left, mid-1, arr[mid]);
    }
}

int main(void) {
    int nums[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (nums[0] > nums[n-1]) {
        printf("%d", get_rotation(nums,0, n-1, nums[0]));
    } else {
        printf("0");
    }
    return 0;
}