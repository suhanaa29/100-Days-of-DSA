/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes.
In case of a tie, return the lexicographically smallest candidate name.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Candidate *votes = malloc(n * sizeof(struct Candidate));
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        char currentName[100];
        scanf("%s", currentName);

        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[j].name, currentName) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(votes[uniqueCount].name, currentName);
            votes[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    int winnerIdx = 0;
    for (int i = 1; i < uniqueCount; i++) {
        if (votes[i].count > votes[winnerIdx].count) {
            winnerIdx = i;
        } else if (votes[i].count == votes[winnerIdx].count) {
            if (strcmp(votes[i].name, votes[winnerIdx].name) < 0) {
                winnerIdx = i;
            }
        }
    }

    printf("%s %d\n", votes[winnerIdx].name, votes[winnerIdx].count);

    free(votes);
    return 0;
}
