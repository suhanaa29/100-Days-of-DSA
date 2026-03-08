/*
Design your implementation of the circular double-ended queue (deque).*/

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->size = k;
    obj->arr = (int*)malloc(sizeof(int)*k);
    obj->front = -1;
    obj->rear = -1;
    return obj;
}

bool isFull(MyCircularDeque* obj){
    return ((obj->front == 0 && obj->rear == obj->size-1) || 
            (obj->front == obj->rear + 1));
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {

    if(isFull(obj))
        return false;

    if(obj->front == -1){
        obj->front = obj->rear = 0;
    }
    else if(obj->front == 0){
        obj->front = obj->size - 1;
    }
    else{
        obj->front--;
    }

    obj->arr[obj->front] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {

    if(isFull(obj))
        return false;

    if(obj->rear == -1){
        obj->front = obj->rear = 0;
    }
    else if(obj->rear == obj->size - 1){
        obj->rear = 0;
    }
    else{
        obj->rear++;
    }

    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {

    if(obj->front == -1)
        return false;

    if(obj->front == obj->rear){
        obj->front = obj->rear = -1;
    }
    else if(obj->front == obj->size - 1){
        obj->front = 0;
    }
    else{
        obj->front++;
    }

    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {

    if(obj->rear == -1)
        return false;

    if(obj->front == obj->rear){
        obj->front = obj->rear = -1;
    }
    else if(obj->rear == 0){
        obj->rear = obj->size - 1;
    }
    else{
        obj->rear--;
    }

    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->front == -1)
        return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->rear == -1)
        return -1;
    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->front == -1;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return isFull(obj);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}
