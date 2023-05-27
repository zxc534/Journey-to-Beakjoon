#include <stdio.h>
#include <time.h>

int main(void){
    int year,month,date;
    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    year = t->tm_year + 1900;
    month = t->tm_mon + 1;
    date = t->tm_mday;
    printf("%d-%02d-%d",year,month,date);
}