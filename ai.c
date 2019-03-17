#include <stdio.h>
#include <stdlib.h>
#include "structs.c"

int findBestPlacement(node* graph, int cols, int* board, int rows){
	//so somehow this looks at the graph and decides what it wants to do from there. i... dont know how i want to do this.
	//i could have it randomly select a number between 1 and cols until it finds something valid, with a thing saying like 'if this number... not'
	int col = -1;

	//logic. what should this be?
	/*
		so I'm thinking. very basic stuff-- it loads in the graph, and the node that its pointing to will be like the first one placed... but it'd be better
		if its the most recent, so lets try to send in the most recently placed node, which will be the enemies. check that node and... 
		lemme write this out on paper.


	*/
	node* temp = graph;
	if (temp->upleft->player == 1 && temp->downright->player == 1){
		if (temp->downright->downright == NULL) col = temp->col + 2;
		else col = temp->col -2; 
	}
	if (temp->left->player == 1 && temp->right->player == 1){
		if (temp->left->left == NULL) col = temp->col -2;
		else col = temp->col + 2;
	}
	if (temp->down->player == 1){
		col = temp->col;
	}
	else col = temp->col + 1;




	int count = rows;
	bool valid = checkIfValid(board, col, cols, rows);
	while (!valid){ rows--;
		if (rows == 0) break; //this shouldnt happen, but just in case
		col--;
		if (col < 0){
			col = cols - 1;
		}
		valid = checkIfValid(board, col, cols, rows);
	}
	return col;
}


bool checkIfValid(int* board, int col, int cols, int rows){
	if (col > cols - 1) return false; 
	if (col < 0) return false;
	if (board[col][rows-1] == -1) return true;
	else return false;
}