/*Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.*/

import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    arr = list(map(int, input_data[1:n+1]))
    x = int(input_data[n+1])

    low, high = 0, n
    lower_bound = n
    while low < high:
        mid = (low + high) // 2
        if arr[mid] >= x:
            lower_bound = mid
            high = mid
        else:
            low = mid + 1

    low, high = 0, n
    upper_bound = n
    while low < high:
        mid = (low + high) // 2
        if arr[mid] > x:
            upper_bound = mid
            high = mid
        else:
            low = mid + 1

    print(f"{lower_bound} {upper_bound}")

if __name__ == "__main__":
    solve()
