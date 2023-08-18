#include <stdio.h>

int main(){
    int i,lista[3];
    int menor;
    int maior;
    float soma=0;

    for(i=0;i<3;i++){
        scanf("%d",&lista[i]);
    }

    menor=lista[0];
    maior=lista[0];

    for(i=0;i<3;i++){
        if(lista[i]<menor){
            menor=lista[i];
        }
    }
    printf("O menor e: %d\n",menor);

    for(i=0;i<3;i++){
        if(lista[i]>maior){
            maior=lista[i];
        }
    }
    printf("O maior e: %d\n",maior);

    for(i=0;i<3;i++){
        soma+=lista[i];
    }
    printf("A media e: %f\n",soma/3);


}