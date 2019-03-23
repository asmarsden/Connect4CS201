int player1Choose(int rows, int cols, int[rows][cols] board);
int player2Choose(int rows, int cols, int[rows][cols] board);
int aiChoose(int rows, int cols, int[rows][cols] board, int prevCol);
bool isWon(int width, int height, int[width][height] board, int column);
int findMostRecent(int width, int height, int[width][height], int column);