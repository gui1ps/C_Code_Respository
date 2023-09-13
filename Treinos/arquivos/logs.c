#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    char buffer[200], item[10], c;
    FILE *ptr;
    ptr=fopen("log.txt","a");
    fprintf(ptr,"----------\nData: %d/%d/%d\n%dh:%dmin\n----------\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,tm.tm_hour,tm.tm_min);
    fclose(ptr);

    ptr=fopen("log.txt","r");
    fgets(buffer,20,ptr);
    printf("%s\n",buffer);

    return 0;
}