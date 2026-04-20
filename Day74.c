/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    char candidates[MAX][NAME_LEN];
    int votes[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < count; j++) {
            if (strcmp(names[i], candidates[j]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            votes[found]++;
        } else {
            strcpy(candidates[count], names[i]);
            votes[count] = 1;
            count++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[NAME_LEN];
    strcpy(winner, candidates[0]);

    for (int i = 0; i < count; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            strcpy(winner, candidates[i]);
        } else if (votes[i] == maxVotes && strcmp(candidates[i], winner) < 0) {
            strcpy(winner, candidates[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
