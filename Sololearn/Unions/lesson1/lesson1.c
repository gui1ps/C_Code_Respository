#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union id
{
    char name[3];
    int id;
};


int main(){
    union id player1;
    player1.id=3000;
    strcpy(player1.name,"Gui");
    printf("%d\n",player1.id);
    printf("%s\n",player1.name);
    return 0;
}