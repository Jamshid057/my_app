#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void welcome();
int loadQuestions(char*** questions, char*** answers, int* count);
int getRandomIndex(int max);
void playGame(char* question, char* answer);
void displayProgress(char* currentStatus, int length);
int checkGuess(char guess, char* answer, char* currentStatus, int length);
void endGame(int win, char* correctAnswer);
void logResult(const char* question, const char* answer, int win);

#endif
