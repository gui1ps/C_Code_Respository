#include <stdio.h>

int main(){
    int segundos;
    int minutos;
    int horas;
    printf("Segundos: ");
    scanf("%d",&segundos);
    horas=(segundos/60)/60;
    minutos=(segundos/60)%60;
    segundos=segundos%60;
    printf("Isso totatiza: %d HORAS:%d MINUTOS:%d SEGUNDOS",horas,minutos,segundos);
    return 0;
}