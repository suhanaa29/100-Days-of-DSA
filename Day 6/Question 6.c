/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. 
Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    for (int k = 0; k <= i; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}
