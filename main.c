/*
I sincerely apologize for how ugly and redundant this code is. it was worse. this is an improvement.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "connect.h"

void printBoard(int cols, int rows, int board[cols][rows]){//the board is ugly, but it works. i think the printing of the board is what takes the most time.
	system("clear");
	int i = 0; int j = 0;
	for (j = 0; j < cols; j++){
		printf(" %d", j);
	}
	printf("\n");
	for (i = rows-1; i >= 0; i--){
		for (j = 0; j < cols; j++){
			printf(" _");
		}
		printf("\n");
		for (j = 0; j < cols; j++){
			if (board[j][i] != -1){
			printf("|%d", board[j][i]);}
			else printf("| ");
		}
		printf("|\n");
	}
	for (j = 0; j < cols; j++){
		printf(" _");
	}
	return;
}

int main(void){
	bool validAnswer = false;
	bool ai = false;
	bool alone = false;
	char answer[12];
	int checkAnswer = -1;
	printf("Welcome. Would you like to play alone, against AI, or against another player? \nPlease enter 'alone', 'AI', or 'player'.\n");
	//scan in answer: ai, AI, Ai, player, Player
	scanf("%s", answer);
	checkAnswer = strcmp(answer, "AI");
	if (checkAnswer == 0){
		validAnswer = true;
		ai = true;
	}
	checkAnswer = strcmp(answer, "ai");
	if (checkAnswer == 0){
		validAnswer = true;
		ai = true;
	}
	checkAnswer = strcmp(answer, "Ai");
	if (checkAnswer == 0){
		validAnswer = true;
		ai = true;
	}
	checkAnswer = strcmp(answer, "player");
	if (checkAnswer == 0){
		validAnswer = true;
	}
	checkAnswer = strcmp(answer, "Player");
	if (checkAnswer == 0){
		validAnswer = true;
	}
	checkAnswer = strcmp(answer, "alone");
	if (checkAnswer == 0){
		validAnswer = true;
		alone = true;
	}
	checkAnswer = strcmp(answer, "Alone");
	if (checkAnswer == 0){
		validAnswer = true;
		alone = true;
	}
	while(!validAnswer){
		printf("Sorry, that isn't a valid answer. Please try again.\n");
		//scan in answer
		scanf("%s", answer);
		checkAnswer = strcmp(answer, "AI");
		if (checkAnswer == 0){
			validAnswer = true;
			ai = true;
		}
		checkAnswer = strcmp(answer, "ai");
		if (checkAnswer == 0){
			validAnswer = true;
			ai = true;
		}
		checkAnswer = strcmp(answer, "Ai");
		if (checkAnswer == 0){
			validAnswer = true;
			ai = true;
		}
		checkAnswer = strcmp(answer, "player");
		if (checkAnswer == 0){
			validAnswer = true;
		}
		checkAnswer = strcmp(answer, "Player");
		if (checkAnswer == 0){
			validAnswer = true;
		}
		checkAnswer = strcmp(answer, "alone");
		if (checkAnswer == 0){
			validAnswer = true;
			alone = true;
		}
		checkAnswer = strcmp(answer, "Alone");
		if (checkAnswer == 0){
			validAnswer = true;
			alone = true;
		}
	}
	validAnswer = false;
	printf("Very well. What size would you like the board to be? Please enter in format #x#. \nNote that board sizes over 40x40 may not function as intended, and board sizes under 4x4 are disabled.\n");
	int tall = -1;
	int wide = -1;
	char placeholder;
	scanf("%d", &wide);
	scanf("%c", &placeholder);
	scanf("%d", &tall);
	if (wide > 3 && tall > 3){
		validAnswer = true;
	}
	while (!validAnswer){
		printf("Sorry, that isn't a valid answer. Please try again.\n");
		scanf("%d", &wide);
		scanf("%c", &placeholder);
		scanf("%d", &tall);
		if (wide > 3 && tall > 3){
			validAnswer = true;
		}
	}
	validAnswer = false;
	bool wantsToPlay = true;
	int score1 = 0;
	int score2 = 0;
	bool gameFinished = false;
	bool fourConnected = false;
	int piecesPlaced = 0;
	while (wantsToPlay){
		int board[wide][tall];
				int i, j;
		int placed[wide];
		for (i = 0; i < wide; i++){
			for (j = 0; j < tall; j++){
				board[i][j] = -1;
			}
			placed[i] = 0;
		}
		gameFinished = false;
		fourConnected = false;
		piecesPlaced = 0;
		int boardSize = tall * wide;
		int playerWon = 0; //0 for not won yet, 1 for player 1, 2 for player 2 or ai
		int player = 2;
		int currentCol = -1;  
		int currentRow = -1;
		while (!gameFinished){
			if (player == 1){
				player = 2;
			}
			else {player = 1;}
			if (alone){
				player = 1;
			}
			printBoard(wide, tall, board);  
			if (player == 1){
				currentCol = player1Choose(wide, tall, board);
				currentRow = placed[currentCol];
				board[currentCol][currentRow] = 1;
			}   
			if (player == 2){
				if (ai){
					currentCol = aiChoose(wide, tall, board, placed, currentCol);
					currentRow = placed[currentCol];
					board[currentCol][currentRow] = 2;
				}
				else {
					currentCol = player2Choose(wide, tall, board);
					currentRow = placed[currentCol];
					board[currentCol][currentRow] = 2;
				}
			}
//printf("placing a piece for %d in row %d and column %d\n", player, currentRow, currentCol); //keeping this here for future debugging, just in case
			piecesPlaced++;
			placed[currentCol]++;
			fourConnected = checkIfWon(wide, tall, board, placed, currentCol);
			if (fourConnected) {gameFinished = true; playerWon = player; break;}
			if (piecesPlaced >= boardSize) {gameFinished = true; playerWon = 0;}
		}
		if (playerWon == 0) {printf("The board has been filled and no one scored a point.\n");}
		if (playerWon == 1) score1++;
		if (playerWon == 2) score2++;
		if (alone){
			printf("Congratulations, you have played %d time(s).\n", score1);
		}
		else{
			printf("The score: Player 1 has %d point(s) and ", score1);
			if (ai) printf("the AI has %d point(s).\n", score2);
			else printf("Player 2 has %d point(s).\n", score2);
		}
		printf("Would you like to play again? Y/N\n");//y, yes, Y, Yes, n, no, N, No, YES, NO. why did i decide to take in input this way this is so redundant
		scanf("%s", answer);
		checkAnswer = strcmp(answer, "Y");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = true;
		}
		checkAnswer = strcmp(answer, "y");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = true;
		}
		checkAnswer = strcmp(answer, "Yes");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = true;
		}
		checkAnswer = strcmp(answer, "YES");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = true;
		}
		checkAnswer = strcmp(answer, "yes");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = true;
		}
		checkAnswer = strcmp(answer, "n");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = false;
		}
		checkAnswer = strcmp(answer, "NO");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = false;
		}
		checkAnswer = strcmp(answer, "No");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = false;
		}
		checkAnswer = strcmp(answer, "N");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = false;
		}
		checkAnswer = strcmp(answer, "no");
		if (checkAnswer == 0){
			validAnswer = true;
			wantsToPlay = false;
		}
		while(!validAnswer){
			printf("Sorry, that is not a valid answer. Please try again.\n");
			scanf("%s", answer);
			checkAnswer = strcmp(answer, "Y");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = true;
			}
			checkAnswer = strcmp(answer, "y");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = true;
			}
			checkAnswer = strcmp(answer, "Yes");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = true;
			}
			checkAnswer = strcmp(answer, "YES");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = true;
			}
			checkAnswer = strcmp(answer, "yes");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = true;
			}
			checkAnswer = strcmp(answer, "n");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = false;
			}
			checkAnswer = strcmp(answer, "NO");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = false;
			}
			checkAnswer = strcmp(answer, "No");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = false;
			}
			checkAnswer = strcmp(answer, "N");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = false;
			}
			checkAnswer = strcmp(answer, "no");
			if (checkAnswer == 0){
				validAnswer = true;
				wantsToPlay = false;
			}
		}
	}
	printf("Hope you enjoyed playing!\n");
	return 0;
}

