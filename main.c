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
#include "ai.c"
#include "connect.c"
#include "structs.c"

int player1score;
int player2score;

int main(void){
	player1score = 0;
	player2score = 0;
	//prompt for game type
	//prompt for board size
	int tall = //readin;
	int wide = //readin;
	bool wantsToPlay = true;
	while (wantsToPlay){
		int* = createBoard(tall, wide);//figure out how to transfer 2 dimensional int arrays
		//create graph object;
		bool gameFinished = false;
		bool fourConnected = false;
		bool boardFilled = false;
		bool previousGame = false;
		int piecesPlaced = 0;
		int boardSize = tall * wide;
		int playerWon = 0; //0 for not won yet, 1 for player 1, 2 for player 2, 3 forr AI;
		int player = 1;
		bool ai = false;//check to see if this needs to be set to true during prompting shit
		while (!gameFinished){
			playGame(stuff){};//stuff == which player, ai or player2, the board itself, the graph, # of pieces
			piecesPlaced++;
			if (piecesPlaced >= boardSize) boardFilled = true;
			fourConnected = checkIfWon(stuff);
			if (fourConnected = true) {gameFinished = true; playerWon = player;}//update scores if needed, display proper thing
			if (boardFilled = true) gameFinished = true; //do not change scores. display  proper thing
			
			if (player == 1){
				if (ai) player == 3;
				else player == 2;
			}
			if (player != 1) {player = 1;}
		}
		//do stuff here for after game stuff, ask if theyd like to play again and updating scores
		if (player == 1){player1score++;}
		if (player == 2 || player == 3){player2score++;}
		player = 0;
		//somehow i gotta figure out how this will wrap around to up there again. hmmm. big big while loop? big big while loop.
		//free all the necessary stuff here
	}
}

void playGame(stuff){//remember there is a number that gets increased every time a piece gets placed
	if (player == 1){
		player1choose(board, graph, rows, cols);
		//this returns... the board and stuff? i guess?
	}
	if (player == 2){
		player2choose(board, graph, rows, cols);
		//this returns... the board and stuff? i guess?
	}
	if (player == 3){
		aiChoose(board, graph, rows, cols);
		//this returns... the board and stuff? i guess?
	}
//return... what should i return here.

}