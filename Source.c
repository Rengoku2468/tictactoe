#include <stdio.h>
// to create the grid layout for the tic tac toe.
char matrix[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},

};
// this helps to initialize the first table.
void firsttable() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            printf("%c\t|\t", matrix[row][col]);
        }
        printf("\n\n");
    }
}
// game logic.
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
            printf("player x's turn\nselect an empty row and column:\n");
            scanf_s("%d\n", &rowa);
            scanf_s("%d", &columna);
            matrix[rowa][columna] = 'x';
            initializegame(rowa, columna, 'x');

        }
        else {
            printf("player o's turn\nselect an empty row and column:");
            scanf_s("%i\n", &rowa);
            scanf_s("%i", &columna);
            matrix[rowa][columna] = 'o';
            initializegame(rowa, columna, 'o');
        }
    }
}