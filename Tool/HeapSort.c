#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEAP_SIZE 50

void initHeap(int * heap, int * index, int * height);
void sortHeap(int * heap, int size);
void printHeap(int * heap, int index, int height);

void swap(int * a, int * b);

void drop(int * heap, int size, int index);
void pop(int * heap, int size);

int main (void) {
    int * heap = (int*)malloc(sizeof(int) * MAX_HEAP_SIZE);
    int size = 1;
    int height = 0;
    initHeap(heap, &size, &height);
    sortHeap(heap, size);
    printHeap(heap, size, height);
}

void initHeap(int * heap, int * size, int * height){
    int i,j,N;
    int jEnd;
    //1.Input
    /*
    printf("Enter initial input size : ");
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&heap[*index]);
        *index += 1;
    }
    */

    //2.Use Array
    int arr[12] = {29, 34, 18, 20, 27, 31, 44, 25, 30, 30, 40};
    for(i=1; i<=11; i++){
        heap[i] = arr[i-1];
    }
    *size = 12;
    *height = (int)(log(*size)/log(2));

    printf("Initiailizing heap...");
    for(i=*height;i>0;i--){
        j = (int)pow(2, i-1);
        jEnd = (int)pow(2, i);
        for(;(j<*size)&&(j<jEnd);j++){
            //printf("%d ",heap[j]);
            //compare every node with its child node
            drop(heap, *size, j);
        }
    }
}

void sortHeap(int * heap, int size){
    for(int i=1;i<size;i++){
        pop(heap,size-i);
    }
    
}

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void drop(int * heap, int size ,int index){
    int temp;
    int lvalue=0;
    int rvalue=0;
    if(index*2<size){     //left child node exist
        lvalue = heap[index*2];
    }
    if(index*2+1<size){     //right child node exist
        rvalue = heap[index*2+1];
    }
    if(rvalue > lvalue){
        if(rvalue > heap[index]){
            swap(&heap[index], &heap[index*2+1]);
            drop(heap, size, index*2+1);
            return;
        }
    } else {
        if(lvalue > heap[index]){
            swap(&heap[index], &heap[index*2]);
            drop(heap, size, index*2);
            return;
        }
    }
}

void pop(int * heap, int size){
    int temp;

    temp = heap[1];
    heap[1] = heap[size];
    heap[size] = temp;
    drop(heap,size,1);
}

void printHeap(int * heap, int index, int height){
    printf("Total heap size : %d\n", index);
    printf("Height of heap : %d\n", height);
    for(int i=1;i<index;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}