#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "functions.h"

void welcome() {
    printf("=== Pole Chudes ===\n");
    printf("Qoidalarga ko‘ra, sizga bir savol beriladi va siz javobni harfma-harf topishingiz kerak.\n");
    printf("Har safar bitta harf kiriting. 6 ta noto‘g‘ri urinishdan keyin o‘yin tugaydi.\n\n");
}

int loadQuestions(char*** questions, char*** answers, int* count) {
    FILE* file = fopen("questions.txt", "r");
    if (!file) {
        printf("Fayl ochilmadi.\n");
        return 0;
    }

    char buffer[256];
    int capacity = 10;
    *questions = malloc(capacity * sizeof(char*));
    *answers = malloc(capacity * sizeof(char*));
    *count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        (*questions)[*count] = strdup(buffer);

        if (!fgets(buffer, sizeof(buffer), file)) break;
        buffer[strcspn(buffer, "\n")] = '\0';
        (*answers)[*count] = strdup(buffer);

        (*count)++;
        if (*count >= capacity) {
            capacity *= 2;
            *questions = realloc(*questions, capacity * sizeof(char*));
            *answers = realloc(*answers, capacity * sizeof(char*));
        }
    }

    fclose(file);
    return 1;
}

int getRandomIndex(int max) {
    return rand() % max;
}

void playGame(char* question, char* answer) {
    int length = strlen(answer);
    char currentStatus[length + 1];
    for (int i = 0; i < length; i++) {
        currentStatus[i] = (answer[i] == ' ') ? ' ' : '_';
    }
    currentStatus[length] = '\0';

    int attempts = 6;
    char guess;
    int found;
    char usedLetters[100] = {0};
    int usedCount = 0;

    printf("Savol: %s\n", question);

    while (attempts > 0) {
        displayProgress(currentStatus, length);
        printf("Harf kiriting: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        int alreadyUsed = 0;
        for (int i = 0; i < usedCount; i++) {
            if (usedLetters[i] == guess) {
                alreadyUsed = 1;
                break;
            }
        }
        if (alreadyUsed) {
            printf("Bu harfni allaqachon kiritgansiz!\n");
            continue;
        }
        usedLetters[usedCount++] = guess;

        found = checkGuess(guess, answer, currentStatus, length);
        if (!found) {
            attempts--;
            printf("Xato! Qolgan urinishlar: %d\n", attempts);
        }

        if (strcmp(currentStatus, answer) == 0) {
            printf("Tabriklayman! To‘g‘ri javob: %s\n", answer);
            logResult(question, answer, 1);
            return;
        }
    }

    printf("Afsus! Urinishlar tugadi. To‘g‘ri javob: %s\n", answer);
    logResult(question, answer, 0);
}

void displayProgress(char* currentStatus, int length) {
    printf("Javob: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", currentStatus[i]);
    }
    printf("\n");
}

int checkGuess(char guess, char* answer, char* currentStatus, int length) {
    int found = 0;
    for (int i = 0; i < length; i++) {
        if (tolower(answer[i]) == guess && currentStatus[i] == '_') {
            currentStatus[i] = answer[i];
            found = 1;
        }
    }
    return found;
}

void logResult(const char* question, const char* answer, int win) {
    FILE* log = fopen("game_log.txt", "a");
    if (!log) return;
    fprintf(log, "Savol: %s\nJavob: %s\nNatija: %s\n\n", question, answer, win ? "Yutdi" : "Yutqazdi");
    fclose(log);
}
