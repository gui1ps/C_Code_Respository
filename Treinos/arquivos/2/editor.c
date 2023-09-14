#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void boasvindas();
void opcoes();

int main(){
    int resp;
    char path[200];
    char buffer[500];
    char method;
    FILE *file;

    boasvindas();
    Sleep(2000);
    system("cls");

    do{
        fflush(stdin);
        opcoes();
        scanf("%d",&resp);
        system("cls");

        switch (resp){
        case 1:
            printf("\nPATH DO ARQUIVO >> ");
            fflush(stdin);

            if(fgets(path,sizeof(path),stdin)!=NULL){
                size_t len=strlen(path);
                if(len>0 && path[len-1]=='\n'){
                    path[len-1]='\0';
                }
            }
            else{
                printf("\nALGO DEU ERRADO!\n");
                continue;
            }

            printf("\nESCREVER [w] | ADICIONAR [a] | LER [r] >>");
            fflush(stdin);
            method=getchar();
            system("cls");

            if(method=='W' || method=='w'){
                file=fopen(path,"w");
                fflush(stdin);
                printf(">> ");

                if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
                    size_t len=strlen(path);
                    if(len>0 && path[len-1]=='\n'){
                        path[len-1]='\0';
                    }
                }
                else{
                    printf("\nALGO DEU ERRADO!\n");
                }
                fprintf(file,buffer);
                fclose(file);
            }
            else if (method=='R' || method=='r')
            {
                file=fopen(path,"r");
                while (fgets(buffer,sizeof(buffer),file)!=NULL)
                {
                    printf("%s",buffer);
                }
                fclose(file);
            }
            else if (method=='A' || method=='a')
            {
                file=fopen(path,"a");
                fflush(stdin);
                printf(">> ");

                if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
                    size_t len=strlen(path);
                    if(len>0 && path[len-1]=='\n'){
                        path[len-1]='\0';
                    }
                }
                else{
                    printf("\nALGO DEU ERRADO!\n");
                }

                fprintf(file,buffer);
                fclose(file);
                }
                else{
                    printf("ERRO: COMANDO NAO CONHECIDO");
                    Sleep(1000);
                    system("cls");
                }
            
                break;

        case 2:
            for(int i=1;i<6;i++){
                if(i%2==0){
                    printf("\nSAINDO +.+\n");
                    Sleep(500);
                    system("cls");
                }
                else{
                    printf("\nSAINDO .+.\n");
                    Sleep(500);
                    system("cls");
                }
            }
            break;
        
        default:
            printf("\nERRO: COMANDO NÃO RECONHECIDO\n");
            system("cls");
            break;
        }

    }while(resp!=2);
    
    return 0;
}

void boasvindas(){
    printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n\tBEM VINDO(A) AO EDITOR DE TEXTO!\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
}

void opcoes(){
    printf("\nO QUE VOCE DESEJA FAZER AGORA: ABRIR ARQUIVO PARA EDITAR [1] | SAIR [2] >>");
}