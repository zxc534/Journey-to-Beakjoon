#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 10

void clearStr(char *);
int char2Int(char ,char);

int main(void){
    int i,M;
    int set = 0;
    char str[STR_LEN];
    int num;

    scanf("%d", &M);
    getchar();
    for(i=0;i<M;i++){
        gets(str);
        if(str[1]=='d'){
            num = char2Int(str[4],str[5]);
            set |= (1 << num);
        } else if (str[0]=='r') {
            num = char2Int(str[7],str[8]);
            set &= ~(1 << num);
        } else if (str[0]=='c') {
            num = char2Int(str[6],str[7]);
            if(set & (1 << num)){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (str[0]=='t') {
            num = char2Int(str[7],str[8]);
            set ^= (1 << num);
        } else if (str[1]=='l') {
            set =  (1<<21) - 1;
        } else if (str[0]=='e') {
            set = 0;
        }
        clearStr(str);
    }

    return 0;
}

void clearStr(char * str){
    int i;
    for(i=0;i<STR_LEN;i++){
        str[i] = 0;
    }
}

int char2Int(char a, char b){
    int num;
    if (b == 0){
        num = a - '0';
    } else {
        num = b - '0';
        num += (a - '0')*10;
    }

    return num;
}