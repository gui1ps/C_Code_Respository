#include <stdio.h>

int main(){

    printf("De input em dois numeros e escolha uma opção para realizar a operação\n");
    char resp;
    float num1,num2;

    do{
       printf("[x] SAIR | [+] SOMAR |  [-] SUBTRAIR |  [*] MUTIPLICAR | [/] DIVIDIR\n");
       resp=getchar();

       switch (resp)
       {
        case 'x':
            printf("SAINDO ...\n");
            break;
        case '+':
            printf("Numero: ");
            scanf("%f",&num1);
            printf("Numero: ");
            scanf("%f",&num2);
            printf("A soma entre %f e %f: %f\n",num1,num2,(num1+num2));
            break;
        case '-':
            printf("Numero: ");
            scanf("%f",&num1);
            printf("Numero: ");
            scanf("%f",&num2);
            printf("A subtracao entre %f e %f: %f\n",num1,num2,(num1-num2));
            break;
        case '*':
            printf("Numero: ");
            scanf("%f",&num1);
            printf("Numero: ");
            scanf("%f",&num2);
            printf("A multiplicacao entre %f e %f: %f\n",num1,num2,(num1*num2));
            break;
        case '/':
            printf("Numero: ");
            scanf("%f",&num1);
            printf("Numero: ");
            scanf("%f",&num2);
            printf("A divisao entre %f e %f: %f\n",num1,num2,(num1/num2));
            break;
        default:
            printf("COMANDO INVÁLIDO");
            break;
       }

    }while (resp!='x');
    
    return 0;
}