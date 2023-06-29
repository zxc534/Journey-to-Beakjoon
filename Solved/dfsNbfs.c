//beakjoon problem number 1260
//dfs and bfs
//start date : 23-06-28
//solve date : 23-06-29

#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int vertex;
    int progress;
}element;

element pop(element * stack, int * top){
    if((*top) == -1){
        element e;
        e.vertex = -1;
        return e;
    } else {
        element temp = stack[*top];
        (*top)--;
        return temp;
    }
}

void push(element * stack, int * top, int v, int p){
    (*top)++;
    stack[*top].vertex = v;
    stack[*top].progress = p;
}

int qPop(int * queue, int * head,int * tail){
    if((*head) == (*tail)-1){
        return -1;
    } else {
        (*head)++;
        return queue[*head];
    }
}

void qPush(int * queue, int * tail, int v){
    queue[*tail]= v;
    (*tail)++;
}

void qPrint(int * queue){
    for(int i =0; i<5;i++){
        printf("%d | v:%d\n",i,queue[i]);
    } 
}

int main(void){
    int N,M,V;
    int i,j;
    int start,end;
    
    scanf("%d %d %d",&N,&M,&V);
    int** edges= (int**) malloc ( sizeof(int*) * (N+1) );
    for(i=0; i<=N; i++){
        edges[i] = (int*) malloc ( sizeof(int) * (N+1) );
    }
    for(i=0;i<=N;i++){
        for(j=0;j<N;j++){
            edges[i][j] = 0;
        }
    }

    for(i=0;i<M;i++){
        scanf("%d %d",&start,&end);
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    //DFS start
    int* check = (int*) malloc (sizeof(int) * N+1);
    for(i=0;i<=N;i++){
        check[i] = 0;
    }
    check[V] = 1;
    element* stack = (element*) malloc (sizeof(element) * (N+1));
    int top = -1;
    int current_vertex = V;
    printf("%d ",V);
    i=1;
    while(1){
        for(;i<=N;i++){
            if((edges[current_vertex][i] == 1)&&(check[i]==0)){
                printf("%d ",i);
                check[i] = 1;
                push(stack,&top,current_vertex,i);
                current_vertex = i;
                break;
            }
        }
        if (i == N+1){
            element e = pop(stack,&top);
            //printf("\n pop v: %d  p: %d\n",e.vertex,e.progress);
            if(e.vertex == -1){
                break;
            } else {
                i = e.progress + 1;
                current_vertex = e.vertex;
            }
        } else {
            i = 1;
        }
    }
    printf("\n");
    //BFS start
    for(i=0;i<=N;i++){
        check[i] = 0;
    }
    check[V] = 1;
    int* queue = (int*) malloc (sizeof(int) * (N+1));
    int head =-1;
    int tail = 0;
    current_vertex = V;
    printf("%d ",V);
    while(1){
        for(i = 1;i<=N;i++){
            if((edges[current_vertex][i] == 1)&&(check[i]==0)){
                printf("%d ",i);
                check[i] = 1;
                qPush(queue,&tail,i);
            }
        }
        //qPrint(queue);
        int e = qPop(queue,&head,&tail);
        //printf("pop : %d\n",e);
        current_vertex = e;
        if(e == -1){
            break;
        }
    }
    return 0;
}