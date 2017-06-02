#include "game.h"

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
