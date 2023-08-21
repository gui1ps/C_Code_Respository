#include <stdio.h>
#include<tuple>

int eprimo(int x);
int decompor(int y);

int main(){
    int num;
    printf("Numero: ");
    scanf("%d",&num);
    printf("%d",decompor(num));

    return 0;
}

int eprimo(int x){
    int eprimo=1;
    for(int i=2;i<x;i++){
        if(x%i==0)
            eprimo=0;
    }
    if(eprimo!=0)
       return 0;
    else
       return 1;
}

int decompor(int y){
    for(int i=2;i<y;i++){
        if(y%i==0){
            return i,y/i;
        }
    }
    return 0;
}