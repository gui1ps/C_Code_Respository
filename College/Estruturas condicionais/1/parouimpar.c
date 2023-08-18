#include <stdio.h>

int main(){
    int num;
    printf("Seu numero: ");
    scanf("%d",&num);
    if(num%2==0){
         printf("Par");
    }
    else{
      printf("Impar");  
    }
    return 0;
}