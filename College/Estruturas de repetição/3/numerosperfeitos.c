#include <stdio.h>
int main(){
    int soma=0;
    for(int i=1;i<101;i++){
        for(int j=1;j<i;j++){
            if(i%j==0){
                soma+=j;
            }
        }
        if(soma==i){
            printf("%d\n",i);
        }
        soma=0;
    }
    return 0;
}