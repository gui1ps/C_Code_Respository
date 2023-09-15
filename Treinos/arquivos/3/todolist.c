#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

FILE *file;
int resp;


void welcome();
void ask();
void exitanimation();
void invalid();
void readlist(FILE *f);

typedef struct{
    int hours;
    int minute;
}timen;

typedef struct{
    int day;
    int month;
    int year;
}date;

typedef struct{
    timen t;
    date d;
}fulldate;

typedef struct{
    fulldate f;
    char *title;
    char *desc;
}task;

typedef struct{
    task list[20];
}todolist;

task t;
todolist tl;

void createtfd(task tk);
void creattt(task *tk);
void creattd(task *tk);
void fprinttask(task tk, FILE *f);
void addtask(todolist *tl,task t);
void runtodolist(todolist *tl);

int main(){

    welcome();

    do{
        fflush(stdin);
        ask();
        scanf("%d",&resp);
        system("cls");

        switch (resp){

        case 1:
            readlist(file);
            break;
        case 2:
            createtfd(t);
            creattt(&t);
            creattd(&t);
            addtask(&tl,t);
            runtodolist(&tl);
            //fprinttask(t,file);
            //free(t.title);
            //free(t.desc);
            break;
        case 4:
            exitanimation();
            break;
        
        default:
            invalid();
            break;
        }
    }while (resp!=4);

    return 0;
}


void welcome(){
    printf("\n----------------------------------------------\n\tWELCOME TO YOUR TODO LIST!\n----------------------------------------------\n");
    Sleep(2000);
    system("cls");
}

void ask(){
    printf("\nOPTIONS: READ LIST [1] | ADD TASK [2] | DELETE TASK [3] | EXIT [4] >> ");
}

void exitanimation(){
    for(int i=0;i<6;i++){
        if(i%2==0){
            printf("LEAVING *+*");
            Sleep(800);
            system("cls");
        }
        else{
            printf("LEAVING +*+");
            Sleep(800);
            system("cls");
        }
    }
}

void invalid(){
   printf("INVALID!");
   Sleep(1000);
   system("cls");
}

void createtfd(task tk){

    int d,m,y,h,min;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int currentyear= tm.tm_year+1900;
    int currentday=tm.tm_mday;
    int currentmon=tm.tm_mon;
    int currenth=tm.tm_hour;
    int currentmin=tm.tm_min;

    fflush(stdin);
    printf("DAY: ");
    scanf("%d",&d);
    system("cls");
    fflush(stdin);
    printf("MONTH: ");
    scanf("%d",&m);
    system("cls");
    fflush(stdin);

    printf("YEAR: ");
    scanf("%d",&y);
    system("cls");
    fflush(stdin);
    printf("HOUR: ");
    scanf("%d",&h);
    system("cls");
    fflush(stdin);
    printf("MINUTE: ");
    scanf("%d",&min);
    system("cls");
    fflush(stdin);

    if(d>=1 && d<=31){
        if(m>=1 && m<=12){
            if(y>=currentyear){
                if(h>=0 && h<=23){
                    if(min>=0 && m<=59){
                        fulldate date;
                        date.d.year=y;
                        date.d.month=m;
                        date.d.day=d;
                        date.t.hours=h;                        
                        date.t.minute=min;
                        tk.f=date;                        
                    }
                }
            }
        }
    }

    system("cls");
}

void creattt(task *tk){
    fflush(stdin);
    size_t buffsize=200;
    printf("TITLE: ");
    tk->title=(char *)malloc(200 * sizeof(char));
    if (tk->title == NULL) {
        printf("Erro na alocação de memória para 'title'\n");
        exit(1);
    }
    getline(&(tk->title),&buffsize,stdin);
    system("cls");
}

void creattd(task *tk){
    fflush(stdin);
    size_t buffsize=700;
    printf("DESCRIPTION: ");
    tk->desc= (char *)malloc(700 * sizeof(char));
    if (tk->desc == NULL) {
        printf("Erro na alocação de memória para 'title'\n");
        exit(1);
    }
    getline(&(tk->desc),&buffsize,stdin);
    system("cls");
};

void fprinttask(task tk, FILE *f){
    f=fopen("todo_teste.txt","a");
    fprintf(f,"\n>>\n %s \n %s",tk.title,tk.desc);
    fclose(f);
}

void readlist(FILE *f){
    char buffer[700];
    f=fopen("todo_teste.txt","r");
    while (fgets(buffer,sizeof(buffer),f)!=NULL)
    {
        printf("%s",buffer);
    }   
}

void addtask(todolist *tl,task t){
    static num=0;
    if(num<21){
        tl->list[num]=t;
    }
    num++;
}

void runtodolist(todolist *tl){
    static int i=0;
    while (tl->list[i].desc!=NULL && tl->list[i].title!=NULL)
    {
        fprinttask(tl->list[i],file);
        free(tl->list[i].title);
        free(tl->list[i].desc);
        i++;
    }
}