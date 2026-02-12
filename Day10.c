/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>
int main() {
    char input[100];
    int i, length, isPalindrome = 1;  
    scanf("%s", input);
    length = strlen(input);
    for (i = 0; i < length / 2; i++) {
        if (input[i] != input[length - i - 1]) {
            isPalindrome = 0; 
            break;
        }
    }
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}