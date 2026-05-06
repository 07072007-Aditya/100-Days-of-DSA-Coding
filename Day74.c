/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. 
In case of a tie, return the lexicographically smallest candidate name.
*/
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];

    // Input names
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[MAX][LEN];   // store unique candidate names
    int count[MAX] = {0};    // store vote counts
    int uniqueCount = 0;

    // Count votes
    for(int i = 0; i < n; i++) {
        int found = 0;

        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(unique[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN];

    for(int i = 0; i < uniqueCount; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output
    printf("%s %d\n", winner, maxVotes);

    return 0;
}