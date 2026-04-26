/*Problem: Implement Bubble Sort - Implement the algorithm.*/

import sys

def bubble_sort():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    arr = list(map(int, input_data[1:]))

    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

    print(*(arr))

if __name__ == "__main__":
    bubble_sort()
