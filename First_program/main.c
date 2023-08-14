#include <stdio.h>
/*
int main(){
    int age=10;
    printf("Hello, world!%d\n",age);
    printf("Second print");
    return 0;
}
*/
/*
int main(){
    float val1=4;
    float val2=5;
    float val3=6;
    int qnt=3;
    printf("Media: %f",(val1+val2+val3)/qnt);
    return 0;
}
*/
/*
int main(){
    float sal=3420.65;
    float desconto=0.10;
    printf("Total com desconto: %f",sal-(sal*desconto));
    return 0;
}
*/
/*
int main(){
    char name[3];
    float sal;
    scanf("%f",&sal);
    gets(name);
    return 0;
}*/
/*
int main(){
    printf("Você deseja iniciar? [s/n]: ");
    char resp=getchar();
    return 0;
}*/
/*
int main() {
    int x;
    double num;
    char text[20];
    scanf("%d %lf %s", &x, &num, text);
    printf("%d %lf %s", x, num, text);
}*/
/*
int main(){
    printf("\"HELLO MUNDOO!\"\n");
    printf("\"HELLO MUNDOO!\"\t TAAB");
    return 0;
}*/
int main(){
    float sal_min;
    float sal_pessoa;

    printf("Salario minimo: ");
    scanf("%f",&sal_min);
    printf("Salario da pessoa: ");
    scanf("%f",&sal_pessoa);
    printf("Esta pessoa ganha %f salario(os) minimo(os)",sal_pessoa/sal_min);

    return 0;
}