#include <stdio.h>
/*
int main(){
    float goldem_purity;
    printf("Goldem purity");
    scanf("%f",&goldem_purity);
    if (goldem_purity<20){
        printf("BAD GOLDEM");
    }
    else{
        printf("GOOD GOLDEM");
    }
    return 0;
}
*/
/*
int main(){
    float peso;
    float altura;
    int idade;

    printf("Bem vindo ao exército!\n");
    printf("Sua idade: ");
    scanf("%d",&idade);
    printf("\nSeu peso: ");
    scanf("%f",&peso);
    printf("\nSua altura: ");
    scanf("%f",&altura);

    if (idade>=18){
        if (peso>=60){
            if (altura >=1.70){
                printf("Aprovado em todos os requisitos");
            }
            else{
                printf("Reprovado por altura");
            }
        }
        else{
            printf("Reprovado por peso");
        }
    }
    else{
        printf("Idade não suficiente!");
    }

    return 0;
}
*/

int main(){
    int resp;
    float num1,num2,num3;
    printf("Escolha uma das opcoes: [0] Tirar medias");
    scanf("%d",&resp);
    switch (resp)
    {
    case 0:
        scanf("%f %f %f",&num1,&num2,&num3);
        printf("Media: %f",(num1+num2+num3)/3);
        break;
    default:
        printf("Comando inválido");
    }
    return 0;
}
