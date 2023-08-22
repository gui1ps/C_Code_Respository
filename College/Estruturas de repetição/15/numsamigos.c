#include <stdio.h>

int achardivisores(int x);

int main(){
    for(int i=1;i<100001;i++){
        if((i==(achardivisores(achardivisores(i)))) && i!=achardivisores(i)){
            printf("%d-%d\n",i,achardivisores(i));
        }
    }
    return 0;
}

int achardivisores(int x){
    int soma=0;
    for(int j=1;j<x;j++){
        if(x%j==0)
            soma+=j;
    }
    return soma;
}