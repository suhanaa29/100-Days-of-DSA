/*Problem: Implement push and pop operations on a stack and verify stack operations.*/

#include <stdio.h>

int main() {
    int stack[100];
    int top = -1;
    int n, m, x;

    scanf("%d", &n);

    // Push n elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        stack[++top] = x;
    }

    // Pop m elements
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        if(top != -1)
            top--;
    }

    // Display stack from top to bottom
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
