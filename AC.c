//beakjoon problem number 5430
//AC

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
#define FUNC_LEN 100000

void getFunc(int *);
void getArr(int *);

void execFunc(int *,bool *,int *,int *);
void printArr(int *,int,int,bool);

int main (void) {
    int i,T,arr_len,arr_sta;
    bool isErr,isRev;
    int func[FUNC_LEN];
    int * arr;

    scanf("%d",&T);

    for(i=0;i<T;i++){
        arr_sta = 0;
        isErr = false;
        isRev = false;
        getFunc(func);
        //for(int j=0;j<100;j++){printf("%d  ",func[j]);}       FUNC 출력

        scanf("%d",&arr_len);
        arr = (int*)malloc(sizeof(int)*arr_len);
        getArr(arr);
        //for(int j=0;j<arr_len;j++){printf("%d  ",arr[j]);}    ARR 출력

        execFunc(func, &isRev, &arr_len, &arr_sta);
        if (arr_len < arr_sta) {isErr =  true;}

        if (isErr) {
            printf("error\n");
        } else {
            printArr(arr,arr_len,arr_sta,isRev);
        }
    }
}

void getFunc(int *func){
    getchar();
    char oper;
    int i=0;
    for(;oper != '\n';i++){
        oper = getchar();
        if(oper == 'R'){
            func[i] = 1;
        } else if (oper == 'D'){
            func[i] = 2;
        }
    };

    func[i-1] = -1;

    return;
}

void getArr(int *arr){
    getchar();
    getchar();
    int i=0;
    int arr_i=0;
    char one=getchar();
    char str[4];

    for(;one != ']';one = getchar()){
        if(one == ','){
            str[i] = 0;
            arr[arr_i] = atoi(str);
            arr_i ++;
            i = 0;
        } else {
            str[i] = one;
            i++;
        }
    }
    str[i] = 0;
    arr[arr_i] = atoi(str);
    arr_i ++;
    i = 0;

    return;
}

void execFunc(int * func,bool * isRev,int * arr_len,int * arr_sta){
    int i=0;
    for(i=0;func[i]!=-1;i++){
        if(func[i]==1){
            *isRev = !*isRev;
        } else if(func[i]==2) {
            if(*isRev){
                *arr_len -= 1;
            } else {
                *arr_sta += 1;
            }
        }
    }
    
    return;
}

void printArr(int *arr,int arr_len,int arr_sta,bool isRev){
    int i;

    printf("[");
    if(arr_len != arr_sta){
        if(isRev){
            for(i=arr_len-1;i>arr_sta;i--){
                printf("%d,",arr[i]);
            }
            printf("%d",arr[arr_sta]);
        } else {
            for(i=arr_sta;i<arr_len-1;i++){
                printf("%d,",arr[i]);
            }
            printf("%d",arr[arr_len-1]);
        }
    }
    printf("]\n");
}