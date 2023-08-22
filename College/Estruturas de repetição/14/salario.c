#include <stdio.h>

int main(){
    float sal;
    int horas;

    printf("\nHoras na semana: ");
    scanf("%d",&horas);

    printf("Valor por hora: ");
    scanf("%f",&sal);

    if(horas<=0)
        printf("Vc nao trabalhou nada!");
    else{
        if(horas<=40)
            printf("O salario e : %f",(sal*horas));
        else if (horas<=60)
            printf("O salario e : %f",((1.5*sal)*horas));
        else
            printf("O salario e : %f",((2*sal)*horas));
    }

    return 0;
}