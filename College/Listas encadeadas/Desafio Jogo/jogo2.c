#include <stdio.h>
#include <stdlib.h>
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
            return procurarPorIguais(ptr->prox, num);
        }
    }

    return 0;
}

int atribuirNumeroNaoEscolhido(pessoa *ptr, int num, int MaxValue)
{
    if (procurarPorIguais(ptr, num) != 1)
    {
        return num;
    }
    else
    {
        return atribuirNumeroNaoEscolhido(ptr, sortNum(MaxValue), MaxValue);
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
    return (ptr != NULL && ptr->prox == NULL);
}

void printGanhador(pessoa *ptr)
{
    printf("\n%s GANHOU O JOGO!!\n", ptr->nome);
}

void tirarUmDoJogo(pessoa **ptr, int numParticipantes)
{
    if (*ptr != NULL)
    {
        int numSorteado = sortNum(numParticipantes);
        printf("\nSORTEANDO NUMERO!...\n");

        pessoa *atual = *ptr;
        pessoa *anterior = NULL;

        while (atual != NULL && atual->numero != numSorteado)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual != NULL)
        {
            printf("\nO JOGADOR RETIRADO FOI: %s | %d\n", atual->nome, atual->numero);

            if (anterior != NULL)
            {
                anterior->prox = atual->prox;
            }
            else
            {
                *ptr = atual->prox;
            }

            if (atual->prox != NULL)
            {
                atual->prox->ant = anterior;
            }

            free(atual);
        }
        else
        {
            printf("\nNINGUEM FOI SELECIONADO DESTA VEZ!\n");
        }
    }
    else
    {
        printf("\nNINGUEM FOI SELECIONADO DESTA VEZ!\n");
    }
}

void limparLista(pessoa *ptr)
{
    pessoa *prox = ptr->prox;
    free(ptr);

    if (prox != NULL)
    {
        limparLista(prox);
    }
}

int main()
{
    srand(time(NULL));
    pessoa *pessoas = NULL;
    int op;
    int numParticipantes;
    int gameFlag = 0;

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
            limparLista(pessoas);
            break;

        case 1:
            lerParticipantes(pessoas);
            break;

        case 2:
            tirarUmDoJogo(&pessoas, numParticipantes);

            if (restaUm(pessoas) == 1)
            {
                printGanhador(pessoas);
                limparLista(pessoas);
                gameFlag = 1;
            }

            break;

        default:
            printf("\nCOMANDO INVALIDO!\n");
            break;
        }
    } while (op != 0 && gameFlag == 0);

    return 0;
}
