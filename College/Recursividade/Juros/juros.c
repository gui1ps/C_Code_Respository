#include <stdio.h>
#include <stdlib.h>

float aplicarjuros(float val, int qntmes, float juros);

int main(){
    printf("%f",aplicarjuros(65,4,13.5));
    return 0;
}

float aplicarjuros(float val, int qntmes, float juros){
    if(qntmes>=0 && val>=0 && juros>=0){
        if(qntmes==0){
            return val;
        }
        else{
            val+=(val*(juros/100));
            return aplicarjuros(val,(qntmes-1),juros);
        }
    }
    else{
        return 0;
    }
}