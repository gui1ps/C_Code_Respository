#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int randomnum=rand();
    int numeroaleatorio=0+(randomnum%(101));
    printf("%d\n",numeroaleatorio);

    printf("Bem vindo(a)! \n");
    printf("O numero ja foi sorteado!\n");

    int resp;
    int tentativas=0;

    do{
        printf("Numero: ");
        scanf("%d",&resp);

        if(resp<numeroaleatorio){
            printf("O seu numero e menor que o sorteado!\n");
            tentativas++;}
        else if(resp>numeroaleatorio){
            printf("O seu numero e maior que o sorteado!\n");
            tentativas++;}
        else{
            tentativas++;
        }

    }while (resp!=numeroaleatorio);

    printf("Voce acertou, o numero escolhido foi o %d! Tetativas: %d",numeroaleatorio,tentativas);
    

    return 0;
}