/*createBoard: generates an x by y int array, all initialized to 0.
	createGraph: generates an empty graph-- will I need this?
	player1Choose: this is a basic ‘prompt for column’ thing, then returns the int regarding the column, after checking that its valid 
	(in bounds, not full). will repeatedly ask until it gets a valid column.
	player2Choose: same as player1Choose.
	aiChoose: this transfers over to the AI program, which will have all Sorts of functions to figure this out. after that, 
	it returns to this the column, then this function returns the column to aiPlaced. 
	player1Placed: after a different function gets the  location to place the piece, this function takes the column chosen (0 thru x)
	 and places it in the next available slot in the array. maybe do a linear search to find the end piece? that should cut down 
	 on time instead of just check-check-check. anyway, it updates that slot in the int array, then creates a node with the proper 
	 information, found from the array, and places it in the graph. whats gonna Suck is getting all the pointers pointed to it properly. 
	player2Placed: this is the same as player1placed but it initializes the proper variables to 2 instead of 1.
	aiPlaced: pretty much the same, but using 3 instead of 2 or 1, and the AI generated the column, not a human. 
	checkIfWon: after each piece is placed, check to see if the piece generated a connect-4. this is gonna be a bit hard to code
	 just due to the sheer number of possibilities, but there are 5 cases:
piece does not create connect4
piece is 1st in a connect4
piece is 2nd in a connect4
piece is 3rd in a connect4
piece is 4th in a connect4
1 and 4 will be coded the same and 2 and 3 will be coded the same, but 2 and 3 will take some extra checking. basically, break out 
of the function and return true if one is found, if not, return false. hopefully i wont need to return the 4+ nodes that make up a 
connect 4… 
	checkIfFull: after each piece is placed, check to see if number of pieces placed == x * y. just to make sure the board isnt 
	completely full
	
*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.c"

int player1Choose(int rows, int cols, int[rows][cols] board){//prompt user for column chosen, then update graph and board, then check for win or full
	int col = -1;
	int row = -1;
	bool validAnswer = false;
	printf("Which column would player 1 like to place a piece in? Please enter a valid number.\n");
	//scan in
	if (board[col][rows-1] == -1){
		validAnswer = true;
	}
	while (!validAnswer){
		printf("That is not a valid column choice, please try again.\n");
		//scan in
		if (board[col][rows-1] == -1){
			validAnswer = true;
		}
	}
	row = findMostRecent(rows, cols, board, col);
	board[col][row] = 1;
	return col;
}

int player2Choose(int rows, int cols, int[rows][cols] board){//prompt user for column chosen, then update graph and board, then check for win or full
	int col = -1;
	int row = -1;
	bool validAnswer = false;
	printf("Which column would player 2 like to place a piece in? Please enter a valid number.\n");
	//scan in
	if (board[col][rows-1] == -1){
		validAnswer = true;
	}
	while (!validAnswer){
		printf("That is not a valid column choice, please try again.\n");
		//scan in
		if (board[col][rows-1] == -1){
			validAnswer = true;
		}
	}
	row = findMostRecent(rows, cols, board, col);
	board[col][row] = 2;
	return col;

}

int aiChoose(int rows, int cols, int[rows][cols] board, int prevCol){//redirect to function in AI that chooses column, then update, then check
	int row = -1;
	int col = -1;
	//so somehow this looks at the graph and decides what it wants to do from there. i... dont know how i want to do this.
	//i could have it randomly select a number between 1 and cols until it finds something valid, with a thing saying like 'if this number... not'
	int col = prevCol+1;
	if (col >= cols) col = col-2;
	while (board[rows-1][col] != -1){
		col--;
		if (col<0) col = cols-1;
	}
//make this a lot more... in depth later
	row = findMostRecent(rows, cols, board, col);
	board[col][row] = 2;


	printf("The AI has placed a piece in column %d.\n", col);
	return col;
}

bool isWon(int width, int height, int[width][height] board, int column){
	int row = findRecent(width, height, board, column);//still gotta code this function//think this is done now
	int count = 1; int player = board[column][row];
	bool isWon = false; bool broken = false;
	int i = column; int j = row; 
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
		if (board[i-1][j+1] == player){
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
		if (board[i+1][j-1] == player){
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
		if (board[i+1][j] == player){
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

int findMostRecent(int width, int height, int[width][height], int column){
	int i = 1;
	int check = -1;
	if (board[column][height-1] != -1){
		return height-1;
	}
	while(check == -1){
		i++;
		check = board[column][(height-1)/i];
	}
	int h = (height-1)/i;
	while (check !=-1){
		h++;
		check = board[column][h];
	}
	return h-1;
}
	




/* 
alright so change of plans. we will have a matrix that holds where each piece is, and another matrix that is an adjacency matrix... so maybe... 
a matrix for individual pieces (-1 for none, 1 for player 1, 2 for player 2, 3 for ai)
then two matrices that just show like. individual pieces? maybe? hmm
also i think ill go with an ascii interface just because i dont wanna Fight with something. it needs to open an .exe though i think which is gonna suck
also also. i need to have the program run some sort of thing on a graph to decide what to do next. ugh
