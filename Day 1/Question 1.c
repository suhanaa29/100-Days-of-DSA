/*Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.*/
#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements in the array: \n");
    scanf("%d",&n);
    int arr[100];
    
    printf("Enter %d elements: \n",n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    } 
    
    int x,pos;
    printf("Enter the element to insert: \n");
    scanf("%d",&x);
    printf("Enter the position to insert (1 to %d): \n" ,n+1);
    scanf("%d",&pos);
    for(int i=n; i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=x;
    n++;
    
    printf("Array after insertion: \n");
    for(int i=0;i<n;i++){
    printf("%d \t",arr[i]);
    }
    return 0;
    
}
