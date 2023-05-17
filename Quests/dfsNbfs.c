#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1001

typedef struct
{
    int stack[MAX_STACK_SIZE];
    int top;
}Stack;

void init_stack(Stack *s){
    s->top = -1;
    return;
}

void push(Stack *s, int num){
    s->top += 1;
    s->stack[s->top] = num;
    return;
}

int pop(Stack *s){
    s->top -= 1;
    return s->stack[s->top+1];
}

typedef struct{
    int index;
    int adj_nodes[1000];
    int adj_num;
}Node;

Node init_node(int num){
    Node n;
    n.index = num;
    n.adj_num = 0;
    return n;
}

int main (void){
    int N,M,V;
    int i,j;
    int p,c;

    Node n1,n2;
    scanf("%d %d %d",&N,&M,&V);
    Node * graph;
    graph = (Node*)malloc(sizeof(Node)*(N+1));
    for(i=0;i<N;i++){
        graph[i+1] = init_node(i+1);
    }
    for(i=0;i<M;i++){
        scanf("%d %d",&p,&c);
        graph[p].adj_nodes[graph[p].adj_num]=c;
        graph[p].adj_num+=1;
        graph[c].adj_nodes[graph[c].adj_num]=p;
        graph[c].adj_num+=1;
    }

    for(i=0;i<N;i++){
        n1 = graph[i+1];
        printf("Node : %d\n",n1.index);
        printf("adj_nodes : ");
        for(j=0;j<n1.adj_num;j++){
            printf("%d  ",n1.adj_nodes[j]);
        }
        printf("\n");
    }
}