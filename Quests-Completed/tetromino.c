#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N,M;
    int i,j,max,sum;
    int **arr;

    scanf("%d %d",&N,&M);
    arr = (int**) malloc ( sizeof(int*) * N );
    for(i=0; i<N; i++){
        arr[i] = (int*) malloc ( sizeof(int) * M );
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    max = 0;
    //case1
    for(i=0;i<N;i++){
        for(j=0;j<M-3;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case2
    for(i=0;i<N-3;i++){
        for(j=0;j<M;j++){
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case3
    for(i=0;i<N-1;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case4
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case5
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case6
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case7
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]+arr[i][j+2];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case8
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case9
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case10
    for(i=0;i<N-2;i++){
            for(j=0;j<M-1;j++){
                sum = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j];
                if (sum > max){
                    max = sum;
                }
            }
        }
    //case11
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case12
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case13
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j+1]+arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case14
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j]+arr[i+2][j];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case15
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case16
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]+arr[i][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case17
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case18
    for(i=0;i<N-1;i++){
        for(j=0;j<M-2;j++){
            sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }
    //case19
    for(i=0;i<N-2;i++){
        for(j=0;j<M-1;j++){
            sum = arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
            if (sum > max){
                max = sum;
            }
        }
    }

    printf("%d", max);
}