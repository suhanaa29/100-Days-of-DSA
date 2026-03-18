/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order,
but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.
Return the minimum number of CPU intervals required to complete all tasks.*/


int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    for (int i = 0; i < tasksSize; i++)
        freq[tasks[i] - 'A']++;

    int maxFreq = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > maxFreq)
            maxFreq = freq[i];

    int countMax = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] == maxFreq)
            countMax++;

    int slots = (maxFreq - 1) * (n + 1) + countMax;

    return slots > tasksSize ? slots : tasksSize;
}

