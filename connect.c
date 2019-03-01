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
#include "structs.c"

int* createBoard(int height, int width){//create the heightxwidth int array of the board


}

int* player1Choose(int* board, node* graph){//prompt user for column chosen, then update graph and board, then check for win or full


}

int* player2Choose(int* board, node* graph){//prompt user for column chosen, then update graph and board, then check for win or full

}

int* aiChoose(int* board, node* graph){//redirect to function in AI that chooses column, then update, then check


}

bool isWon(node* graph, node* recent){//checks to see if node named recent formed a connect 4
	


}

bool isFull(int* board, int total){//checks to see if board size == number of pieces placed. buuuut this can prob just be in main


}