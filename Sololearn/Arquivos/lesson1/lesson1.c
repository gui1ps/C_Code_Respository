#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    char buffer[200];
    
    fptr = fopen("myfile.txt", "a");

    if (fptr == NULL) {
        printf("Error opening file.");
        return -1;
    }

    fprintf(fptr,"Teste\n");
    fprintf(fptr,"ARROZ: %d\n",10);
    fclose(fptr);

    fptr = fopen("myfile.txt", "r");

    return 0;
}