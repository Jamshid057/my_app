#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main() {

	printf("\n\n\t *** Kompyuter o'ylagan sonni toping *** \n\n");
	srand(time(NULL));
	int x,son, urinish = 0;
	x = rand() % 100;

	do {
		urinish += 1;
		printf("Sonni kiriting ");
		scanf("%d",&son);
		if (x == son) {

			printf("Y u t u q ! ! !\nSiz sonni %d ta urinishda topdingiz\n",urinish);
			break;

		} else if (x > son)
			puts("Siz kichik son kiritdingiz");
		else
			puts("Katta son kiritdingiz");
		if (urinish == 7)
		{
			puts("Siz yutqazdingiz !\n");
			break;
		}

	} while (1);
	return 0;
}

