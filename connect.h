#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int player1Choose(int cols, int rows, int** board);
int player2Choose(int cols, int rows, int** board);
int aiChoose(int cols, int rows, int** board, int* placed, int prevCol);
bool checkIfWon(int width, int height, int** board, int* placed, int column);
int aiHelper(int width, int height, int** board, int col, int row);