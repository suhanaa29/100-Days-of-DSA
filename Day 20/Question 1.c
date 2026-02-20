/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int prefixSum = 0;
    int count = 0;

    // Create hash array large enough for constraints
    int offset = 100000; 
    int size = 200001;
    int *freq = (int*)calloc(size, sizeof(int));
    
    freq[offset] = 1;  // prefix sum 0 occurs once

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        if(freq[prefixSum + offset] > 0)
            count += freq[prefixSum + offset];
        
        freq[prefixSum + offset]++;
    }

    printf("%d", count);
    
    free(freq);
    return 0;
}
