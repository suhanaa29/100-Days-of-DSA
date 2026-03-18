/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i]
is the number of days you have to wait after the ith day to get a warmer temperature.If there is no future day for 
which this is possible, keep answer[i] == 0 instead*/

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev = stack[top--];
            result[prev] = i - prev;
        }
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    return result;
}
