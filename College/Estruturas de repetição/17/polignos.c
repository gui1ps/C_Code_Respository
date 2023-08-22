#include <stdio.h>

int main(){
    printf("Vamos calcular a area do seu poligno! \n");

    int resp;
    float tam;

    do{
        printf("QUANTOS LADOS TEM SEU POLIGNO : [0] SAIR | [3] AREA DE TRIANGULO | [4] AREA DE QUADRADO | [6] AREA DE HEXAGONO :");
        scanf("%d",&resp);

        switch (resp)
        {
        case 0:
            printf("Saindo...\n");
            break;

        case 3:
            printf("Tamanho dos 3 lados: ");
            scanf("%f",&tam);
            printf("A area e: %f\n",((tam*tam)*1.73/4));
            break;

        case 4:
            printf("Tamanho de um dos lados: ");
            scanf("%f",&tam);
            printf("A area e: %f\n",(tam*tam));
            break;
        case 6:
            printf("Tamanho dos 6 lados: ");
            scanf("%f",&tam);
            printf("A area e: %f\n",(6*((tam*tam)*1.73/4)));
            break;

        default:
            printf("nao sei calcular a area\n");
            break;
        }

    }while(resp!=0);
    
    return 0;
}