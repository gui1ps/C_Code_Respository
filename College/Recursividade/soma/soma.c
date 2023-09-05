#include <stdio.h>
#include <stdlib.h>

int somar(int a, int b);

int main(){
    printf("%d",somar(50,6));
}

int somar(int a, int b){
    if(a==b){
        return b;
    }
    else{
        if(a<b)
            return a+somar((a+1),b);
        else
            return b+somar((b+1),a);
    }
}