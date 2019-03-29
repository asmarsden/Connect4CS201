# Connect4CS201
cs201 project: connect 4
written by: Aislinn S. Marsden
This is a version of connect 4, written in c. It allows for the player to play single player (which is admittedly kind of boring), against another player, or against an AI. It includes the string library and the bool library, and is in C11. 
You can choose the board size as well, ranging from 4x4 to however big you want it (though any larger than about 40x40 and it doesn't display as intended). The minimum size was put in place due to the fact that connect 4 can't be played with less than 4 places in a row to put pieces; technically, I could have allowed a 4x1 board, but that seemed pretty pointless. 4x4 is the smallest board to still let the player(s) have fun for more than a few seconds. 
The game keeps track of score in game, but does not save that score anywhere for future use, simply displays it after each game lost. If you want to change the game type or board size, you will have to exit the game and restart it with what kind of game you want; so it will not keep overall score if you play a few games with AI then a few games with another player, because inbetween the game will have to close.  
The board itself was implemented using a 2d integer array. This is an unconvential way of implementing a graph, but in order to implement the graph of the board in a traditional manner, the program would lose speed and take up more space, and while trying to add a traditionally implemented graph regardless, I found that having the integer array helped anyway. All of the information needed for this to function properly could be held in that array, so I found no reason to make the program slower.
Currently, the array is a simple 2d integer array, not using pointers or anything. I have noted that large board sizes cause a segmentation fault simply because the game runs out of space for the board; while a connect 4 game of 10000x10000 is gigantic and I personally doubt anyone would enjoy playing it, and the larger the board size the worse it displays, this is something I am going to fix if I have the time by changing the array so that it is allocated on the heap instead of the stack.  

URL of video on how to run this program: 

Step by step guide on how to run this program: 
Download the main.c, connect.c, connect.h, and makefile files into a new folder within your terminal. 
Use the make command or make connect4 command to compile the program and create the executable, then use ./connect4 to run the program.
It simply runs in the terminal. It will ask if you want to play alone, with another player, or with the AI. 
After that it will prompt for the board size, then start the game. It will ask you to enter the column you'd like to place a piece in whenever needed. If you are playing with another player, it will ask player 2 to enter the column they would like to place a piece in; if you are playing against AI, it will simply tell you which column the AI chose to place a piece in. After each piece placed it will display the updated board for you to see. 
Once someone has connected 4 pieces, it will update the score, and ask if you would like to play again. If you choose to play again, it will start the game again with the same settings you chose previously; if not, it will simply close the program. 

Tests done so far:
Filling the board without anyone winning
player 2 winning
player 1 winning
the AI winning
playing alone
board size 4x4
board size 5x5
board size 4x10
board size 10x4
board size 100x100
board size 1000x1000
