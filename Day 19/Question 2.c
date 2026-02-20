/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.*/

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    
    int currMax = nums[0], maxKadane = nums[0];
    int currMin = nums[0], minKadane = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
        
        if(i > 0) {
            currMax = (nums[i] > currMax + nums[i]) ? nums[i] : currMax + nums[i];
            maxKadane = (maxKadane > currMax) ? maxKadane : currMax;
            
            currMin = (nums[i] < currMin + nums[i]) ? nums[i] : currMin + nums[i];
            minKadane = (minKadane < currMin) ? minKadane : currMin;
        }
    }
    
    if(maxKadane < 0)
        return maxKadane;
    
    return (maxKadane > totalSum - minKadane) ? maxKadane : totalSum - minKadane;
}
