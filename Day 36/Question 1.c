/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isFull(int size) {
    return (front == (rear + 1) % size);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int x, int size) {

    if(isFull(size))
        return;

    if(front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    queue[rear] = x;
}

void dequeue(int size) {

    if(isEmpty())
        return;

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display(int size) {

    if(isEmpty())
        return;

    int i = front;

    while(1){
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main() {

    int n, m, x;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x,MAX);
    }

    scanf("%d",&m);

    for(int i=0;i<m;i++){
        dequeue(MAX);
    }

    display(MAX);

    return 0;
}
