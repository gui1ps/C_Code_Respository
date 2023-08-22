#include <stdio.h>

int main(){
    float peso;
    int qant_boi;
    printf("Quantidade de bois: ");
    scanf("%d",&qant_boi);
    float lista_bois[qant_boi];
    float maisgordo=lista_bois[0];
    float maismagro;
    int indicemg=-1;
    int indicemm=-1;

    for(int i=0;i<qant_boi;i++){
        printf("Digite o peso do boi ID:%d: ",i);
        scanf("%f",&peso);

        if(peso!=0)
            lista_bois[i]=peso;
        else
            break;
    }

    printf("Lista geral dos bois: \n");

    for(int i=0;i<qant_boi;i++){
        printf("peso do boi ID:%d: %f \n",i,(lista_bois[i]));
    }

    for(int i=0;i<qant_boi;i++){
        if(lista_bois[i]>maisgordo){
            maisgordo=lista_bois[i];
            indicemg=i;
        }
        else if (lista_bois[i]==maisgordo && i<indicemg)
            indicemg=i;  
    }

    maismagro=maisgordo;

    for(int i=0;i<qant_boi;i++){
        if (lista_bois[i]<maismagro && lista_bois[i]!=0)
        {
            maismagro=lista_bois[i];
            indicemm=i;
        }
        else if (lista_bois[i]==maismagro && i<indicemm)
            indicemm=i; 
        
    }


    printf("Boi mais gordo: ID: %d | Peso: %f\n",indicemg,maisgordo);
    printf("Boi mais magro: ID: %d | Peso: %f\n",indicemm,maismagro);

}

/*
LETRA B:

#include <stdio.h>

int main(){
    float peso;
    int qant_boi=10;
    float lista_bois[qant_boi];
    float maisgordo=lista_bois[0];
    float maismagro;
    int indicemg=-1;
    int indicemm=-1;

    for(int i=0;i<qant_boi;i++){
        printf("Digite o peso do boi ID:%d: ",i);
        scanf("%f",&peso);

        if(peso!=0)
            lista_bois[i]=peso;
        else
            break;
    }

    printf("Lista geral dos bois: \n");

    for(int i=0;i<qant_boi;i++){
        printf("peso do boi ID:%d: %f \n",i,(lista_bois[i]));
    }

    for(int i=0;i<qant_boi;i++){
        if(lista_bois[i]>maisgordo){
            maisgordo=lista_bois[i];
            indicemg=i;
        }
        else if (lista_bois[i]==maisgordo && i<indicemg)
            indicemg=i;  
    }

    maismagro=maisgordo;

    for(int i=0;i<qant_boi;i++){
        if (lista_bois[i]<maismagro && lista_bois[i]!=0)
        {
            maismagro=lista_bois[i];
            indicemm=i;
        }
        else if (lista_bois[i]==maismagro && i<indicemm)
            indicemm=i; 
        
    }


    printf("Boi mais gordo: ID: %d | Peso: %f\n",indicemg,maisgordo);
    printf("Boi mais magro: ID: %d | Peso: %f\n",indicemm,maismagro);

}*/
