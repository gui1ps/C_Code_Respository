#include <stdio.h>
int main(){
    int num;
    int eprimo=1;
    printf("Numero: ");
    scanf("%d",&num);
    for(int i=2;i<num;i++){
        if(num%i==0)
            eprimo=0;
    }
    if(eprimo!=0)
        printf("Esse numero e primo");
    else
        printf("Esse numero nao e primo");
    return 0;
}