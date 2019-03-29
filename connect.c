
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "connect.h"

int player1Choose(int cols, int rows, int board[cols][rows]){//this prompts player 1 for the column to place a piece in. the main function handles all changes to the board
	int col = -1;
	bool validAnswer = false;
	printf("\nWhich column would player 1 like to place a piece in? Please enter a valid number.\n");
	scanf("%d", &col);
	if (col >= 0 && col < cols){
		if (board[col][rows-1] == -1){
		validAnswer = true;
		}
	}
	while (!validAnswer){
		printf("That is not a valid column choice, please try again.\n");
		scanf("%d", &col);
		if (col >= 0 && col < cols){
			if (board[col][rows-1] == -1){
			validAnswer = true;
			}
		}
	return col;
}

int player2Choose(int cols, int rows, int board[cols][rows]){//almost the exact same as player1choose. but I like having these seperate.
	int col = -1;
	bool validAnswer = false;
	printf("Which column would player 2 like to place a piece in? Please enter a valid number.\n");
	scanf("%d", &col);
	if (col >= 0 && col < cols){
		if (board[col][rows-1] == -1){
		validAnswer = true;
		}
	}
	while (!validAnswer){
		printf("That is not a valid column choice, please try again.\n");
				scanf("%d", &col);
		if (col >= 0 && col < cols){
			if (board[col][rows-1] == -1){
			validAnswer = true;
			}
		}
	}
	return col;
}

int aiChoose(int cols, int rows, int board[cols][rows], int placed[cols], int prevCol){//this uses an algorithm to decide the next place to put a piece.
	int col = -1;
	int prevRow = placed[prevCol];
	col = aiHelper(cols, rows, board, prevCol, prevRow); //this function just returns the column that would potentially block the next item.
	if (col >= cols) col = cols-1;
	while (board[col][rows-1] != -1){//this is just to make sure its not placing a piece out of bounds. 
		col--;
		if (col<0) col = cols-1;
	}
	printf("The AI has placed a piece in column %d.\n", col);//this just tells the user where the AI has placed a piece. its helpful for debugging.
	return col;
}

bool checkIfWon(int width, int height, int board[width][height], int placed[width], int column){//this checks if someone has won.
	//it only checks the most recently placed piece, since its impossible to have won without the win relating to the recently placed piece.
	int row = placed[column]-1;
	int count = 1; 
	int player = board[column][row];
	bool broken = false;
	int i = column; 
	int j = row; 
	while (!broken){//upleft
		if (i-1<0) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i-1][j+1] == player){
			count++; i--; j++;
		}
		else if (board[i-1][j+1] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	while (!broken){//downright
		if (j-1<0) {broken = true; break;}
		if (i+1>=width) {broken = true; break;}
		if (board[i+1][j-1] == player){
			count++; i++; j--;
		}
		else if (board[i+1][j-1] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	count = 1;	
	while (!broken){//upright
		if (i+1>=width) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i+1][j+1] == player){
			count++; i++; j++;
		}
		else if (board[i+1][j+1] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	while (!broken){//downleft
		if (j-1<0) {broken = true; break;}
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j-1] == player){
			count++; i--; j--;
		}
		else if (board[i-1][j-1] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	count = 1;
	while (!broken){//left
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j] == player){
			count++; i--; 
		}
		else if (board[i-1][j] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	while (!broken){//right
		if (i+1>=width) {broken = true; break;}
		else if (board[i+1][j] == player){
			count++; i++; 
		}
		else if (board[i+1][j] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	i = column;
	j = row;
	broken = false;
	count = 1;
	while (!broken){//down
		if (j-1<0) {broken = true; break;}
		if (board[i][j-1] == player){
			count++; j--;
		}
		else if (board[i][j-1] != player){broken = true; break;}
		if (count>=4) {return true;}
	}
	return false;
}

int aiHelper(int width, int height, int board[width][height], int col, int row){//this is based off of my checkifwon function, but used for the AI
	int count = 1; 
	bool broken = false;
	int i = col; 
	int j = row; 
	while (!broken){//upleft
		if (i-1<0) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i-1][j+1] == 1){
			count++; i--; j++;
		}
		else if (board[i-1][j+1] != 1){broken = true; break;}
		if (count>=3) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//downright
		if (j-1<0) {broken = true; break;}
		if (i+1>=width) {broken = true; break;}
		if (board[i+1][j-1] == 1){
			count++; i++; j--;
		}
		else if (board[i+1][j-1] != 1){broken = true; break;}
		if (count>=3) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;	


	while (!broken){//upright
		if (i+1>=width) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i+1][j+1] == 1){
			count++; i++; j++;
		}
		else if (board[i+1][j+1] != 1){broken = true; break;}
		if (count>=3) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//downleft
		if (j-1<0) {broken = true; break;}
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j-1] == 1){
			count++; i--; j--;
		}
		else if (board[i-1][j-1] != 1){broken = true; break;}
		if (count>=3) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;


	while (!broken){//left
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j] == 1){
			count++; i--; 
		}
		else if (board[i-1][j] != 1){broken = true; break;}
		if (count>=3) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//right
		if (i+1>=width) {broken = true; break;}
		if (board[i+1][j] == 1){
			count++; i++; 
		}
		else if (board[i+1][j] != 1){broken = true; break;}
		if (count>=3) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;

	while (!broken){//down
		if (j-1<0) {broken = true; break;}
		if (board[i][j-1] == 1){
			count++; j--;
		}
		else if (board[i][j-1] != 1){broken = true; break;}
		if (count>=3) {return i;}
	}
	//return i;

	while (!broken){//upleft
		if (i-1<0) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i-1][j+1] == 1){
			count++; i--; j++;
		}
		else if (board[i-1][j+1] != 1){broken = true; break;}
		if (count>=2) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//downright
		if (j-1<0) {broken = true; break;}
		if (i+1>=width) {broken = true; break;}
		if (board[i+1][j-1] == 1){
			count++; i++; j--;
		}
		else if (board[i+1][j-1] != 1){broken = true; break;}
		if (count>=2) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;	


	while (!broken){//upright
		if (i+1>=width) {broken = true; break;}
		if (j+1>=height) {broken = true; break;}
		if (board[i+1][j+1] == 1){
			count++; i++; j++;
		}
		else if (board[i+1][j+1] != 1){broken = true; break;}
		if (count>=2) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//downleft
		if (j-1<0) {broken = true; break;}
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j-1] == 1){
			count++; i--; j--;
		}
		else if (board[i-1][j-1] != 1){broken = true; break;}
		if (count>=2) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;


	while (!broken){//left
		if (i-1<0) {broken = true; break;}
		if (board[i-1][j] == 1){
			count++; i--; 
		}
		else if (board[i-1][j] != 1){broken = true; break;}
		if (count>=2) {return i-1;}
	}
	i = col;
	j = row;
	broken = false;
	while (!broken){//right
		if (i+1>=width) {broken = true; break;}
		if (board[i+1][j] == 1){
			count++; i++; 
		}
		else if (board[i+1][j] != 1){broken = true; break;}
		if (count>=2) {return i+1;}
	}
	i = col;
	j = row;
	broken = false;
	count = 1;

	while (!broken){//down
		if (j-1<0) {broken = true; break;}
		if (board[i][j-1] == 1){
			count++; j--;
		}
		else if (board[i][j-1] != 1){broken = true; break;}
		if (count>=2) {return i;}
	}

	//if it has reached this point, then theres only one piece in a row. 
	if (col > col/2){//the idea for this is to put the piece as close to the middle as possible while still interfering with the placed piece from player 1. 
		return col-1; 
	}
return col+1;
}


