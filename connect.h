#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int player1Choose(int rows, int cols, int board[rows][cols]);
int player2Choose(int rows, int cols, int board[rows][cols]);
int aiChoose(int rows, int cols, int board[rows][cols], int prevCol);
bool checkIfWon(int width, int height, int board[width][height], int placed[width], int column);