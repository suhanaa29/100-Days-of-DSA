/*Problem: Find the integer square root of a given non-negative integer using Binary Search.
The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.*/

import sys

def solve():
    input_data = sys.stdin.read().strip()
    if not input_data:
        return
    
    n = int(input_data)
    if n < 2:
        print(n)
        return

    low, high = 1, n // 2
    ans = 1
    
    while low <= high:
        mid = (low + high) // 2
        if mid * mid <= n:
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
            
    print(ans)

if __name__ == "__main__":
    solve()
