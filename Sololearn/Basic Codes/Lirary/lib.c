#include <stdio.h>
#include <string.h>
int main(){
    char bookname[80];
    int resp;
    int i;
    char livros[80][80];
    int last_position=0;
    int encontrado=0;

    printf("\nBem vindo(a) a biblioteca do Gui!\n");
    do{
    printf("\nO que voce deseja fazer: [0] Livros disponiveis | [1] Consultar por livros | [2] Incluir livros | [3] Sair\n");
    scanf("%d",&resp);

    switch (resp)
    {
    case 0:
        for(i=0;i<(last_position+1);i++){
            if(livros[i]!=NULL)
                printf("%s\n",livros[i]);
        }
        break;

    case 1:

        printf("Livro: ");
        scanf("%s",&bookname);

        for(i=0;i<80;i++){
            if(strcmp(livros[i],bookname)==0){
                printf(" O livro %s existe!\n",livros[i]);
                encontrado=1;}
            else if(i==79 && encontrado==0)
                printf(" O livro %s não existe!\n",bookname);
        }
        encontrado=0;
        break;
        
    case 2:

        printf("Livro: ");
        scanf("%s",&livros[last_position]);
        last_position++;
        break;

    case 3:
        printf("Saindo...");
        break;

    default:
        printf("Comando inválido!");
    }

    }while (resp!=3);
    return 0;
}