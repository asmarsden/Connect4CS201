/*sets scores to 0 just for safety measure
prompts user for type of game (vs ai or vs other person), then sets the proper variable to 2 or 3
start a loop type thing here that breaks if player doesnt want to play anymore
prompts user for board size, checks if valid, then sends that to createBoard (or just initializes it in here? hmm. yeah just initialize
 it in here)
once everythings set, it enters a loop (while (connect4 == false && full == false) (if either of those == true then it breaks)
call player1choose
call player1placed
call checkifWon
call checkifFull (could just check within main)
call player2 or aichoose
call player2 or aiplaced
call checkifWon
call checkifFull (could just check within main)
repeat

if full == true then its a draw
if not, then there are two variables for scores that get updated
prompt if player would like to play again
if yes, do not erase scores
if not, erase scores then goto start of program somehow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connect.h"

int player1score;
int player2score;

int main(void){
	player1score = 0;
	player2score = 0;
	bool validAnswer = false;
	bool ai = false;
	char[8] answer;
	int checkAnswer = -1;
	printf("Welcome. Would you like to play against AI or against another player? 
			Please enter 'AI' or 'player'.\n");
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
	}
	validAnswer = false;
	printf("Very well. What size would you like the board to be? Please enter in format #x#.\n
		Note that board sizes over 40x40 may not function as intended, and board sizes under 4x4 are disabled.\n");
	int tall = -1;
	int wide = -1;
	char placeholder;
	scanf("%d", wide);
	scanf("%c", placeholder);
	scanf("%d", tall);
	if (wide > 3 && tall > 3){
		validAnswer = true;
	}
	while (!validAnswer){
		printf("Sorry, that isn't a valid answer. Please try again.\n");
		scanf("%d", wide);
		scanf("%c", placeholder);
		scanf("%d", tall);
		if (wide > 3 && tall > 3){
			validAnswer = true;
		}
	}
	validAnswer = false;

	bool wantsToPlay = true;
	int score1 = 0;
	int score2 = 0;
	bool gameFinished = false;
	bool isWon = false;
	bool boardFilled = false;
	int piecesPlaced = 0;

	while (wantsToPlay){
		int board[wide][tall];
		int i, j;
		for (i = 0; i < wide; i++){
			for (j = 0; j < tall; j++){
				board[i][j] = -1;
			}
		}
		
		gameFinished = false;
		fourConnected = false;
		boardFilled = false;
		piecesPlaced = 0;
		int boardSize = tall * wide;
		int playerWon = 0; //0 for not won yet, 1 for player 1, 2 for player 2, 3 forr AI;
		int player = 2;
		int currentCol = -1;
		while (!gameFinished){
			if (player == 1){
				if (ai) player == 3;
				else player == 2;
			}
			if (player != 1) {player = 1;}

			printBoard(wide, tall, board);
			
			if (player == 1){
				currentCol = player1Choose(wide, tall, board);
			}
			if (player == 2){
				if (ai){
					currentCol = aiChoose(wide, tall, board, currentCol);
				}
				else currentCol = player2Choose(wide, tall, board);
			}

			piecesPlaced++;
			fourConnected = checkIfWon(wide, tall, board, currentCol);
			if (fourConnected) {gameFinished = true; playerWon = player; break;}

			if (piecesPlaced >= boardSize) {boardFilled = true; gameFinished = true; playerWon = 0;}
		}

		if (playerWon == 0) {printf("The board has been filled and no one scored a point.\n");}
		if (playerWon == 1) score1++;
		if (playerWon == 2) score2++;
		printf("The score: Player 1 has %d points and ", score1);
		if (ai) printf("the AI has %d points.\n", score2);
		else printf("Player 2 has %d points.\n", score2);
		printf("Would you like to play again? Y/N\n");//y, yes, Y, Yes, n, no, N, No, YES, NO
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
		//do i need to free the board? hmm
	}
}

void printBoard(int cols, int rows, int* board){
	system("clear");
	int i = 0; int j = 0;
	for (j = 0; j < cols; j++){
		printf(' %d ', j);
	}
	printf('\n');
	for (i = 0; i < rows, i++){
		for (j = 0; j < cols, j++){
			printf(' _ ');
		}
		printf('\n');
		for (j = 0; j < cols, j++){
			printf('|%d', board[j][i]);
		}
		printf('|\n');
	}
	for (j = 0; j < cols, j++){
		printf(' _ ');
	}
	return;
}