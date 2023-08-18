#include <stdio.h>
int main(){
    int soma=0;
    int val;
    float resultado;
    int i;

    for(i=0;i<3;i++){
        printf("Valor: ");
        scanf("%d",&val);
        soma+=val;
    }
    resultado=soma/3;
    printf("Resultado: %f",resultado);
    
    printf("%d",soma);
}