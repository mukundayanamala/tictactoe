#include <stdio.h>
#include <stdlib.h>

char board[3][3];
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces() {
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void playerMove(char player) {
    int row, col;
    do {
        printf("Player %c, enter row (0-2): ", player);
        scanf("%d", &row);
        printf("Player %c, enter column (0-2): ", player);
        scanf("%d", &col);
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move!\n");
        } else if (board[row][col] != ' ') {
            printf("Position is taken!\n");
        } else {
            board[row][col] = player;
            break;
        }
    } while (1);
}

char checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' ';
}

void printWinner(char winner) {
    if (winner == PLAYER_X) {
        printf("Player X wins!\n");
    } else if (winner == PLAYER_O) {
        printf("Player O wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    char winner = ' ';
    resetBoard();

    while (winner == ' ' && checkFreeSpaces() != 0) {
        printBoard();
        playerMove(PLAYER_X);
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0) {
            break;
        }
        printBoard();
        playerMove(PLAYER_O);
        winner = checkWinner();
    }
    printBoard();
    printWinner(winner);
    return 0;
}