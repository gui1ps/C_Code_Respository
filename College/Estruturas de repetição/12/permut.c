#include <stdio.h>

int verificaqnt(char *x, char num);
int verificarperm(char *x, char *y);

int main(){
    unsigned int num1;
    unsigned int num2;
    char cn1[20];
    char cn2[20];

    printf("Numero 1: ");
    scanf("%d",&num1);
    printf("Numero 2: ");
    scanf("%d",&num2);

    sprintf(cn1, "%u", num1);
    sprintf(cn2, "%u", num2);

    printf("Num1: %s, Num2: %s\n",cn1,cn2);

    if(verificarperm(cn1,cn2)==1)
        printf("Sao permutacoes! \n");
    else
        printf("Nao sao permutacoes! \n");
    return 0;
}


int verificarperm(char *x, char*y){
    int resp;
    if(strlen(x)!=strlen(y))
        return 0;
    else{
        for(int i=0;i<strlen(x);i++){
            if((verificaqnt(x,x[i]))==(verificaqnt(y,x[i])))
                resp=1;
            else{
                resp=0;
                break;
                }
        }
    }
    return resp;
}


int verificaqnt(char *x, char num){
    int qnt=0;
    for(int i=0;i<strlen(x);i++){
        if(x[i]==num)
            qnt++;
    }
    return qnt;
}