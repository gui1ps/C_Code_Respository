#include <stdio.h>
#include <string.h>

int main(){
    char buffer[5];
    char *ptr=&buffer+1;

    strcpy(buffer,"OverflowExample");

    printf("Buffer: %s\n", buffer);
    printf("Size: %d\n", sizeof("OverflowExample"));
    printf("Size: %d\n", sizeof(buffer));
    printf("Size: %p\n", &buffer);
    printf("Size: %p\n", &buffer+1);
    printf("Size: %\n", ptr);

    return 0;
}