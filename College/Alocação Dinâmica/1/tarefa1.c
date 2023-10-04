#include <stdio.h>
#include <stdlib.h>

int q;
int num;
int *vet;

void ler(int *ptr, int n);

int main(){
    printf("Quantos numeros serao adicionados :");
    scanf("%d",&q);
    vet=(int*)malloc(q*sizeof(int));
    for(int i=0;i<q;i++){
        printf("Numero: ");
        scanf("%d",&vet[i]);
    }
    ler(vet,q);
    free(vet);
    return 0;
}

void ler(int *ptr, int n){
    for(int z=0; z<n; z++){
        printf("%d\n",ptr[z]);
    }
}