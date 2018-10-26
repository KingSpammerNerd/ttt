#include <stdio.h>

typedef int BOARD[3][3];

//Initialize a new BOARD b by zeroing all the elements:
void newBOARD(BOARD b)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			b[i][j]=0;
}

//Check if the BOARD b is empty:
int isBOARDempty(BOARD b)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			if(b[i][j]!=0)
				return 0;
	return 1;
}

//Print contents of BOARD b:
void printBOARD(BOARD b)
{
	printf("   0    1    2\n");
	printf("  +-----------\n");
	for(int i=0; i<3; ++i)
	{
		printf("%d |", i);
		for(int j=0; j<3; ++j)
			printf("%d    ", b[i][j]);
		printf("\n");
	}
}

//Place a piece on BOARD b at position (x,y):
int place_piece(BOARD b, int piece, int x, int y)
{
	if(b[y][x]!=0 || x>2 || x<0 || y>2 || y<0)
		return 0;
	else
	{
		b[y][x]=piece;
		return 1;
	}
}

//Check if either player has won:
int checkwin(BOARD b)
{
	//Check diagonals:
	if(b[0][0]==b[1][1] && b[1][1]==b[2][2])
		return b[0][0];
	else if(b[0][2]==b[1][1] && b[1][1]==b[2][0])
		return b[0][2];
	//Check rows:
	for(int i=0; i<2; ++i) if(b[i][0]==b[i][1] && b[i][1]==b[i][2]) return b[i][0];
	//Check columns:
	for(int i=0; i<2; ++i) if(b[0][i]==b[1][i] && b[1][i]==b[2][i]) return b[i][0];
	
	//Return 0 if nobody won:
	return 0;
}

//Check if BOARD b is full:
int isfull(BOARD b)
{
	if(b[0][0]>0 && b[0][1]>0 && b[0][2]>0 && b[1][0]>0 && b[1][1]>0 && b[1][2]>0 && b[2][0]>0 && b[2][1]>0 && b[2][2]>0)
		return 1;
	else 
		return 0;
}

int main()
{
	//BOARD variable:
	BOARD board;
	newBOARD(board);
	
	//Variables:
	int i=0, x=0, y=0, w=0;
	//Game loop:
	for(i=0;;++i)
	{
		//Print board:
		printf("Player %d's turn:\n", (i%2)+1);
		printBOARD(board);
		//Get input:
		printf("Enter x,y position: ");
		scanf("%d,%d", &x, &y);
		//Place piece on board:
		while(place_piece(board, (i%2)+1, x, y)==0)
		{
			printf("Enter valid x,y position: ");
			scanf("%d,%d", &x, &y);
		}
		//Check if board is full or a player has won:
		if(isfull(board)==1 && checkwin(board)==0)
		{
			puts("Stalemate!");
			return 0;
		}
		else if((w=checkwin(board))>0)
		{
			printf("The winner is Player %d!\n", w);
			return 0;
		}
	}
	return -1;
}
