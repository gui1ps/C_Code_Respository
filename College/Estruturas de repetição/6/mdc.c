#include <stdio.h>

int mdc(int x, int y);

int main(){
    printf("De input em dois numeros\n");
    int num1;
    int num2;

    while ((num1!=0 && num2!=0))
    {
       printf("[0,0] SAIR\n");
       printf("Numero 1: ");
       scanf("%d",&num1);
       printf("Numero 2: ");
       scanf("%d",&num2);
       printf("O MDC entre %d e %d e: %d\n",num1,num2,mdc(num1,num2));
    }
    return 0;
}

int mdc(int x, int y){
    if (x%y==0){
        return y;
    }
    else{
        return mdc(y,(x%y));
    }
}