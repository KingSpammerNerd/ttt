#include <stdio.h>

typedef int[3][3] BOARD;

//Initialize a new BOARD b:
void newBOARD(BOARD b)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			b[i][j]=(-1);
}

//Check if the BOARD b is empty:
int isBOARDempty(BOARD b)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			if(b[i][j]!=(-1))
				return -1;
	return 0;
}

//Print contents of BOARD b:
void printBOARD(BOARD b)
{
	for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			printf("%d\t", b[i][j]);
		printf("\n");
}

//Place a piece on BOARD b at position (x,y):
int place_piece(BOARD b, int piece, int x, int y)
{
	if(b[x-1][y-1]!=(-1) || x>3 || x<1 || y>3 || y<1)
		return -1;
	else
	{
		b[x-1][y-1]=piece;
		return 0;
	}
}

int main()
{
	//BOARD variable:
	BOARD board;
	newBOARD(board);
	
	//TODO:The rest.
	return 0;
}
