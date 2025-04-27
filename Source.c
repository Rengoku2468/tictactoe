#include <stdio.h>
#include <stdint.h>


#define matrix_len  3
// to create the grid layout for the tic tac toe.
char matrix[matrix_len][matrix_len] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},

};
//to check for the winner of the game
int winner() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != '-') {
            printf("\nPlayer %c wins!\n", matrix[i][0]);
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != '-') {
            printf("\nPlayer %c wins!\n", matrix[0][i]);
            return 1;
        }
    }
    // check diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != '-') {
        printf("\nPlayer %c wins!\n", matrix[0][0]);
        return 1;
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != '-') {
        printf("\nPlayer %c wins!\n", matrix[0][2]);
        return 1;
    }
    return 0;
}

// this helps to initialize the first table.
void firsttable() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            printf("%c\t|\t", matrix[row][col]);
        }
        printf("\n\n");
    }
}
void initializegame(int rowan, int columnan, char var) {
    char* ptr = &matrix[rowan][columnan];
    *ptr = var;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            printf("%c\t|\t", matrix[row][col]);
        }
        printf("\n\n");
    }
}
int main() {
    printf("tictactoe-game\n");
    firsttable();
    int max_plays = 9;
    int rowa, columna;
    for (int play = 0; play < max_plays; play++) {
        if (play % 2 == 0) {
            while (1)
            {
                printf("player x's turn\nselect an empty row and column:\n");
                scanf_s("%d", &rowa);
                scanf_s("%d", &columna);
                if (rowa >= 0 && rowa <= 2 && columna >= 0 && columna <= 2)
                {
                    if (matrix[rowa][columna] == 'x' || matrix[rowa][columna] == 'o')
                    {
                        printf("please select an empty grid");
                    }
                    else
                    {
                        matrix[rowa][columna] = 'x';
                        initializegame(rowa, columna, 'x');
                        winner();
                        break;
                    }
                }
                else {
                    printf("PLEASE SELECT A VALID INPUT");
                }
            }

        }
        else {
            while (1)
            {
                printf("player O's turn");
                scanf_s("%d", &rowa);
                scanf_s("%d", &columna);
                if (rowa >= 0 && rowa <= 2 && columna >= 0 && columna <= 2)
                {
                    if (matrix[rowa][columna] == 'x' || matrix[rowa][columna] == 'o')
                    {
                        printf("please select an empty grid");
                    }
                    else
                    {
                        matrix[rowa][columna] = 'o';
                        initializegame(rowa, columna, 'o');
                        winner();
                        break;
                    }
                }
                else {
                    printf("PLEASE SELECT A VALID INPUT");
                }
            }
        }
    }



}