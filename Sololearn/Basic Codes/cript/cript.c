#include <stdio.h>
#include <string.h>

char* cript(char *x);
char* decript(char *x);

int main(){
    char word[20];
    char* ptr;
    char* ptr2;

    printf("Palavra de ate 20 letras: ");
    gets(word);
    printf("%s\n",word);

    ptr=cript(word);
    ptr2=decript(*ptr);

    printf("%s",*ptr);
    printf("%s",*ptr2);

    return 0;
}

char* cript(char *x){
    char cripchar[20];

    for(int i=0;i<strlen(x);i++){
        cripchar[i]=x[i]+3;
    }

    return &cripchar;
}

char* decript(char *x){
    char decripchar[20];

    for(int i=0;i<strlen(x);i++){
        decripchar[i]=x[i]-3;
    }

    return &decripchar;
}