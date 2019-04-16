//Tic-Tac-Toe refree : assisting at each move

#include<stdio.h>
#define SIZE 3

//GLOBAL DECLARATIONS :
char board[SIZE][SIZE];
int freeCells=SIZE*SIZE;

char player[2] = {'O', 'X'};

char EMPTY = ' ';

int NOT_OVER;
int P1_WIN;
int P2_WIN;
int DRAW;

int LEGAL=1;
int ILLEGAL=0;

//FUNCTIONS :
void init (void)
{
	int i, j;
	for (i=0 ; i<SIZE ; i++)
	{
		for(j=0 ; j<SIZE ; j++)
		{
			board[i][j] = EMPTY;
		}
	}
}

void showconfig(void)
{
	int i, j;
	printf ("+-------+-------+-------+\n");
	for (i=0 ; i<SIZE ; i++)
	{
		for(j=0 ; j<SIZE ; j++)
		{
			printf ("|   %c   ", board[i][j]);
		}
		printf ("|\n+-------+-------+-------+\n");
	}
		printf ("\n");
}

void printlogo (void)
{
	printf ("********  ********   ****** 		********    ****     ****** 		********   ******   ********\n") ;
	printf ("********  ********  ********		********   ******   ********		********  ********  ********\n") ;
	printf ("   **        **     **      		   **     **    **  **      		   **     **    **  **      \n") ;
	printf ("   **        **     **      		   **     **    **  **      		   **     **    **  *****   \n") ;
	printf ("   **        **     **      		   **     ********  **      		   **     **    **  *****   \n") ;
	printf ("   **        **     **      		   **     **    **  **      		   **     **    **  **      \n") ;
	printf ("   **     ********  ********		   **     **    **  ********		   **     ********  ********\n") ;
	printf ("   **     ********   ****** 		   **     **    **   ****** 		   **      ******   ********\n\n") ;
}

int checkwin (void)
{
	int n=0, a, b, c, count_h, count_v, df, db;
	while (n<=1)
	{
		//for horizontal check
		for (a=0 ; a<SIZE ; a++)
		{
			count_h=0;
			for (b=0 ; b<SIZE ; b++)
			{
				if(board[a][b] == player[n])
					count_h++;
			}
			if (count_h == 3)
			{
				printf ("\nPlayer %d wins\n", n+1);
				return (n+1);
			}
		}
	
		//for vertical check
		for (a=0 ; a<SIZE ; a++)
		{
			count_v=0;
			for (b=0 ; b<SIZE ; b++)
			{
				if (board[b][a] == 3)
					count_v++;
			}
			if (count_v == 3)
			{
				printf ("\nPlayer %d wins\n", n+1);
				return (n+1);
			}
		
		}
		
		//for diagonal check
		df=0; db=0;
		for (c=0 ; c<SIZE ; c++)
		{
			if (board[c][c] == player[n])
				df++;
			if (board[SIZE-c-1][c] == player[n])
				db++;
		}
		if(df == 3 || db == 3)
		{
			printf ("\nPlayer %d wins\n", n+1);
			return (n+1);
		}
		
		if (freeCells == 0)
		{
			printf ("\nDraw.\n");
			return 3;
		}
		
		n++;
		printf ("Play continues...\n\n");
		return 0;
	}
}

int checklegal (int i, int j)
{
	if (i>=0 && j>=0 && i<SIZE && j<SIZE && board[i][j] == EMPTY)
		return LEGAL;
	return ILLEGAL;
}

void putsymbol (int a, int b, char c)
{
	board[a][b]=c;
	freeCells--;
}

int main (void)
{
	int p=0, i, j;
	
	init ();	
	printlogo ();
	
	printf ("Welcome to Tic-Tac-Toe game\n");
	printf ("Player 1 will use \'X\' and Player 2 will use\'O\'\n\n");
	
	showconfig ();
	
	while (checkwin () == NOT_OVER)
	{
		printf ("Player %d\'s turn\n", (p+1));
		printf ("Enter the coordinates of the cell.\n");
		scanf ("%d %d", &i, &j);
		
		i--;
		j--;
		
		if (checklegal (i, j) == ILLEGAL)
		{
			printf ("Illegal move.\nChoose some other cell.\n");
			continue;
		}
		putsymbol (i, j, player[p]);
		
		showconfig ();
		
		p = (p+1) % 2;
		
	}
	
	printf ("\nGAME OVER.");
	return 0;
}
