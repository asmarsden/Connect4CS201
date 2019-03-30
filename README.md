# Connect4CS201
cs201 project: connect 4
written by: Aislinn S. Marsden

Command line: simply run make or make connect4, then ./connect4. also supports make clean.

---------
Summary
---------

This is a version of connect 4, written in c. It allows for the player to play single player (which is admittedly kind of boring), against another player, or against an AI. It includes the string library and the bool library, and is in C11. 
You can choose the board size as well, ranging from 4x4 to however big you want it (though any larger than about 40x40 and it doesn't display as intended). The minimum size was put in place due to the fact that connect 4 can't be played with less than 4 places in a row to put pieces; technically, I could have allowed a 4x1 board, but that seemed pretty pointless. 4x4 is the smallest board to still let the player(s) have fun for more than a few seconds. 
The game keeps track of score in game, but does not save that score anywhere for future use, simply displays it after each game lost. If you want to change the game type or board size, you will have to exit the game and restart it with what kind of game you want; so it will not keep overall score if you play a few games with AI then a few games with another player, because inbetween the game will have to close.  
The board itself was implemented using a 2d integer array. This is an unconvential way of implementing a graph, but in order to implement the graph of the board in a traditional manner, the program would lose speed and take up more space, and while trying to add a traditionally implemented graph regardless, I found that having the integer array helped anyway. All of the information needed for this to function properly could be held in that array, so I found no reason to make the program slower.
The board has been changed to be allocated on the heap rather than on the stack, so that incredibly large board sizes can theoretically run. However, the larger the board, the longer it takes to display the board, and the weirder it looks.  

---------
Links
---------

URL of video on how to run this program: https://youtu.be/4_PLtY5cagE
URL of github: https://github.com/asmarsden/Connect4CS201
Note: the github will be made public on Sunday the 31st of March.

---------
Step by step guide on how to run this program: 
---------

Download the main.c, connect.c, connect.h, and makefile files into a new folder within your terminal. 
Use the make command or make connect4 command to compile the program and create the executable, then use ./connect4 to run the program.
It runs in the terminal. It will ask if you want to play alone, with another player, or with the AI. 
After that it will prompt for the board size, then start the game. It will ask you to enter the column you'd like to place a piece in whenever needed. If you are playing with another player, it will ask player 2 to enter the column they would like to place a piece in; if you are playing against AI, it will simply tell you which column the AI chose to place a piece in. After each piece placed it will display the updated board for you to see. 
Once someone has connected 4 pieces, it will update the score, and ask if you would like to play again. If you choose to play again, it will start the game again with the same settings you chose previously; if not, it will simply close the program. 

---------
Tests done so far:
---------

Filling the board without anyone winning: successfully finds that board is filled
player 2 winning: updates scores accordingly
player 1 winning: updates scores accordingly
the AI winning (kind of hard to actually get it to win
playing alone: boring
board size 4x4: smallest possible board works
board size 5x5: plain board works
board size 4x10: works fine after finding and fixing a logic issue
board size 10x4: input that is not square seems to work fine
board size 100x100: runs fine, just looks weird
board size 1000x1000: took a bit longer to print
board size 10000x10000: took quite some time to print, but otherwise appears to work fine
inputting incorrect input in all possible chances to input: after fixing so that it discarded characters when searching for integer input, works fine
