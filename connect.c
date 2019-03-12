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
	int board[width][height];
	int i;
	int j;
	for (i = 0; i < width; i++){
		for (j=0; j<height; j++){
			board[i][j] = -1;
		}
	}
return board;
}

int* player1Choose(int* board, node* graph, int rows, int cols){//prompt user for column chosen, then update graph and board, then check for win or full
	int col = -1;
	int row = -1;
	//use ints rows and cols to make sure item placed is Valid
	//prompt for proper column here
	//do a linear search for next available slot in column here, changing row value
	//also check to see if column value is valid. 

	board[row][col] = 1; //one is for player 1
	node* temp = graph;
	int coll = temp->col; 
	while (coll != col){
		if (coll > col){
			temp = temp->left;
			coll--;
		}
		if (coll < col){
			temp = temp->right;
			coll++;
		}
	}
	while (temp->up!=NULL){temp = temp->up;}
	node* new = new Node(row, col);//this may need to change
	//check to make sure none of these are null? 
	temp->up = new; 
	temp->upright->left = new; 
	temp->upleft->right = new;
	temp->left->upright = new;
	temp->right->upleft = new;
	temp->upright->up->downleft = new;
	temp->upleft->up->downright = new;
	new->down = temp;
	new->left = temp->upleft;
	new->right = temp->upright;
	new->up = NULL;
	new->upright = temp->upright->up;
	new->upleft = temp->upleft->up;
	new->downleft = temp->left;
	new->downright = temp->right;
	//what should this return?

}

int* player2Choose(int* board, node* graph){//prompt user for column chosen, then update graph and board, then check for win or full
	//copy everything from up there and change like 2 things

}

int* aiChoose(int* board, node* graph){//redirect to function in AI that chooses column, then update, then check
	//copy from up there and change like 3 things this time

}

bool isWon(node* graph, node* recent){//checks to see if node named recent formed a connect 4
	//this is gonna be Annoying to code. but Here We Go
	//lets check up-- wait. that wont work. just these 7, upright, right, downright, down, downleft, left, then upleft
	int player = recent->player;
	node* temp = recent;
	if (recent->upright->player = player){
		temp = temp->upright;
		if (temp->upright->player = player){
			temp = temp->upright;
			if (temp->upright->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	if (recent->right->player = player){
		temp = temp->right;
		if (temp->right->player = player){
			temp = temp->right;
			if (temp->right->player = player){
				return true;
			}
			else return false;
		}
		else return false;
		
	}
	if (recent->downright->player = player){
		temp = temp->downright;
		if (temp->downright->player = player){
			temp = temp->downright;
			if (temp->downright->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	if (recent->down->player = player){
		temp = temp->down;
		if (temp->down->player = player){
			temp = temp->down;
			if (temp->down->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	if (recent->downleft->player = player){
		temp = temp->downleft;
		if (temp->downleft->player = player){
			temp = temp->downleft;
			if (temp->downleft->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	if (recent->left->player = player){
		temp = temp->left;
		if (temp->left->player = player){
			temp = temp->left;
			if (temp->left->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	if (recent->upleft->player = player){
		temp = temp->upleft;
		if (temp->upleft->player = player){
			temp = temp->upleft;
			if (temp->upleft->player = player){
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}
