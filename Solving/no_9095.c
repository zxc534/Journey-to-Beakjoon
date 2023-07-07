//beakjoon problem number 9095
//1,2,3 plus
//start date : 23-07-07
//solve date : 23-07-07

#include <stdio.h>

int combinationWithRepetition(int a, int b, int c);
int factorial(int a);

int combinationWithRepetition(int a, int b, int c){
    int result = factorial(a+b+c)/factorial(a)/factorial(b)/factorial(c);
    return result;
}

int factorial(int a){
    int num = 1;
    for(int i=1;i<=a;i++){
        num*=i;
    }
    return num;
}

int main(void){
    int T;
    int n;
    int i;
    int remember_table[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    int max_a,max_b,max_c;
    int sum = 0;
    scanf("%d",&T);

    for(i=0;i<T;i++){
        scanf("%d",&n);
        sum = 0;
        if(remember_table[n]){  //know
            printf("%d\n",remember_table[n]);
        } else {        //don't know
            max_a = n;
            max_b = n/2;
            max_c = n/3;
            for(int p=0;p<=max_a;p++){
                for(int q=0;q<=max_b;q++){
                    for(int r=0;r<=max_c;r++){
                        if((p+2*q+3*r)==n){
                            sum += combinationWithRepetition(p,q,r);
                        }
                    }
                }
            }
            remember_table[n] = sum;
            printf("%d\n",sum);
        }
    }
    
}