//beakjoon problem number 18110
//solved.ac
//start date : 23-06-29
//solve date : 23-06-29

#include <stdio.h>
#include <math.h>

int main(void){
    int i;
    int n;
    int arr[31];
    int score;
    int exclude_num;

    for(int i=1;i<=30;i++){
        arr[i] = 0;
    } 

    scanf("%d",&n);
    exclude_num = (int)round((float)n*15/100);
    //printf("ex_num : %d\n",exclude_num);
    for(i=0;i<n;i++){
        scanf("%d",&score);
        arr[score] += 1;
    }
    if(n == 0) {
        printf("0\n");
        return 0;
    } else {
        int current_max=30;
        int current_min=1;
        for(i=0;i<exclude_num;i++){
            while(arr[current_max]==0){
                current_max--;
            }
            arr[current_max]--;
            while(arr[current_min]==0){
                current_min++;
            }
            arr[current_min]--;
        }
    }
    /*for(int i=1;i<=30;i++){
        printf("%02d | %d\n",i,arr[i]);
    }*/
    
    int sum=0;
    for(i=1;i<=30;i++){
        sum += arr[i] * i;
    }
    //printf("sum : %d\n",sum);
    //printf("n : %d\n",n);
    printf("%d\n",(int)round((float)sum/(n-exclude_num*2)));

    return 0;
}