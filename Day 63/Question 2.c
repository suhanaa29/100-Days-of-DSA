/*Return the modified image after performing the flood fill*/

void dfs(int** image, int r, int c, int m, int n, int oldColor, int newColor) {
    if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != oldColor) {
        return;
    }
    
    image[r][c] = newColor;
    
    dfs(image, r + 1, c, m, n, oldColor, newColor);
    dfs(image, r - 1, c, m, n, oldColor, newColor);
    dfs(image, r, c + 1, m, n, oldColor, newColor);
    dfs(image, r, c - 1, m, n, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];
    
    if (oldColor != color) {
        dfs(image, sr, sc, imageSize, imageColSize[0], oldColor, color);
    }
    
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}
