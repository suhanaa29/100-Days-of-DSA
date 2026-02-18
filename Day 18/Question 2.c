/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].*/

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    result[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}
