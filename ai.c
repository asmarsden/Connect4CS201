#include <stdio.h>
#include <stdlib.h>

int findBestPlacement(int rows, int cols, int[rows][cols]board, int prevCol){
	//so somehow this looks at the graph and decides what it wants to do from there. i... dont know how i want to do this.
	//i could have it randomly select a number between 1 and cols until it finds something valid, with a thing saying like 'if this number... not'
	int col = prevCol+1;
	if (col >= cols) col = col-2;
	while (board[rows-1][col] != -1){
		col--;
		if (col<0) col = cols-1;
	}

	return col;
}//make this a lot more... in depth later