#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));
    welcome();

    char** questions;
    char** answers;
    int count;

    if (!loadQuestions(&questions, &answers, &count)) {
        return 1;
    }

    int keepPlaying = 1;
    while (keepPlaying) {
        int index = getRandomIndex(count);
        playGame(questions[index], answers[index]);

        printf("Yana o‘ynaysizmi? (1 = ha, 0 = yo‘q): ");
        scanf("%d", &keepPlaying);
    }

    for (int i = 0; i < count; i++) {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);

    printf("O‘yin tugadi. Rahmat!\n");
    return 0;
}
