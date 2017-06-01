#include "game.h"

void igra(char *zagadka) {
	char otvet[strlen(zagadka)];
	char *otvet_tmp = malloc(sizeof(char*) * 100);
	int i,hp = 6;

	for (i = 0; i < strlen(zagadka); i++)
		otvet[i] = '_';
	otvet[i++] = '\0';

	while (hp > 0 && strcmp(zagadka, otvet)) {
		system("cls");
		if (hp < 6)
			printf("\n Вы ошиблись! \n");
		printf("\n Слово: %s", otvet);
		printf("\n\n HP = %d. Введите букву или слово целиком: ", hp);
		scanf("%s", otvet_tmp);
		if (strlen(otvet_tmp) == 1) {
			int a = 0;
			for (i = 0; i < strlen(zagadka); i++) {
				if (otvet_tmp[0] == zagadka[i]) {
					otvet[i] = zagadka[i];
					a++;
				}
			}
			if (a == 0)
				hp--;
		} else {
			if (strcmp(zagadka,otvet_tmp)==0) {
				for (i=0;i<strlen(zagadka);i++) otvet[i]=zagadka[i];
			} else {
				hp--;
			}
	}
}

