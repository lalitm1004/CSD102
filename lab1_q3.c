/*
Given a string str, find the length of the longest substring without repeating characters.

Example 1:
    Input: str = "snuioe"
    Output: 6
    Explanation: The answer is "snuioe", with the length of 6

Example 2:
    Input: str = "snusnu"
    Output: 3
    Explanation: The answer is "snu", with the length of 3
*/

#include <stdio.h>

int main() {
    char str[100];
    scanf("%s", &str);

    // Get length of str
    int len = 0;
    while (str[len] != '\0'){
        len++;
    }

    int max = 0;
    // Loops over entire string to get substrings with different start characters
    for (int i = 0; i < len; i++) {

        // Initializes substring array and appends starting character manually
        char sub[len];
        int sub_len = 0;
        
        // With a set starting character, loops over rest of string
        for (int j = i; j < len; j++) {
            
            
            // Loops over substring
            int isUnique = 1;
            for (int k = 0; k < sub_len; k++) {
                // Checking if current character is unique
                if (str[j] == sub[k]) {
                    isUnique = 0;
                    break;
                }
            }

            if (!isUnique) {
                break;
            }

            // Appends to substring if current character is unique
            sub[sub_len++] = str[j];
        }
        // Updates maximum substring length
        max = (max > sub_len) ? max : sub_len;
    }
    printf("%d\n", max);
    return 0;
}   