/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.*/

void moveZeroes(int* nums, int numsSize) {
    int j = 0; 
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
           
            if (i != j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
    }
}
