/*Kth largest element in astream*/

#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int capacity;
} KthLargest;

void swap(int *a, int *b);
void heapifyUp(KthLargest* obj, int i);
void heapifyDown(KthLargest* obj, int i);
int kthLargestAdd(KthLargest* obj, int val);   // FUNCTION DECLARATION

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest* obj, int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (obj->heap[parent] <= obj->heap[i])
            break;

        swap(&obj->heap[parent], &obj->heap[i]);
        i = parent;
    }
}

void heapifyDown(KthLargest* obj, int i)
{
    while (1)
    {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&obj->heap[i], &obj->heap[smallest]);
        i = smallest;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
{
    KthLargest* obj = malloc(sizeof(KthLargest));
    obj->heap = malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++)
        kthLargestAdd(obj, nums[i]);

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val)
{
    if (obj->size < obj->capacity)
    {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    }
    else if (val > obj->heap[0])
    {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj)
{
    free(obj->heap);
    free(obj);
}
