#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, Enter row and column (0, 1, 2): ", player);
        scanf("%d %d", &row, &col);

        // Joyni tekshirish
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

int checkWinner(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return (board[i][0] == 'X') ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return (board[0][i] == 'X') ? 1 : 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 3;
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);

    int winner = 0;
    int currentPlayer = 1;
    while (winner == 0) {
        printBoard(board);

        playerMove(board, currentPlayer == 1 ? 'X' : 'O');

        winner = checkWinner(board);

 
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

	printBoard(board);
    if (winner == 1) {
        printf("Player 1 (X) wins!\n");
    } else if (winner == 2) {
        printf("Player 2 (O) wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
