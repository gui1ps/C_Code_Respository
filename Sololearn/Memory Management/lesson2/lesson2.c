#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *x;
    x =malloc(0);
    if (x == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    *x = 50;
    int *ptr2=x+50;
    *ptr2=10;

    printf("%d\n",*(ptr2));

    printf("1: %d\n", *x);
    free(x);

    return 0;
}
