#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
}point;

typedef struct{
    point xy;
    int z;
}corde;


int main(){
    point p1;
    p1.x=10;
    p1.y=20;
    corde c1={p1,50};
    printf("%d\n",c1.xy.y);
    return 0;
}