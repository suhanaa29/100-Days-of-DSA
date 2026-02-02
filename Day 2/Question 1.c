/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array \n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter %d numbers: \n",n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int pos;
    printf("Enter the position which element to be deleted: \n");
    scanf("%d",&pos);
    
    for(int j= pos-1;j<n-1;j++){
        arr[j]=arr[j+1];
    }
    
    printf("The updated array is: \n");
    for(int k=0;k<(n-1);k++){
        printf("%d \t",arr[k]);
    }
}
