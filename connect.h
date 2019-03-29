#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int player1Choose(int cols, int rows, int board[cols][rows]);
int player2Choose(int cols, int rows, int board[cols][rows]);
int aiChoose(int cols, int rows, int board[cols][rows], int placed[cols], int prevCol);
bool checkIfWon(int width, int height, int board[width][height], int placed[width], int column);
int aiHelper(int width, int height, int board[width][height], int col, int row);