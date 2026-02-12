/*Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.*/

#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    
    int m = matrixSize;
    int n = matrixColSize[0];   // number of columns
    
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] != matrix[i-1][j-1]) {
                return false;
            }
        }
    }
    
    return true;
}
