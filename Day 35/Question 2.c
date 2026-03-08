/*Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).*/

#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void pushStack(int stack[], int *top, int x){
    stack[++(*top)] = x;
}

int popStack(int stack[], int *top){
    return stack[(*top)--];
}

bool isEmptyStack(int top){
    return top == -1;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack(obj->stack1, &obj->top1, x);
}

int myQueuePop(MyQueue* obj) {

    if(isEmptyStack(obj->top2)){
        while(!isEmptyStack(obj->top1)){
            int val = popStack(obj->stack1, &obj->top1);
            pushStack(obj->stack2, &obj->top2, val);
        }
    }

    return popStack(obj->stack2, &obj->top2);
}

int myQueuePeek(MyQueue* obj) {

    if(isEmptyStack(obj->top2)){
        while(!isEmptyStack(obj->top1)){
            int val = popStack(obj->stack1, &obj->top1);
            pushStack(obj->stack2, &obj->top2, val);
        }
    }

    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
