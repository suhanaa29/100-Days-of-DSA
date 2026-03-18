/*The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value, and the median is the mean of the two middle values*/

#include <stdlib.h>

#define MAX 50000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- Max Heap ---------- */
void maxHeapifyUp(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] < heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void maxHeapifyDown(int heap[], int size, int i) {
    while (1) {
        int largest = i, l = 2*i+1, r = 2*i+2;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
}

/* ---------- Min Heap ---------- */
void minHeapifyUp(int heap[], int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else break;
    }
}

void minHeapifyDown(int heap[], int size, int i) {
    while (1) {
        int smallest = i, l = 2*i+1, r = 2*i+2;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

/* ---------- Core ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    } else {
        obj->minHeap[obj->minSize] = num;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    }

    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

        obj->minHeap[obj->minSize] = val;
        minHeapifyUp(obj->minHeap, obj->minSize);
        obj->minSize++;
    }

    if (obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);

        obj->maxHeap[obj->maxSize] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize);
        obj->maxSize++;
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize)
        return obj->maxHeap[0];
    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
