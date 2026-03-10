/*sliding window maximum*/



#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* dq = (int*)malloc(numsSize * sizeof(int));
    
    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        if (front <= rear && dq[front] <= i - k)
            front++;

        while (front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        if (i >= k - 1)
            result[idx++] = nums[dq[front]];
    }

    *returnSize = idx;
    return result;
}
