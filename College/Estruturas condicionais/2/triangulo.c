#include <stdio.h>
#include <stdlib.h>
int main(){
    int l1;
    int l2;
    int l3;
    int i;


    for(i=0;i<3;i++){
        printf("Lado: ");

        if(i==0){
            scanf("%d",&l1);
        }
        else if (i==1)
        {
            scanf("%d",&l2);
        }
        else{
            scanf("%d",&l3);
        }
        
    }

    if((l1>(abs(l2-l3)) && l1<(l2+l3)) && (l2>(abs(l1-l3)) && l2<(l1+l3)) && (l3>(abs(l1-l2)) && l3<(l1+l2)) ){

        if((l1==l2) && (l2==l3))
            printf("É um triângulo equilátero");
        else if ((l1==l2) || (l1==l3) || (l2==l3))
            printf("É um triângulo isósceles ");
        else{
            printf("É um triângulo escaleno ");
        }
    }
    else{
        printf("Nao pode ser um triangulo");
    }
    
    return 0;
}