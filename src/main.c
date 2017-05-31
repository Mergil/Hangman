#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void igra(char *zagadka);

int main() {
    
    setlocale(LC_ALL,"rus");
    
    int i=0;
    
    srand(time(0));
    
    char *zagadka=malloc(sizeof(char*)*100);
    
    FILE *myfile;
    
    if ((myfile=fopen("book.txt","r"))) {
         while (fscanf(myfile,"%s",zagadka) != EOF) i++;
         if (i>0) {
            int j=rand()%i;
            fseek(myfile,0,SEEK_SET); /// В начало документа
            for (i=0;i<=j;i++) fscanf(myfile,"%s",zagadka);
                 zagadka=realloc(zagadka,sizeof(char*)*strlen(zagadka)); /// Выделение новой памяти
            } else i=-1;
    } else myfile=fopen("book.txt","w");
                  
    fclose(myfile);
               
    if (i==-1) {
        printf("\n Слов для загадки не найдено! Добавьте слова в файл и повторите попытку.\n\n");
    } else igra(zagadka);

    return 0;

}

void igra(char *zagadka) {
char otvet[strlen(zagadka)];
char *otvet_tmp=malloc(sizeof(char*)*100);
int i,hp=6;
for (i=0;i<strlen(zagadka);i++) otvet[i]='_';
otvet[i++]='\0';
while (hp>0 && strcmp(zagadka,otvet)) {
system("cls");
if (hp<6) printf("\n Вы ошиблись! \n");
printf("\n Слово: %s",otvet);
printf("\n\n HP = %d. Введите букву или слово целиком: ",hp);
scanf("%s",otvet_tmp);
if (strlen(otvet_tmp)==1) {
int a=0;
for (i=0;i<strlen(zagadka);i++) {
if (otvet_tmp[0]==zagadka[i]) {
otvet[i]=zagadka[i];
a++;
}
}
if (a==0) hp--;
} else {
if (strcmp(zagadka,otvet_tmp)==0) {
for (i=0;i<strlen(zagadka);i++) otvet[i]=zagadka[i];
} else hp--;
}
}
