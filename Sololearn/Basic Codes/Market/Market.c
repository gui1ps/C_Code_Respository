#include <string.h>
#include <stdio.h>

const char carrinho[10][10];
float total;

void adiciona(char item);

int main(){
    int resp;

    printf("\nBem vindo(a) ao mercado do Gui!\n");

    do{
        printf("\n[1]Comprar | [2] Sair\n");
        scanf("%d",&resp);

        switch (resp){
            case 1:
                printf("\n[1] Ovo - 3,50 | [2] Carne - 50 | [3] Arroz - 5,30 \n);
                break;
            
            default:
                printf("Erro");
        }

    }while(resp!=6);
    return 0;
}

void adiciona(char item){
   static int last_item=0;
   strcpy(item,carrinho[last_item]);
}