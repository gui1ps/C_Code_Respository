#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include <string.h>
#include <unistd.h>

char generatepass(int tam);
char randomchar();

int main(){
    char *pass=generatepass(8);
    printf("%s",pass);
    return 0;
}


char generatepass(int tam){
    char pass[tam];
    for(int i=0;i<tam;i++){
        pass[i]=randomchar();
        sleep(1);
        printf("Gerando caracteres. Faltam : %d\n",tam-1);
    }
    return pass;
}

char randomchar(){
    static int choose=0;
    srand(time(NULL));
    int randomnum=rand();
    char letters[52]={ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char num[10]={'0','1','2','3','4','5','6','7','8','9'};
    char special[28]={'!', '#' , '$' , '%' , '&' ,'(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' , ':' , ';' , '<' , '=' , '>' , '?' , '@' , '[' , '^' , '_' , '`' , '{' , '|' , '}' , '~'};

    if(choose==0){
        choose++;
        return letters[randomnum%52];
    }else if (choose==1){
        choose++;
        return num[randomnum%10];
    }
    else{
        choose=0;
        return special[randomnum%28];
    }
}