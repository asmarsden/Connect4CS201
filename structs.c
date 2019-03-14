#include <stdio.h>
#include <stdlib.h>
#include "node.h"
//todo: assert n!=0 in all
typedef struct NODE
{
	struct NODE *up;
	struct NODE *left;
	struct NODE *right;
	struct NODE *upright;
	struct NODE *downright;
	struct NODE *upleft;	
	struct NODE *downleft;
	struct NODE *down;
	int player; 
	int row;
	int col;

} NODE;

    extern NODE *newNODE(int p, int r, int c){
		NODE *node = malloc(sizeof(NODE));
		assert(node != 0);
		node->up = NULL;
		node->upleft = NULL;
		node->upright = NULL;
		node->left = NULL;
		node->right = NULL;
		node->down = NULL;
		node->downleft = NULL;
		node->downright = NULL;
		node->player = p;
		node->row = r;
		node->col = c;
		return node;
    }
    extern int getPlayer(NODE *n){//add to .h file
    	return n->player;
    }
    extern int getCol(NODE *n){//add to .h file
        return n->col;
    }
    extern int getRow(NODE *n){//add to .h file
        return n->row;
    }