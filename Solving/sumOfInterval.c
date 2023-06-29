//beakjoon problem number 2042
//summation of interval
//23-05-17

#include <stdio.h>
#include <stdlib.h>

void printArr(long long * arr,long long * sum,int N){
    printf("print array (from index1)\n");
    for(int i = 1;i<=N;i++){
        printf("%lld ",arr[i]);
    }
    printf("\nprint sum\n");
    for(int i =1;i<=N;i++){
        printf("%lld ",sum[i]);
    }
}

int main (void){
    int N,M,K;
    //N : num of Numbers
    //M : num of modify
    //K : num of summation
    long long * arr;
    long long * sum;
    long long temp;
    long long b,c;
    int opt;
    long long modi;

    scanf("%d %d %d",&N,&M,&K);
    arr = (long long*)malloc(sizeof(long long)*N+1);
    sum = (long long*)malloc(sizeof(long long)*N+1);
    arr[0] = 0;
    sum[0] = 0;
    scanf("%lld",&arr[1]);
    sum[1] = arr[1];
    for(int i = 2;i<=N;i++){
        scanf("%lld",&temp);
        arr[i] = temp;
        sum[i] = sum[i-1] + temp;
    }
    
    //printArr(arr,sum,N);
    
    for(int i = 0;i<M+K;i++){
        scanf("%d",&opt);
        if (opt == 1){//modify
            scanf("%lld %lld",&b,&c);
            modi = c - arr[b];
            arr[b] = c;
            for(int j=b;j<N+1;j++){
                sum[j] += modi;
            }
        } else {        //summation
            scanf("%lld %lld",&b,&c);
            printf("%lld\n",sum[c]-sum[b-1]);
            
        }
    }
    //printArr(arr,sum,N);
}