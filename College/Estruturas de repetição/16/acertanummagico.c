#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int randomnum=rand();
    int numeroaleatorio=0+(randomnum%(501));
    printf("%d\n",numeroaleatorio);

    printf("Bem vindo(a)! \n");
    printf("O numero ja foi sorteado!\n");

    int resp;
    int tentativas=0;

    do{
        printf("Numero magico: ");
        scanf("%d",&resp);

        if(resp<numeroaleatorio){
            printf("O seu numero e menor que o numero magico!\n");
            tentativas++;}
        else if(resp>numeroaleatorio){
            printf("O seu numero e maior que o numero magico!\n");
            tentativas++;}
        else{
            tentativas++;
        }

    }while (resp!=numeroaleatorio);

    if(tentativas>=1 && tentativas<=3)
        printf("Muito sortudo");
    else if (tentativas>=4 && tentativas<=6)
        printf("Sortudo");
    else if (tentativas>=7 && tentativas<=10)
        printf("Normal");
    else
        printf("Voce deveria tentar denovo!");
    

    return 0;
}