#include <stdio.h>

int eprimo(int x);

int main(){
    int num;
    printf("Numero: ");
    scanf("%d",&num);
    int maior=0;

    for(int i=1;i<num;i++){
        if(eprimo(i)==1 && i>maior){
            maior=i;
        }
    }

    printf("O maior numero ate %d e %d",num,maior);
    return 0;

}

int eprimo(int x){
    int eprimo=1;
    for(int i=2;i<x;i++){
        if(x%i==0)
            eprimo=0;
    }
    if(eprimo!=0)
        return 1;
    else
        return 0;
}