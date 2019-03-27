connect4 : main.c connect.c connect.h
	gcc -Wall -Wextra -g -std=c11 main.c connect.c connect.h -o connect4

clean :
	rm -f *.o connect4