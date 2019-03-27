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
#include <stdbool.h>
#include "connect.h"

void printBoard(int cols, int rows, int board[cols][rows]){
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
}//this is gonna need a lot of adjustment but for now it does the job. 

int main(void){
	int player1score = 0;
	int player2score = 0;
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
	bool isWon = false;
	bool boardFilled = false;
	int piecesPlaced = 0;

	while (wantsToPlay){
printf("main check 11\n");
		int board[wide][tall];
		int placed[wide];
		int i, j;
		for (i = 0; i < wide; i++){
			for (j = 0; j < tall; j++){
				board[i][j] = -1;
			}
			placed[i] = 0;
		}
printf("main check 12\n");
		gameFinished = false;
		fourConnected = false;
		boardFilled = false;
		piecesPlaced = 0;
		int boardSize = tall * wide;
		int playerWon = 0; //0 for not won yet, 1 for player 1, 2 for player 2, 3 forr AI;
		int player = 2;
		int currentCol = -1;   printf("main check 13\n");
		int currentRow = -1;
		while (!gameFinished){
			if (player == 1){
				player = 2;
			}
			else {player = 1;}
			if (alone){
				player = 1;
			}

			printBoard(wide, tall, board);   printf("main check 14\n");
			
			if (player == 1){
				currentCol = player1Choose(wide, tall, board);
				currentRow = placed[currentCol];
				board[currentCol][currentRow] = 1;

			}   printf("main check 15\n");
			if (player == 2){
				if (ai){
					currentCol = aiChoose(wide, tall, board, currentCol);
					currentRow = placed[currentCol];
					board[currentCol][currentRow] = 2;
				}
				else {
					currentCol = player2Choose(wide, tall, board);
					currentRow = placed[currentCol];
					board[currentCol][currentRow] = 2;
				}
				
			}   printf("main check 16\n");
printf("placing a piece for %d in row %d and column %d\n", player, currentRow, currentCol);
			piecesPlaced++;
			placed[currentCol]++;
			fourConnected = checkIfWon(wide, tall, board, placed, currentCol);
			if (fourConnected) {gameFinished = true; playerWon = player; break;}
printf("main check 17\n");
			if (piecesPlaced >= boardSize) {boardFilled = true; gameFinished = true; playerWon = 0;}
		}

		if (playerWon == 0) {printf("The board has been filled and no one scored a point.\n");}
		if (playerWon == 1) score1++;
		if (playerWon == 2) score2++;
		printf("The score: Player 1 has %d points and ", score1);
		if (ai) printf("the AI has %d points.\n", score2);
		else printf("Player 2 has %d points.\n", score2);
		printf("Would you like to play again? Y/N\n");//y, yes, Y, Yes, n, no, N, No, YES, NO
		scanf("%s", answer);//do i need & here? not sure. apparently not
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
	return 0;
}

