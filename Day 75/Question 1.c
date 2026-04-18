/*Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero*/

def longest_zero_sum_subarray(arr):
    hash_map = {}
    max_len = 0
    curr_sum = 0
    
    for i in range(len(arr)):
        curr_sum += arr[i]
        
        if curr_sum == 0:
            max_len = i + 1
        
        if curr_sum in hash_map:
            max_len = max(max_len, i - hash_map[curr_sum])
        else:
            hash_map[curr_sum] = i
            
    return max_len

arr = [15, -2, 2, -8, 1, 7, 10, 23]
print(longest_zero_sum_subarray(arr))
