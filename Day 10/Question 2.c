/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as 
many times as it shows in both arrays and you may return the result in any order.*/

#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int count[1001] = {0};
    
    // Count frequency of nums1
    for(int i = 0; i < nums1Size; i++) {
        count[nums1[i]]++;
    }
    
    // Allocate maximum possible size
    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(sizeof(int) * maxSize);
    
    int k = 0;
    
    // Find intersection
    for(int i = 0; i < nums2Size; i++) {
        if(count[nums2[i]] > 0) {
            result[k++] = nums2[i];
            count[nums2[i]]--;
        }
    }
    
    *returnSize = k;
    return result;
}
