#include <stdio.h>

int main(){
    float soma=0;
    float qnt=0;
    float val=1;
    printf("Iniciando\n");
    
    while (val>=0){

        printf("Valor: ");
        scanf("%f",&val);
        if(val>=0){
            soma+=val;
            qnt++;}
    }

    printf("A media dos valores e : %f",(soma/qnt));

    return 0;
}