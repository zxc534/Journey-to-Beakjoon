#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEAP_SIZE 50

int initHeap(int * heap, int * index, int * height);
void printHeap(int * heap, int index, int height);

int main (void) {
    int * heap = (int*)malloc(sizeof(int) * MAX_HEAP_SIZE);
    int index = 1;
    int height = 0;
    initHeap(heap, &index, &height);
    //printHeap(heap, index, height);
}

int initHeap(int * heap, int * index, int * height){
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
    *index = 12;
    *height = (int)(log(*index)/log(2));

    printf("Initiailizing heap...");
    for(i=*height;i>0;i--){
        j = (int)pow(2, i-1);
        jEnd = (int)pow(2, i);
        for(;(j<*index)&&(j<jEnd);j++){
            printf("%d ",heap[j]);
        }
    }

}

void printHeap(int * heap, int index, int height){
    printf("Total heap size : %d\n", index);
    printf("Height of heap : %d\n", height);
    for(int i=1;i<index;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}