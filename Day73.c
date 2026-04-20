/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/
#include <stdio.h>
#include <string.h>
#define MAX 1000
int main() {
    char s[MAX];
    scanf("%s", s);
    int freq[26] = {0};  
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    char result = '$';
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            result = s[i];
            break;
        }
    }

    printf("%c\n", result);
    return 0;
}
