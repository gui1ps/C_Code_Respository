#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef struct pessoa
{
    char nome[20];
    int numero;
    struct pessoa *prox;
    struct pessoa *ant;
} pessoa;

int sortNum(int MaxValue)
{
    return rand() % MaxValue + 1;
}

int verificarFilaVazia(pessoa *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int procurarPorIguais(pessoa *ptr, int num)
{
    if (verificarFilaVazia(ptr) != 0)
    {
        if (ptr->numero == num)
        {
            return 1;
        }
        else
        {
            procurarPorIguais(ptr->prox, num);
        }
    }
}

int atribuirNumeroNaoEscolhido(pessoa *ptr, int num, int MaxValue)
{
    if (procurarPorIguais(ptr, num) != 1)
    {
        return num;
    }
    else
    {
        atribuirNumeroNaoEscolhido(ptr, sortNum(MaxValue), MaxValue);
    }
}

pessoa *add(pessoa *ptr, int numMax)
{
    pessoa *nova_pessoa = (pessoa *)malloc(sizeof(pessoa));
    nova_pessoa->prox = ptr;
    nova_pessoa->ant = NULL;
    if (ptr != NULL)
    {
        ptr->ant = nova_pessoa;
    }
    fflush(stdin);
    printf("\nNome da nova pessoa: \n");
    fgets(nova_pessoa->nome, 20, stdin);
    nova_pessoa->numero = atribuirNumeroNaoEscolhido(ptr, (rand() % numMax + 1), numMax);
    printf("\nNumero gerado: %d\n", nova_pessoa->numero);
    return nova_pessoa;
}

void lerParticipantes(pessoa *ptr)
{
    if (verificarFilaVazia(ptr) != 0)
    {
        printf("\n%s%d\n", ptr->nome, ptr->numero);
        lerParticipantes(ptr->prox);
    }
}

int restaUm(pessoa *ptr)
{
    if (ptr->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printGanhador(pessoa *ptr)
{
    printf("\n%s GANHOU O JOGO!!\n", ptr->nome);
}

void tirarUmDoJogo(pessoa *ptr, int num)
{
    if (ptr->numero == num)
    {
        printf("\nO JOGADOR RETIRADO FOI: %s | %d\n", ptr->nome, ptr->numero);
        if (ptr->ant != NULL)
        {
            ptr->ant->prox = ptr->prox;
        }
        if (ptr->prox != NULL)
        {
            ptr->prox->ant = ptr->ant;
        }
        free(ptr);
    }
    else
    {
        tirarUmDoJogo(ptr->prox, num);
    }
}

int main()
{
    srand(time(NULL));
    pessoa *pessoas = NULL;
    int op;
    int numParticipantes;
    int gameFlag=0;

    printf("BEM VINDO AO JOGO! PRIMEIRAMENTE VAMOS DECIDIR A QUANTIDADE DE PARTICIPANTES: ");
    fflush(stdin);
    scanf("%d", &numParticipantes);

    for (int i = 0; i < numParticipantes; i++)
    {
        pessoas = add(pessoas, numParticipantes);
    }

    printf("\nPRONTO! LISTA DE JOGADORES:\n");
    lerParticipantes(pessoas);

    do
    {
        printf("\nSAIR [0] | LER LISTA DE PARTICIPANTES [1] | SORTEAR UM JOGADOR PARA SAIR [2]\n");

        fflush(stdin);
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nSAINDO!...\n");
            _sleep(2000);
            break;

        case 1:
            lerParticipantes(pessoas);
            break;

        case 2:
            printf("\nSORTEANDO NUMERO!...\n");
            _sleep(3000);
            tirarUmDoJogo(pessoas, (rand() % numParticipantes + 1));
            if(restaUm(pessoas)==1){
                printGanhador(pessoas);
                gameFlag=1;
            }
            break;

        default:
            printf("\nCOMANDO INVÁLIDO!\n");
            break;
        }
    } while (op != 0 && gameFlag==0);
    return 0;
}