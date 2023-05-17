//beakjoon problem number 9375
//fashion king Shin
//23-05-16

//By using YOGA13 this comment is added;

#include <stdio.h>
#include <string.h>

int combOfCloths(void);

int main (void){
    int N, M;
    //N = num of test case
    //M = num of cloths

    scanf("%d ",&N);
    for(int i =0;i<N;i++){
        printf("%d\n", combOfCloths());
    }
}

int combOfCloths(void){
    int M,i,j;
    int result = 1;
    char ch = 0;
    char temp[20];
    char * clothTypes[30];
    int clothNums[30];
    int typeIndex = 0;
    int isNew = 1;

    for(i=0;i<30;i++){
        clothTypes[i] = (char*)malloc(22);
    }

    for(i=0;i<30;i++){
        clothNums[i] = 0;
    }

    scanf("%d",&M);
    if(M == 0){
        return 0;
    }
    for(i=0;i<M;i++){
        while(getchar()!=' '){} //get until 'SPACE'
        fgets(temp, 22, stdin);
        //printf("%s",temp);

        for(j=0;j<typeIndex;j++){
            if(strcmp(clothTypes[j],temp)==0) { //str1 == str2
                isNew = 0;
                clothNums[j]++;
            }
        }

        if(isNew){
            strcpy(clothTypes[typeIndex],temp);
            clothNums[typeIndex]++;
            typeIndex++; 
        } else {
            isNew = 1;
        }

    }
    /*
    printf("typeIndex : %d\n",typeIndex);
    for(i=0;i<typeIndex;i++){
        printf("%s =>%d\n",clothTypes[i],clothNums[i]);
    }
    */
    for(i=0;i<typeIndex;i++){
        result *= clothNums[i]+1;
    }

    return result-1;
}