#include <stdio.h>

int main(){
    int numatual,numant,numantant;

    for(int i=0; i<101;i++){

        if(i==0){
            numatual=1;
            numant=0;
            numantant=0;
            printf("%d\n",numatual);
        }
        else{
            numantant=numant;
            numant=numatual;
            numatual=numant+numantant;
            printf("%d\n",numatual);
        }

    }
    return 0;
}