#include <stdio.h>

int main() {
	int min = 0, max = 100;
	int comp_guessed;
	char user_input;

	do {
		comp_guessed = ( min + max ) / 2;
		printf("It's your number %d ? ( l = lower, h = higher, y = yes )\n", comp_guessed);
		scanf(" %c", &user_input);
		
		if (user_input == 'h') {
			min = comp_guessed;
		}else if (user_input == 'l') {
			max = comp_guessed;
		}
	
	} while ( user_input != 'y');

	puts("I won !!!");

	return 0;
}
