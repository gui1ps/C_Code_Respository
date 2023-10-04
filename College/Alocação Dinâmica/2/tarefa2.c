#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q;
int num;
char **vet;
char buffer[100];

void ler(char **ptr, int n);

int main(){
    printf("Quantos nomes serao adicionados na lista:");
    scanf("%d",&q);
    vet=(char**)malloc(q*sizeof(char*));
    for(int i=0;i<q;i++){
        printf("Nome: ");
        scanf("%s",&buffer);
        vet[i]= strdup(buffer);
    }
    ler(vet,q);
    free(vet);
    return 0;
}

void ler(char **ptr, int n){
    for(int z=0; z<n; z++){
        printf("%s\n",ptr[z]);
    }
}