#include <stdio.h>
#include <string.h>

#define ORDER 10

int m, n, cx, cy;
char a[ORDER][ORDER] = {'\0'}, b[ORDER] = {'\0'};

void dec (void)
{
	printf ("|         ");
}

void dhc (void)
{
	printf ("|+-------+");
}

void pl (int b)
{
	int i;
	for (i=0; i<b; i++)
	{
		printf ("+---------");
	}
	printf ("+\n");
}

void pb (int b)
{
	int i;
	
	for (i=0; i<b; i++)
	{
		printf ("|         ");
	}
	printf ("|\n");
}

void print_grid (int b)
{
	int i, j;
	for (i=0; i<b; i++)
	{
		pl(b);
		pb(b);
		for (j=0; j<b; j++)
		{
			printf ("|    %c    ", a[i][j] );		
		}
		printf ("|\n");
		pb(b);
	}
	pl(b);
}

int alongdir (char* q, int h, int v)
{
	int i, j, k, t=0;
	for (i=0; i<m; i++)
	{
		for (j=0; j<m; j++)
		{
			if (a[i][j] == b[0])
			{
				/*if (m-j+1 < n || m-i+1 < n)
					break;*/
				cx = i; cy = j;
				for (k=0; k<n; k++)
				{
					if (a[i+h*k][j+v*k] != b[k])
						break;
					t++;
				}
				if (t == n)
					return 1;
			}
		}
	}
	return 0;
}

int checklegal (void)
{
	if (strlen(b) == n)
		return 1;
	return 0;
}

void dislpay_highlighted_board (int h, int v, int t)
{
	int i, j, k=0;
	if (t == -1)
	{
		cx = cx - (n-1);
		cy = cy + (n-1);
	}
	for (i=0; i<m; i++)
	{
		if (i < cx || i > cx+(n-1)*h)
		{
			pl(m);
			pb(m);
			for (j=0; j<m; j++)
			{
				printf ("|    %c    ", a[i][j] );		
			}
			printf ("|\n");
			pb(m);
		}
		else
		{
			{
				pl(m);
				for (j=0; j<m; j++)
				{
					if (j < cy + (i - cx)*t || j > cy+(n-1)*v + (i - cx)*t)
						dec();
					else
						dhc();
				}
				printf ("|\n");
				for (j=0; j<m; j++)
				{
					if (j < cy + (i - cx)*t || j > cy+(n-1)*v + (i - cx)*t)
						printf ("|    %c    ", a[i][j] );
					else
						printf ("||   %c   |", a[i][j]-32);
				}
				printf ("|\n");
				for (j=0; j<m; j++)
				{
					if (j < cy + (i - cx)*t || j > cy+(n-1)*v + (i - cx)*t)
						dec();
					else
						dhc();
				}
				printf ("|\n");
			}
		}
	}
	pl(m);
}

int string_finder (char* p)
{
	//for horizontal
	if (alongdir(p, 0, 1) == 1)
	{
		dislpay_highlighted_board (0, 1, 0);
		return 1;
	}
	//for verticle 
	if (alongdir(p, 1, 0) == 1)
	{
		dislpay_highlighted_board (1, 0, 0);
		return 1;
	}
	//for diagonal1
	if (alongdir(p, 1, 1) == 1)
	{
		dislpay_highlighted_board (1, 0, 1);
		return 1;
	}
	//for diagonal2
	if (alongdir(p, -1, 1) == 1)
	{
		dislpay_highlighted_board (1, 0, -1);
		return 1;
	}
	return 0;
}

int main()
{
	int i, j;
	printf ("SEARCHING A STRING IN THE GRID\n");
	printf ("First enter the order of grid, followed by entering data of the grid.\n");
	scanf ("%d", &m);
	for (i=0; i<m; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf ("%c", &a[i][j]);			
		}
	}
	
	printf ("Enter the length of search string. Then enter the search string. Or type '0**' to exit.\n");
	for (i=0; i<1; i++)
	{
		print_grid(m);
		scanf ("%d%s",&n, b);
		if (checklegal() == 1)
		{
			if (string_finder(b) == 1)
			{
				printf ("Yes!\n");
			}
			else
				printf ("No..\n");
		}
		else
			printf ("**Incorrect value of n.**\n");
		printf ("\n YOU CAN STILL TRY AGAIN!!!...\n\n");
		printf ("To continue press 1.  OR   Press 0 to end.\n\n");
		scanf ("%d", &n);
		if (n == 0)
			return 0;
		if (n == 1)
			i--;
		printf ("Enter the length of search string. Then enter the string.\n");
	}
	return 0;
}
 
