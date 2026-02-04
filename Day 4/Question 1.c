/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter %d numbers: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int j,k;
    for(j=0,k=(n-1);j<(n/2);j++,k--){
        arr[j]=arr[j]+arr[k];
        arr[k]=arr[j]-arr[k];
        arr[j]=arr[j]-arr[k];
    }
    
    printf("The updated array is: \n");
    for(int a=0;a<n;a++){
        printf("%d \t",arr[a]);
    }
}
