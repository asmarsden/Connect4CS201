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
	int* = createBoard(tall, wide);//figure out how to transfer 2 dimensional int arrays
	//create graph object;
	bool gameFinished = false;
	bool fourConnected = false;
	bool boardFilled = false;
	bool previousGame = false;
	while (!gameFinished){
		playGame(stuff){};



		if (boardFilled = true) gameFinished = true; //do not change scores. display  proper thing
		if (fourConnected = true) gameFinished = true; //update scores if needed, display proper thing
	}

	//do stuff here for after game stuff, ask if theyd like to play again



}

void playGame(stuff){//remember there is a number that gets increased every time a piece gets placed



}