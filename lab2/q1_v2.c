/*
Given and array nums[] of size N having integers in the range [1,N] with
some of the elements missing. The task is to find the missing elements.

Note: Do it without using extra space and O(n) runtime.

Example 1:
    Input: n = 4, nums = [1, 2, 2, 4]
    Output: 3

Example 2:
    Input: n = 6, nums = [1, 3, 4, 5, 5, 5]
    Output: 2 6
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int nums[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i=0; i<n; i++) {
        nums[abs(nums[i])-1] = abs(nums[abs(nums[i])-1])*-1;
    } 
        
    for (int i=0; i<n; i++) {
        if(nums[i]>0) {
            printf("%d", i+1);
        } 
    }
}