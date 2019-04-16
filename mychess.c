/*TO BE DONE !!!!!
*points calculator*
*sorting in display board*
*checkmate, stalemate, game over
*correct- games continues even after king
*according to latest FIDE rules
*/

#include <stdio.h>
#include <math.h>

int chess[8][8] = {0};
int displayboard[4][3] = {0};
int counter[4][3] = {0};
int checkshift[8][8] = {0};

int display_logo(void)
{
	int a;
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf ("\t\t\t\t\t\t\t   ********      *****      *****    **************       *********         ********* \n");
	printf ("\t\t\t\t\t\t\t ************     ***        ***      *************     *************     *************\n");
	printf ("\t\t\t\t\t\t\t****        *     ***        ***      ***         *     ***         *     ***         *\n");
	printf ("\t\t\t\t\t\t\t***               ***        ***      ***               ***               ***          \n");
	printf ("\t\t\t\t\t\t\t***               **************      *******           ***********       ***********  \n");
	printf ("\t\t\t\t\t\t\t***               **************      *******             ***********       ***********\n");
	printf ("\t\t\t\t\t\t\t***               ***        ***      ***                         ***               ***\n");
	printf ("\t\t\t\t\t\t\t****        *     ***        ***      ***         *     *         ***     *         ***\n");
	printf ("\t\t\t\t\t\t\t ************     ***        ***      *************     *************     *************\n");
	printf ("\t\t\t\t\t\t\t   ********      *****      *****    **************       *********         *********  \n");
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf ("press 0, then ENTER.\n");
	scanf ("%d", &a);
	if (a == 0)
	{
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf ("\t\t\t\t\t\t\t\t\t\t\t\tA game of chess\n ");
		printf ("\t\t\t\t\t\t\t\t\t\t\t   designed and presented by\n\n");
		printf ("\t\t\t\t\t\t\t\t\t\t\t\tSHREYASH PATIDAR\n\n");
		printf ("\t\t\t\t\t\t\t\t\t\t          based on latest FIDE rules\n");
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
		printf ("To start game press 1, then ENTER.\n");
	}
	scanf ("%d", &a);
	if (a == 1)
		return 0;
}
/*
101 :- white pawn;
102 :- white rook;
103 :- white knight;
104 :- white bishop;
105 :- white king;
106 :- white queen;

201 :- black pawn;
202 :- black rook;
203 :- black knight;
204 :- black bishop;
205 :- black king;
206 :- black queen;
*/

void initconfig (void)
{
	int i;
	for (i=0; i<8; i++)
	{
		chess[1][i] = 201;
		chess[6][i] = 101;
	}
		chess[0][0] = chess[0][7] = 202;
		chess[0][1] = chess[0][6] = 203;
		chess[0][2] = chess[0][5] = 204;
		chess[0][3] = 206;
		chess[0][4] = 205;
		
		chess[7][0] = chess[7][7] = 102;
		chess[7][1] = chess[7][6] = 103;
		chess[7][2] = chess[7][5] = 104;
		chess[7][3] = 106;
		chess[7][4] = 105;
}

void pll1 (void)
{
	printf ("\t+-----------------------------------------------------------------------------------------------------------------------------------+       ");
}

void pll2 (void)
{
	printf ("+---------------------------------------------------+\n");
}

void pls1 (void)
{
	printf ("\t| +---------------+---------------+---------------+---------------+---------------+---------------+---------------+---------------+ |       ");
}

void pls2 (void)
{
	printf ("| +-----------------------------------------------+ |\n");
}

void bec1 (int t)
{
	switch (t)
	{
		case 1 : printf ("***         ***|"); break;
		case 2 : printf ("**           **|"); break;
		case 3 : printf ("*             *|"); break;
	}
}

void wec1 (void)
{
	printf ("               |");
}

void ec2 (void)
{
	printf ("               |               |               |");
}

/*
Symbols and appearance
*/

void b_w_pawn (int i)
{
	switch (i)
	{
		case 1 : printf ("               |"); break;
		case 2 : printf ("       @       |"); break;
		case 3 : printf ("      / \\      |"); break;
		case 4 : printf ("      | |      |"); break;
		case 5 : printf ("     =====     |"); break;
	}
}

void b_w_rook (int i)
{
	switch (i)
	{
		case 1 : printf ("     ^^^^^     |"); break;
		case 2 : printf ("     =====     |"); break;
		case 3 : printf ("     |   |     |"); break;
		case 4 : printf ("     |   |     |"); break;
		case 5 : printf ("    =======    |"); break;
	}
}

void b_w_knight (int i)
{
	switch (i)
	{
		case 1 : printf ("        ^      |"); break;
		case 2 : printf ("     <<@@?     |"); break;
		case 3 : printf ("      )  }     |"); break;
		case 4 : printf ("     (   )     |"); break;
		case 5 : printf ("    =======    |"); break;
	}
}

void b_w_bishop (int i)
{
	switch (i)
	{
		case 1 : printf ("       ^       |"); break;
		case 2 : printf ("      ( )      |"); break;
		case 3 : printf ("      | |      |"); break;
		case 4 : printf ("      | |      |"); break;
		case 5 : printf ("     =====     |"); break;
	}
}

void b_w_king (int i)
{
	switch (i)
	{
		case 1 : printf ("       +       |"); break;
		case 2 : printf ("     ==|==     |"); break;
		case 3 : printf ("      | |      |"); break;
		case 4 : printf ("     /   \\     |"); break;
		case 5 : printf ("    =======    |"); break;
	}
}

void b_w_queen (int i)
{
	switch (i)
	{
		case 1 : printf ("       #       |"); break;
		case 2 : printf ("     _/^\\_     |"); break;
		case 3 : printf ("     ((@))     |"); break;
		case 4 : printf ("      ) (      |"); break;
		case 5 : printf ("    =======    |"); break;
	}
}

void w_w_pawn (int i)
{
	switch (i)
	{
		case 1 : printf ("***         ***|"); break;
		case 2 : printf ("**     @     **|"); break;
		case 3 : printf ("*     / \\     *|"); break;
		case 4 : printf ("**    | |    **|"); break;
		case 5 : printf ("***  =====  ***|"); break;
	}
}

void w_w_rook (int i)
{
	switch (i)
	{
		case 1 : printf ("***  ^^^^^  ***|"); break;
		case 2 : printf ("**   =====   **|"); break;
		case 3 : printf ("*    |   |    *|"); break;
		case 4 : printf ("**   |   |   **|"); break;
		case 5 : printf ("*** ======= ***|"); break;
	}
}

void w_w_knight (int i)
{
	switch (i)
	{
		case 1 : printf ("***     ^   ***|"); break;
		case 2 : printf ("**   <<@@?   **|"); break;
		case 3 : printf ("*     )  }    *|"); break;
		case 4 : printf ("**   (   )   **|"); break;
		case 5 : printf ("*** ======= ***|"); break;
	}
}

void w_w_bishop (int i)
{
	switch (i)
	{
		case 1 : printf ("***    ^    ***|"); break;
		case 2 : printf ("**    ( )    **|"); break;
		case 3 : printf ("*     | |     *|"); break;
		case 4 : printf ("**    | |    **|"); break;
		case 5 : printf ("***  =====  ***|"); break;
	}
}

void w_w_king (int i)
{
	switch (i)
	{
		case 1 : printf ("***    +    ***|"); break;
		case 2 : printf ("**   ==|==   **|"); break;
		case 3 : printf ("*     | |     *|"); break;
		case 4 : printf ("**   /   \\   **|"); break;
		case 5 : printf ("*** ======= ***|"); break;
	}
}

void w_w_queen (int i)
{
	switch (i)
	{
		case 1 : printf ("***    #    ***|"); break;
		case 2 : printf ("**   _/^\\_   **|"); break;
		case 3 : printf ("*    ((@))    *|"); break;
		case 4 : printf ("**    ) (    **|"); break;
		case 5 : printf ("*** ======= ***|"); break;
	}
}

void b_b_pawn (int i)
{
	switch (i)
	{
		case 1 : printf ("   .       .   |"); break;
		case 2 : printf ("  .    @    .  |"); break;
		case 3 : printf (" .    / \\    . |"); break;
		case 4 : printf ("  .   | |   .  |"); break;
		case 5 : printf ("   . =*=*= .   |"); break;
	}
}

void b_b_rook (int i)
{
	switch (i)
	{
		case 1 : printf ("   . ^^^^^ .   |"); break;
		case 2 : printf ("  .  =====  .  |"); break;
		case 3 : printf (" .   |   |   . |"); break;
		case 4 : printf ("  .  |   |  .  |"); break;
		case 5 : printf ("   .=*=*=*=.   |"); break;
	}
}

void b_b_knight (int i)
{
	switch (i)
	{
		case 1 : printf ("   .    ^  .   |"); break;
		case 2 : printf ("  .  <<@@?  .  |"); break;
		case 3 : printf (" .    )  }   . |"); break;
		case 4 : printf ("  .  (   )  .  |"); break;
		case 5 : printf ("   .=*=*=*=.   |"); break;
	}
}

void b_b_bishop (int i)
{
	switch (i)
	{
		case 1 : printf ("   .   ^   .   |"); break;
		case 2 : printf ("  .   ( )   .  |"); break;
		case 3 : printf (" .    | |    . |"); break;
		case 4 : printf ("  .   | |   .  |"); break;
		case 5 : printf ("   . =*=*= .   |"); break;
	}
}

void b_b_king (int i)
{
	switch (i)
	{
		case 1 : printf ("   .   +   .   |"); break;
		case 2 : printf ("  .  ==|==  .  |"); break;
		case 3 : printf (" .    | |    . |"); break;
		case 4 : printf ("  .  /   \\  .  |"); break;
		case 5 : printf ("   .=*=*=*=.   |"); break;
	}
}

void b_b_queen (int i)
{
	switch (i)
	{
		case 1 : printf ("   .   #   .   |"); break;
		case 2 : printf ("  .  _/^\\_  .  |"); break;
		case 3 : printf (" .   ((@))   . |"); break;
		case 4 : printf ("  .   ) (   .  |"); break;
		case 5 : printf ("   .=*=*=*=.   |"); break;
	}
}

void w_b_pawn (int i)
{
	switch (i)
	{
		case 1 : printf ("***.       .***|"); break;
		case 2 : printf ("**.    @    .**|"); break;
		case 3 : printf ("*.    / \\    .*|"); break;
		case 4 : printf ("**.   | |   .**|"); break;
		case 5 : printf ("***. =*=*= .***|"); break;
	}
}

void w_b_rook (int i)
{
	switch (i)
	{
		case 1 : printf ("***. ^^^^^ .***|"); break;
		case 2 : printf ("**.  =====  .**|"); break;
		case 3 : printf ("*.   |   |   .*|"); break;
		case 4 : printf ("**.  |   |  .**|"); break;
		case 5 : printf ("***.=*=*=*=.***|"); break;
	}
}

void w_b_knight (int i)
{
	switch (i)
	{
		case 1 : printf ("***.    ^  .***|"); break;
		case 2 : printf ("**.  <<@@?  .**|"); break;
		case 3 : printf ("*.    )  }   .*|"); break;
		case 4 : printf ("**.  (   )  .**|"); break;
		case 5 : printf ("***.=*=*=*=.***|"); break;
	}
}

void w_b_bishop (int i)
{
	switch (i)
	{
		case 1 : printf ("***.   ^   .***|"); break;
		case 2 : printf ("**.   ( )   .**|"); break;
		case 3 : printf ("*.    | |    .*|"); break;
		case 4 : printf ("**.   | |   .**|"); break;
		case 5 : printf ("***. =*=*= .***|"); break;
	}
}

void w_b_king (int i)
{
	switch (i)
	{
		case 1 : printf ("***.   +   .***|"); break;
		case 2 : printf ("**.  ==|==  .**|"); break;
		case 3 : printf ("*.    | |    .*|"); break;
		case 4 : printf ("**.  /   \\  .**|"); break;
		case 5 : printf ("***.=*=*=*=.***|"); break;
	}
}

void w_b_queen (int i)
{
	switch (i)
	{
		case 1 : printf ("***.   #   .***|"); break;
		case 2 : printf ("**.  _/^\\_  .**|"); break;
		case 3 : printf ("*.   ((@))   .*|"); break;
		case 4 : printf ("**.   ) (   .**|"); break;
		case 5 : printf ("***.=*=*=*=.***|"); break;
	}
}

void fun_select (int a, int b, int t)
{
	if ((a+b) % 2 != 0)
	{
		if (chess[a][b] == 201)
			w_b_pawn(t);
		if (chess[a][b] == 202)
			w_b_rook(t);
		if (chess[a][b] == 203)
			w_b_knight(t);
		if (chess[a][b] == 204)
			w_b_bishop(t);
		if (chess[a][b] == 205)
			w_b_king(t);
		if (chess[a][b] == 206)
			w_b_queen(t);
		if (chess[a][b] == 101)
			w_w_pawn(t);
		if (chess[a][b] == 102)
			w_w_rook(t);
		if (chess[a][b] == 103)
			w_w_knight(t);
		if (chess[a][b] == 104)
			w_w_bishop(t);
		if (chess[a][b] == 105)
			w_w_king(t);
		if (chess[a][b] == 106)
			w_w_queen(t);
	}
	
	else
	{
		if (chess[a][b] == 201)
			b_b_pawn(t);
		if (chess[a][b] == 202)
			b_b_rook(t);
		if (chess[a][b] == 203)
			b_b_knight(t);
		if (chess[a][b] == 204)
			b_b_bishop(t);
		if (chess[a][b] == 205)
			b_b_king(t);
		if (chess[a][b] == 206)
			b_b_queen(t);
		if (chess[a][b] == 101)
			b_w_pawn(t);
		if (chess[a][b] == 102)
			b_w_rook(t);
		if (chess[a][b] == 103)
			b_w_knight(t);
		if (chess[a][b] == 104)
			b_w_bishop(t);
		if (chess[a][b] == 105)
			b_w_king(t);
		if (chess[a][b] == 106)
			b_w_queen(t);
	}
}

void p1 (int i)
{
	switch (i)
	{
		case 1 : printf ("**           **"); break;
		case 2 : printf ("*      @      *"); break;
		case 3 : printf ("      / \\      "); break;
		case 4 : printf ("*     | |     *"); break;
		case 5 : printf ("**   =====   **"); break;
	}
}

void r1 (int i)
{
	switch (i)
	{
		case 1 : printf ("**   ^^^^^   **"); break;
		case 2 : printf ("*    =====    *"); break;
		case 3 : printf ("     |   |     "); break;
		case 4 : printf ("*    |   |    *"); break;
		case 5 : printf ("**  =======  **"); break;
	}
}

void k1 (int i)
{
	switch (i)
	{
		case 1 : printf ("**      ^    **"); break;
		case 2 : printf ("*    <<@@?    *"); break;
		case 3 : printf ("      )  }     "); break;
		case 4 : printf ("*    (   )    *"); break;
		case 5 : printf ("**  =======  **"); break;
	}
}

void b1 (int i)
{
	switch (i)
	{
		case 1 : printf ("**     ^     **"); break;
		case 2 : printf ("*     ( )     *"); break;
		case 3 : printf ("      | |      "); break;
		case 4 : printf ("*     | |     *"); break;
		case 5 : printf ("**   =====   **"); break;
	}
}

void q1 (int i)
{
	switch (i)
	{
		case 1 : printf ("**     #     **"); break;
		case 2 : printf ("*    _/^\\_    *"); break;
		case 3 : printf ("     ((@))     "); break;
		case 4 : printf ("*     ) (     *"); break;
		case 5 : printf ("**  =======  **"); break;
	}
}

void p2 (int i)
{
	switch (i)
	{
		case 1 : printf ("** .       . **"); break;
		case 2 : printf ("* .    @    . *"); break;
		case 3 : printf (" .    / \\    . "); break;
		case 4 : printf ("* .   | |   . *"); break;
		case 5 : printf ("** . =*=*= . **"); break;
	}
}

void r2 (int i)
{
	switch (i)
	{
		case 1 : printf ("** . ^^^^^ . **"); break;
		case 2 : printf ("* .  =====  . *"); break;
		case 3 : printf (" .   |   |   . "); break;
		case 4 : printf ("* .  |   |  . *"); break;
		case 5 : printf ("** .=*=*=*=. **"); break;
	}
}

void k2 (int i)
{
	switch (i)
	{
		case 1 : printf ("** .    ^  . **"); break;
		case 2 : printf ("* .  <<@@?  . *"); break;
		case 3 : printf (" .    )  }   . "); break;
		case 4 : printf ("* .  (   )  . *"); break;
		case 5 : printf ("** .=*=*=*=. **"); break;
	}
}

void b2 (int i)
{
	switch (i)
	{
		case 1 : printf ("** .   ^   . **"); break;
		case 2 : printf ("* .   ( )   . *"); break;
		case 3 : printf (" .    | |    . "); break;
		case 4 : printf ("* .   | |   . *"); break;
		case 5 : printf ("** . =*=*= . **"); break;
	}
}

void q2 (int i)
{
	switch (i)
	{
		case 1 : printf ("** .   #   . **"); break;
		case 2 : printf ("* .  _/^\\_  . *"); break;
		case 3 : printf (" .   ((@))   . "); break;
		case 4 : printf ("* .   ) (   . *"); break;
		case 5 : printf ("** .=*=*=*=. **"); break;
	}
}

void prinnum (int i, int p, int q)
{
	int x1, x2;
	x1 = displayboard[p][q]/10;
	x2 = displayboard[p][q]%10;
	
	switch (i)
	{
		case 1 : printf ("**          ***"); break;
		case 2 : printf ("*             *"); break;
		case 3 : printf ("       %d%d      ", x1, x2); break;
		case 4 : printf ("*             *"); break;
		case 5 : printf ("**          ***"); break;
	}
}
void emc2 (int a)
{
	switch (a)
	{
		case 0 : printf ("| |                                               | |\n"); break;
		case 1 : printf ("**           **");break;
		case 2 : printf ("*             *");break;
		case 3 : printf ("               ");break;
		case 4 : printf ("*             *");break;
		case 5 : printf ("**           **");break;
		case 6 : printf ("*"); break;
		case 7 : printf ("*"); break;
		case 8 : printf (" "); break;
		case 9 : printf ("*"); break;
		case 10 : printf ("*"); break;
	}
}

void fc2 (int a, int p, int q)
{
	if (p == 1 && q == 2)
		prinnum(a, p, q);
	if (p == 2 && q == 2)
		prinnum(a, p, q);
	if (displayboard[p][q] == 101)
		p1(a);
	if (displayboard[p][q] == 102)
		r1(a);
	if (displayboard[p][q] == 103)
		k1(a);
	if (displayboard[p][q] == 104)
		b1(a);
	if (displayboard[p][q] == 106)
		q1(a);
	if (displayboard[p][q] == 201)
		p2(a);
	if (displayboard[p][q] == 202)
		r2(a);
	if (displayboard[p][q] == 203)
		k2(a);
	if (displayboard[p][q] == 204)
		b2(a);
	if (displayboard[p][q] == 206)
		q2(a);
}

void playerconsole1 (int i, int p)
{
	switch(i)
	{
		case 1 : printf ("***********************************************|"); break;
		case 2 : printf ("*******'''''''''''''''''''''''''''''''''*******|"); break;
		case 3 : printf ("****'''                                 '''****|"); break;
		case 4 : printf ("***'''        +              PLAYER      '''***|"); break;
		case 5 : if (p == 1)
					printf ("**''        ==|==        *                 ''**|");
				 if (p == 2)
				 	printf ("**''        ==|==                          ''**|"); break;
		case 6 : if (p == 1)
					printf ("**''         | |        ***    I           ''**|");
				 if (p == 2)
				 	printf ("**''         | |               I           ''**|"); break;
		case 7 : if (p == 1)
					printf ("**''        /   \\        *                 ''**|");
				 if (p == 2)
				 	printf ("**''        /   \\                          ''**|"); break;
		case 8 : printf ("***'''     =======           (White)     '''***|"); break;
		case 9 : printf ("****'''                                 '''****|"); break;
		case 10 : printf ("*******'''''''''''''''''''''''''''''''''*******|"); break;
		case 11 : printf ("***********************************************|"); break;
	}
}

void playerconsole2 (int i, int p)
{
	switch(i)
	{
		case 1 : printf ("***********************************************|"); break;
		case 2 : printf ("*******'''''''''''''''''''''''''''''''''*******|"); break;
		case 3 : printf ("****'''                                 '''****|"); break;
		case 4 : printf ("***'''     .   +   .         PLAYER      '''***|"); break;
		case 5 : if (p == 2)
					printf ("**''      .  ==|==  .    *                 ''**|");
				 if (p == 1)
				 	printf ("**''      .  ==|==  .                      ''**|"); break;
		case 6 : if (p == 2)
					printf ("**''     .    | |    .  ***    II          ''**|");
				 if (p == 1)
				 	printf ("**''     .    | |    .         II          ''**|"); break;
		case 7 : if (p == 2)
					printf ("**''      .  /   \\  .    *                 ''**|");
				 if (p == 1)
				 	printf ("**''      .  /   \\  .                      ''**|"); break;
		case 8 : printf ("***'''     .=*=*=*=.         (Black)     '''***|"); break;
		case 9 : printf ("****'''                                 '''****|"); break;
		case 10 : printf ("*******'''''''''''''''''''''''''''''''''*******|"); break;
		case 11 : printf ("***********************************************|"); break;
	}
}

void scoreboard (int i, int j, int p)
{
	if (i == 0)
	{
		printf (" |       | |");
		int a;
		for (a=0; a<3; a++)
		{
			if (displayboard[i][a] == 0)
				emc2(j);
			else
				fc2(j, i, a);
			emc2(j+5);
		}
		printf ("\b|");
		return;
	}
	if (i == 1)
	{
		printf (" |       | |");
		int a;
		for (a=0; a<3; a++)
		{
			if (displayboard[i][2-a] == 0)
				emc2(j);
			else
				fc2(j, i, 2-a);
			emc2(j+5);
		}
		printf ("\b|");
		return;
	}
	if (i == 2)
	{
		printf (" |       | |");
		playerconsole2(j, p);
		return;
	}
	if (i == 3)
	{
		printf (" |       | |");
		playerconsole2(j+6, p);
		return;
	}
	if (i == 4)
	{
		printf (" |       | |");
		playerconsole1(j, p);
		return;
	}
	if (i == 5)
	{
		printf (" |       | |");
		playerconsole1(j+6, p);
		return;
	}
	if (i == 6)
	{
		printf (" |       | |");
		int a;
		for (a=0; a<3; a++)
		{
			if (displayboard[i-4][2-a] == 0)
				emc2(j);
			else
				fc2(j, i-4, 2-a);
			emc2(j+5);
		}
		printf ("\b|");
		return;
	}
	if (i == 7)
	{
		printf (" |       | |");
		int a;
		for (a=0; a<3; a++)
		{
			if (displayboard[i-4][a] == 0)
				emc2(j);
			else
				fc2(j, i-4, a);
			emc2(j+5);
		}
		printf ("\b|");
		return;
	}
}

void counterf(int p, int q)
{
	int y1, y2;
	y1 = counter[p][q]%10;
	y2 = counter[p][q]/10;
	
	if (counter[p][q] == 0)
	{
		printf ("| |       (%d)      ", y1);
		return;
	}
		
	if (counter[p][q] > 0)
	{
		if (counter[p][q] == 0)
			printf ("| |       (0)      ");
		else
			printf ("| |      ( %d%d)      ", y2, y1);
		return;
	}
	else
	{
		if (counter[p][q] == 0)
			printf ("| |       (0)      ");
		else
			printf ("| |      (-%u%u)      ", y2, y1);
		return;
	}
}

void num_count(int i)
{
	if (i == 0)
	{
		if (counter[0][0] == 0)
			printf ("| |                ");
		else
			printf ("| |      (%d)       ", counter[0][0]);
		if (counter[0][1] == 0)
			printf ("                ");
		else
			printf ("      (%d)       ", counter[0][1]);
		if (counter[0][2] == 0)
			printf ("               | |\n");
		else
			printf ("      (%d)      | |\n", counter[0][2]);
	}
	if (i == 1)
	{
		counterf(1, 2);
		if (counter[1][1] == 0)
			printf ("                ");
		else
			printf ("      (%d)       ", counter[1][1]);
		if (counter[1][0] == 0)
			printf ("               | |\n");
		else
			printf ("      (%d)      | |\n", counter[1][0]);
	}
	if (i == 5)
	{
		counterf(2, 2);
		if (counter[2][1] == 0)
			printf ("                ");
		else
			printf ("      (%d)       ", counter[2][1]);
		if (counter[2][0] == 0)
			printf ("               | |\n");
		else
			printf ("      (%d)      | |\n", counter[2][0]);
	}
	if (i == 6)
	{
		if (counter[3][0] == 0)
			printf ("| |                ");
		else
			printf ("| |      (%d)       ", counter[3][0]);
		if (counter[3][1] == 0)
			printf ("                ");
		else
			printf ("      (%d)       ", counter[3][1]);
		if (counter[3][2] == 0)
			printf ("               | |\n");
		else
			printf ("      (%d)      | |\n", counter[3][2]);
	}
}

void showconfig(int p)
{
	int i, j;
	pll1();
	pll2();
	pls1();
	pls2();
	for (i=0; i<8; i++)
	{
		int k=0;
		printf ("\t| |");
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == 0)
			{	
				if ((i+j) % 2 != 0)
					bec1(1);
				else
					wec1();
			}
			else
				fun_select(i, j, 1);
		}
		k++;
		scoreboard (i, k, p);
		printf (" |\n\t| |");	
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == 0)
			{
				if ((i+j) % 2 != 0)
					bec1(2);
				else
					wec1();
			}
			else
				fun_select(i, j, 2);
		}
		k++;
		scoreboard (i, k, p);
		printf (" |\n\t| |");	
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == 0)
			{
				if ((i+j) % 2 != 0)
					bec1(3);
				else
					wec1();
			}
			else
				fun_select(i, j, 3);
		}
		k++;
		scoreboard (i, k, p);
		printf (" |\n\t| |");
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == 0)
			{
				if ((i+j) % 2 != 0)
					bec1(2);
				else
					wec1();
			}
			else
				fun_select(i, j, 4);
		}
		k++;
		scoreboard (i, k, p);
		printf (" |\n\t| |");	
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == 0)
			{
				if ((i+j) % 2 != 0)
					bec1(1);
				else
					wec1();
			}
			else
				fun_select(i, j, 5);
		}
		k++;
		scoreboard (i, k, p);
		printf (" |\n");	
		pls1();
		
		if (i == 2)
		{
			printf ("| |");
			playerconsole2(6, p);
			printf (" |\n");
		}
		if (i == 4)
		{
			printf ("| |");
			playerconsole1(6, p);
			printf (" |\n");
		}
		if (i<2 || i==5 || i==6)
			num_count(i);
		if (i == 3)
			emc2(0);
		if (i==7)
			pls2();
	}
	pll1();
	pll2();
}

//directories

int direc_pawn(int a, int b, int c, int d)
{
	if (chess[a][b]/100 == 2)
	{
		if (a > c) return 0;
		if (c > a)
		{
			if (chess[c][d] == 0 && b!=d)	return 0;
			if (c-a>1 && a!=1)	return 0;
			if (c-a>2 && a==1)	return 0;
			if (b-d>1 || d-b>1)	return 0;
		}
	}
	else if (chess[a][b]/100 == 1)
	{
		if (a > c)
		{
			if (chess[c][d] == 0 && b!=d)	return 0;
			if (a-c>1 && a!=6)	return 0;
			if (a-c>2 && a==6)	return 0;
			if (b-d>1 || d-b>1)	return 0;
		}
		if (c > a) return 0;
	}
	return 1;
}

int direc_rook(int a, int b, int c, int d)
{
	int i;
	if (a!=c && b!=d)	return 0;
	if (b==d && a>c)
	for (i=1; i<a-c; i++)
	{
		if (chess[a-i][b] != 0)
			return 0;
	}	
	if (b==d && a<c)
	for (i=1; i<c-a; i++)
	{
		if (chess[a+i][b] != 0)
			return 0;
	}	
	if (a==c && b>d)
	for (i=1; i<b-d; i++)
	{
		if (chess[a][b-i] != 0)
			return 0;
	}	
	if (a==c && b<d)
	for (i=1; i<d-b; i++)
	{
		if (chess[a][b+i] != 0)
			return 0;
	}
	return 1;
}

int direc_knight(int a, int b, int c, int d)
{
	if (c-a==2 && d-b==1)	return 1;
	if (c-a==2 && b-d==1)	return 1;
	if (a-c==2 && d-b==1)	return 1;
	if (a-c==2 && b-d==1)	return 1;
	if (c-a==1 && d-b==2)	return 1;
	if (c-a==1 && b-d==2)	return 1;
	if (a-c==1 && d-b==2)	return 1;
	if (a-c==1 && b-d==2)	return 1;
	return 0; 
}

int direc_bishop(int a, int b, int c, int d)
{
	int i;
	if (c+b-a-d!=0 && c+d-a-b!=0)	return 0;
	if (c+b-a-d == 0)
	{
		if (c > a)
		{
			for (i=1; i<c-a ;i++)
			{
				if (chess[a+i][b+i] != 0)
					return 0;
			}
		}
		if (a > c)
		{
			for (i=1; i<a-c ;i++)
			{
				if (chess[a-i][b-i] != 0)
					return 0;
			}
		}
	}
	if (c+d-a-b == 0)
	{
		if (c > a)
		{
			for (i=1; i<c-a ;i++)
			{
				if (chess[a+i][b-i] != 0)
					return 0;
			}
		}
		if (a > c)
		{
			for (i=1; i<a-c ;i++)
			{
				if (chess[a-i][b+i] != 0)
					return 0;
			}
		}
	}
	return 1;
}

int direc_king(int a, int b, int c, int d)
{
	if (c-a==1 && d-b == 0)	return 1;
	if (a-c==1 && b-d == 0)	return 1;
	if (c-a==0 && d-b == 1)	return 1;
	if (a-c==0 && b-d == 1)	return 1;
	if (c-a==1 && d-b == 1)	return 1;
	if (a-c==1 && b-d == 1)	return 1;
	if (c-a==1 && b-d == 1)	return 1;
	if (a-c==1 && d-b == 1)	return 1;
	return 0;
}

int direc_queen(int a, int b, int c, int d)
{
	if (direc_rook(a, b, c, d)==1 || direc_bishop(a, b, c, d)==1)
		return 1;
	return 0;
}

int checkcastle (int a, int b, int c, int d)
{
	if (a!=0 && a!=7)
		return 0;
	if (a != c)
		return 0;
	if (b != 4)
		return 0;
	if (checkshift[a][b] == 1)
		return 0;
	if (d <= 3)
	{
		if (checkshift[a][0] == 1)
			return 0;
		if (chess[a][1]!=0 || chess[a][2]!=0 || chess[a][3]!=0)
			return 0;
		chess[a][2] = chess[a][4];
		chess[a][4] = 0;
		chess[a][3] = chess[a][0];
		chess[a][0] = 0;
	}
	else
	{
		if (checkshift[a][7] == 1)
			return 0;
		if (chess[a][5]!=0 || chess[a][6]!=0)
			return 0;
		chess[a][6] = chess[a][4];
		chess[a][4] = 0;
		chess[a][5] = chess[a][7];
		chess[a][7] = 0;
	}
	return 1;
}

//directory index/links

int checkdirectory(int a, int b, int c, int d)
{
	switch (chess[a][b])
	{
		case 101 : if (direc_pawn(a, b, c, d) == 0)	return 0; break;
		case 102 : if (direc_rook(a, b, c, d) == 0)	return 0; break;
		case 103 : if (direc_knight(a, b, c, d) == 0)	return 0; break;
		case 104 : if (direc_bishop(a, b, c, d) == 0)	return 0; break;
		case 105 : if (direc_king(a, b, c, d) == 0)	return 0; break;
		case 106 : if (direc_queen(a, b, c, d) == 0)	return 0; break;
		case 201 : if (direc_pawn(a, b, c, d) == 0)	return 0; break;
		case 202 : if (direc_rook(a, b, c, d) == 0)	return 0; break;
		case 203 : if (direc_knight(a, b, c, d) == 0)	return 0; break;
		case 204 : if (direc_bishop(a, b, c, d) == 0)	return 0; break;
		case 205 : if (direc_king(a, b, c, d) == 0)	return 0; break;
		case 206 : if (direc_queen(a, b, c, d) == 0)	return 0; break;
	}
	return 1;
}

int checklegal (int i1, int j1, int i2, int j2)
{
	if (i1 == i2 && j1 == j2)
		return 0;
	if (chess[i1][j1]/100 == chess[i2][j2]/100)
		return 0;
	if (checkdirectory(i1, j1, i2, j2) == 0)
		return 0;
	return 1;
}

void help (void)
{
	printf ("********************************************************************************************************************\n");
	printf ("*                                                   NOTATIONS                                                      *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*                                                                 .       .                                        *\n");
	printf ("*                 @                                              .    @    .                                       *\n");
	printf ("*                / \\      : White Pawn                          .    / \\    . : Black Pawn                         *\n");
	printf ("*                | |                                             .   | |   .                                       *\n");
	printf ("*               =====                                             . =*=*= .                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*               ^^^^^                                             . ^^^^^ .                                        *\n");
	printf ("*               =====                                            .  =====  .                                       *\n");
	printf ("*               |   |     : White Rook                          .   |   |   . : Black Rook                         *\n");
	printf ("*               |   |                                            .  |   |  .                                       *\n");
	printf ("*              =======                                            .=*=*=*=.                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*                  ^                                              .    ^  .                                        *\n");
	printf ("*               <<@@?                                            .  <<@@?  .                                       *\n");
	printf ("*                )  }     : White Knight                        .    )  }   . : Black Knight                       *\n");
	printf ("*               (   )                                            .  (   )  .                                       *\n");
	printf ("*              =======                                            .=*=*=*=.                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*                 ^                                               .   ^   .                                        *\n");
	printf ("*                ( )                                             .   ( )   .                                       *\n");
	printf ("*                | |      : White Bishop                        .    | |    . : Black Bishop                       *\n");
	printf ("*                | |                                             .   | |   .                                       *\n");
	printf ("*               =====                                             . =*=*= .                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*                 +                                               .   +   .                                        *\n");
	printf ("*               ==|==                                            .  ==|==  .                                       *\n");
	printf ("*                | |      : White King                          .    | |    . : Black King                         *\n");
	printf ("*               /   \\                                            .  /   \\  .                                       *\n");
	printf ("*              =======                                            .=*=*=*=.                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("*                 #                                               .   #   .                                        *\n");
	printf ("*               _/^\\_                                            .  _/^\\_  .                                       *\n");
	printf ("*               ((@))     : White Queen                         .   ((@))   . : Black Queen                        *\n");
	printf ("*                ) (                                             .   ) (   .                                       *\n");
	printf ("*              =======                                            .=*=*=*=.                                        *\n");
	printf ("*                                                                                                                  *\n");
	printf ("********************************************************************************************************************\n");
}

int sort(int p)
{
	int c[4][3], db[4][3], i, j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<3; j++)
		{
			c[i][j] = counter[i][j];
			db[i][j] = displayboard[i][j];
		}
	}
	
	// points calculator:
	
	db[1][2] = 0;
	db[2][2] = 0;
	
	for (i=0; i<2; i++)
	{
		for (j=0; j<3; j++)
		{
			if (i == 1 && j == 2)
				break;
			if (db[i][j] == 101)
				db[1][2] = db[1][2] + c[i][j];
			if (db[i][j] == 102)
				db[1][2] = db[1][2] + 5*c[i][j];
			if (db[i][j] == 103)
				db[1][2] = db[1][2] + 3*c[i][j];
			if (db[i][j] == 104)
				db[1][2] = db[1][2] + 3*c[i][j];
			if (db[i][j] == 106)
				db[1][2] = db[1][2] + 9*c[i][j];
		}
	}
	
	for (i=3; i>1; i--)
	{
		for (j=0; j<3; j++)
		{
			if (i == 2 && j == 2)
				break;
			if (db[i][j] == 201)
				db[2][2] = db[2][2] + c[i][j];
			if (db[i][j] == 202)
				db[2][2] = db[2][2] + 5*c[i][j];
			if (db[i][j] == 203)
				db[2][2] = db[2][2] + 3*c[i][j];
			if (db[i][j] == 204)
				db[2][2] = db[2][2] + 3*c[i][j];
			if (db[i][j] == 206)
				db[2][2] = db[2][2] + 9*c[i][j];
		}
	}
	
	displayboard[1][2] = db[1][2];
	displayboard[2][2] = db[2][2];
	
	counter[1][2] = db[1][2] - db[2][2];
	counter[2][2] = db[2][2] - db[1][2];
	
	int x=0, y=0;
	
	if (p == 1)
	{
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				counter[i][j] =0;
				displayboard[i][j] = 0;
			}
		}
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				if (db[i][j] == 201)
				{
					counter[3-x][y] = c[i][j];
					displayboard[3-x][y] = db[i][j];
					y++;
					break;
				}
			}
		}
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				if (db[i][j] == 204)
				{
					counter[3-x][y] = c[i][j];
					displayboard[3-x][y] = db[i][j];
					y++;
					break;
				}
			}
		}
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				if (db[i][j] == 203)
				{
					counter[3-x][y] = c[i][j];
					displayboard[3-x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				if (db[i][j] == 202)
				{
					counter[3-x][y] = c[i][j];
					displayboard[3-x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (i == 2 && j == 2)
					break;
				if (db[i][j] == 206)
				{
					counter[3-x][y] = c[i][j];
					displayboard[3-x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
	}
	if (p == 2)
	{
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 101)
				counter[i][j] = 0;
				displayboard[i][j] = 0;
			}
		}
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 101)
				{
					counter[x][y] = c[i][j];
					displayboard[x][y] = db[i][j];
					y++;
					break;
				}
			}
		}
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 104)
				{
					counter[x][y] = c[i][j];
					displayboard[x][y] = db[i][j];
					y++;
					break;
				}
			}
		}
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 103)
				{
					counter[x][y] = c[i][j];
					displayboard[x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 102)
				{
					counter[x][y] = c[i][j];
					displayboard[x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (i == 1 && j == 2)
					break;
				if (db[i][j] == 106)
				{
					counter[x][y] = c[i][j];
					displayboard[x][y] = db[i][j];
					if (y==2)
					{
						y = 0;
						x++;
					}
					else y++;
					break;
				}
			}
		}
	}
	
	
	return 0;
}

void board (int p, int q, int a)
{
	int i, j;
	for (i=0; i<4; i++)
	{
		for (j=0; j<3; j++)
		{
			if (displayboard[i][j] == chess[p][q])
				counter[i][j]++;
		}
	}
	if (chess[p][q]/100 == 1)
	{
		for (i=0; i<2; i++)
		{
			for (j=0; j<3; j++)
			{
				if (displayboard[i][j] == 0)
				{
					displayboard[i][j] = chess[p][q];
					counter[i][j]++;
					sort(a);
					return;
				}		
			}
		}
	}
	if (chess[p][q]/100 == 2)
	{
		for (i=3; i>1; i--)
		{
			for (j=0; j<3; j++)
			{
				if (displayboard[i][j] == 0)
				{
					displayboard[i][j] = chess[p][q];
					counter[i][j]++;
					sort(a);
					return;
				}		
			}
		}
	}
}

void transform (int a, int b, int p)
{
	int c;
	if (a==0 && chess[a][b] == 101)
	{
		printf ("Your pawn has reached the other end.\n Press:\n");
		printf ("1 to replace with rook\n2 to replace with knight\n3 to replace with bishop\n4 to replace with queen\n");
		scanf ("%d", &c);
		switch (c)
		{
			case 1 : chess[a][b] = 102 ; break ;
			case 2 : chess[a][b] = 103 ; break ;
			case 3 : chess[a][b] = 104 ; break ;
			case 4 : chess[a][b] = 106 ; break ;
			default : transform (a, b, p);
		}
		showconfig(p);
	}
	
	if (a==7 && chess[a][b] == 201)
	{
		printf ("Your pawn has reached the other end.\n Press:\n");
		printf ("1 to replace with rook\n2 to replace with knight\n3 to replace with bishop\n4 to replace with queen\n ");
		scanf ("%d", &c);
		switch (c)
		{
			case 1 : chess[a][b] = 202 ; break ;
			case 2 : chess[a][b] = 203 ; break ;
			case 3 : chess[a][b] = 204 ; break ;
			case 4 : chess[a][b] = 206 ; break ;
			default : transform (a, b, p);
		}
		showconfig(p);
	}
}

int checkpawn1 (int p, int q, int a, int b)
{
	if (p-1==a && q-1==b)
		return 1;
	if (p-1==a && q+1==b)
		return 1;
	return 0;
}

int checkpawn2 (int p, int q, int a, int b)
{
	if (p+1==a && q-1==b)
		return 1;
	if (p+1==a && q+1==b)
		return 1;
	return 0;
}

int checkrook (int p, int q, int a, int b)
{
	int i;
	for (i=p-7; i<p+8, i>=0, i<8; i++)
	{
		if (p+i==a && q==b)
			return 1;
		if (p==a && q+i==b)
			return 1;
	}
	return 0;
}

int checkknight (int p, int q, int a, int b)
{
	if (p+1==a && q+2==b)
		return 1;
	if (p+1==a && q-2==b)
		return 1;
	if (p-1==a && q+2==b)
		return 1;
	if (p-1==a && q-2==b)
		return 1;
	if (p+2==a && q+1==b)
		return 1;
	if (p+2==a && q-1==b)
		return 1;
	if (p-2==a && q+1==b)
		return 1;
	if (p-2==a && q-1==b)
		return 1;
	return 0;
}

int checkbishop (int p, int q, int a, int b)
{
	int i;
	for (i=p-7; i<p+8, i>=0, i<8; i++)
	{
		if (p+i==a && q+i==b)
			return 1;
		if (p-i==a && q+i==b)
			return 1;
	}
	return 0;
}

int checkqueen (int p, int q, int a , int b)
{
	if (checkrook(p, q, a, b) == 1 || checkbishop(p, q, a, b) == 1)
		return 1;
	return 0;
}

int check_threat(int a, int b)
{
	int i, j;
	
	if (a/100 == 2)
	{
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{	
				if (chess[i][j] == 101)
					if (checkpawn1(i, j, a, b) == 1)
						return 2;
				if (chess[i][j] == 102)
					if (checkrook(i, j, a, b) == 1)
						return 2;
				if (chess[i][j] == 103)
					if (checkknight(i, j, a, b) == 1)
						return 2;
				if (chess[i][j] == 104)
					if (checkbishop(i, j, a, b) == 1)
						return 2;
				if (chess[i][j] == 106)
					if (checkqueen(i, j, a, b) == 1)
						return 2;
			}
		}
	}
	
	if (a/100 == 1)
	{
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if (chess[i][j] == 201)
					if (checkpawn2(i, j, a, b) == 1)
						return 1;
				if (chess[i][j] == 202)
					if (checkrook(i, j, a, b) == 1)
						return 1;
				if (chess[i][j] == 203)
					if (checkknight(i, j, a, b) == 1)
						return 1;
				if (chess[i][j] == 204)
					if (checkbishop(i, j, a, b) == 1)
						return 1;
				if (chess[i][j] == 206)
					if (checkqueen(i, j, a, b) == 1)
						return 1;
			}
		}
	}
	return 0;
}

int posfinder(int a)
{
	int i, j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			if (chess[i][j] == a)
				return (10*i + j);
		}
	}
	return 0;
} 

int checkmate (void)
{
	int i, j, p, q, r, s, count1=0, count2=0;
	p = posfinder(105);
	q = p%10;
	p = p/10;
	r = posfinder(205);
	s = r%10;
	r = r/10;
	
	//for whites;
	if (check_threat(p, q) != 0)
	{
		for (i=-1; i<=1, p+i>=0, p+i<8; i++)
		{
			for (j=-1; j<=1, q+j>=0, q+j<8; j++)
			{
				if (i==0 && j==0)
					continue;
				if (chess[p+i][q+j] == 0 || chess[p+i][q+j]/100 == 2)
				{
					count1++;
					if (check_threat(p+i, q+j) == 1)
						count2++;
				}
			}
		}
		
		if (count2 == count1 && count2 != 0)
			return 1;
			return 3;
	}
	
	//for blacks;
	count1 = 0;
	count2 = 0;
	if (check_threat(r, s) != 0)
	{
		for (i=-1; i<=1, r+i>=0, r+i<8; i++)
		{
			for (j=-1; j<=1, s+j>=0, s+j<8; j++)
			{
				if (i==0 && j==0)
					continue;
				if (chess[r+i][s+j] == 0 || chess[r+i][s+j]/100 == 1)
				{
					count1++;
					if (check_threat(r+i, s+j) == 2)
					count2++;
				}
			}
		}
		if (count2 == count1 && count2 !=0)
			return 2;
			return 4;
	}
	
	return 0;
}

int stalemate(void)
{
	int i, j, p, q, r, s, count1=0, count2=0, count=0;
	p = posfinder(105);
	q = p%10;
	p = p/10;
	r = posfinder(205);
	s = r%10;
	r = r/10;
	//for whites;
	for (i=7; i>=0; i--)
	{
		for (j=7; j>=0; j--)
		{
			if (chess[i][j]/100 == 1 && chess[i][j] != 101 )
				count++;
			if (chess[i][j] == 101)
			{
				if (chess[i-1][j] == 0)
					count++;
				if (chess[i-1][j-1]/100 == 2 || chess[i-1][j+1]/100 == 2)
					count++;
			}			
			if (count > 1)
				break;
		}
	}
	if (count == 1)
	{
		if (check_threat(p, q) == 0)
		{
			for (i=-1; i<=1, p+i>=0, p+i<8; i++)
			{
				for (j=-1; j<=1, q+j>=0, q+j<8; j++)
				{
					if (i==0 && j==0)
						continue;
					if (chess[p+i][q+j]/100 != 1)
					{
						count1++;
						if (check_threat(p+i, q+j) == 1)
						count2++;
					}
				}
			}
		}
	}
	if (count2 == count1 && count1 != 0)
		return 1;
	
	//for blacks;
	count = 0;
	count1 = 0;
	count2 = 0;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			if (chess[i][j]/100 == 2 && chess[i][j] != 201 )
				count++;
			if (chess[i][j] == 201)
			{
				if (chess[i+1][j] == 0)
					count++;
				if (chess[i+1][j-1]/100 == 1 || chess[i+1][j+1]/100 == 1)
					count++;
			}			
			if (count > 1)
				break;
		}
	}
	if (count == 1)
	{
		if (check_threat(r, s) == 0)
		{
			for (i=-1; i<=1, r+i>=0, r+i<8; i++)
			{
				for (j=-1; j<=1, s+j>=0, s+j<8; j++)
				{
					if (i==0 && j==0)
						continue;
					if (chess[r+i][s+j]/100 != 2)
					{
						count1++;
						if (check_threat(r+i, s+j) == 2)
						count2++;
					}
				}
			}
		}
	}
	if (count2 == count1 && count1 != 0)
		return 1;
	return 0;
}

int checkfinish ()
{
	if (checkmate() == 1)
	{
		printf ("\n\n White(player I) won by checkmate.... \n\n");
		return 1;
	}
	if (checkmate() == 2)
	{
		printf ("\n\n Black(player II) won by checkmate.... \n\n");
		return 1;
	}
	if (checkmate() == 3)
	{
		printf ("\n\n White king's position is under threat.\n\n");
		return 0;
	}
	if (checkmate() == 4)
	{
		printf ("\n\n Black king's position is under threat.\n\n");
		return 0;
	}
	if (stalemate() == 1)
	{
		printf ("\n\n Match results in draw due to stalemate.... \n\n");
		return 1;
	}
	return 0;
}

int positionswap (int p)
{
	int i1, i2, j1, j2;
	printf ("Enter the address of initial and final cells in the form i1 j1 i2 j2  **FOR ANY HELP OR GUIDANCE YOU CAN TYPE'0 0 0 0'**\n");
	/*
	scanf("%c %d %c %d", &i1, &j1, &i2, &j2);
	
	*/
	scanf ("%d %d %d %d", &i1, &j1 ,&i2, &j2);
	if (i1==0 && i2==0 && j1==0 && j2==0)
	{
		help();
		return 0;
	}
	i1--;
	i2--;
	j1--;
	j2--;
	
	if (chess[i1][j1] == 0)
	{
		printf("\nEnter correct values.\n\n");
		return 0;
		
	}
	if (chess[i1][j1]/100 != p)
	{
		printf ("You are not allowed to move other player's piece.\n");
		return 0;
	}
	
	if (i1==0 || i1==7)
	{
		if (checkcastle(i1, j1, i2, j2) == 1)
		{	
			checkshift[i1][j1]++;
			showconfig(3-p);
			return 1;
		}
	}
	
	if (checklegal(i1, j1, i2, j2) == 0)
	{
		printf ("Movement restricted : illegal move\n");
		return 0;
	}
	
	if (chess[i2][j2] != 0)
		board(i2, j2, p);
	
	chess[i2][j2] = chess[i1][j1];
	chess[i1][j1] = 0;
	checkshift[i1][j1]++;
	showconfig(3-p);
	transform(i2, j2, 3-p);
	
	if (checkfinish() == 1)
	{
		printf ("\t\t ...GAME OVER...");
		return 2;
	}
	return 1;
}	

int main ()
{
	int p=1, ret;
	display_logo();
	initconfig();
	showconfig(1);
	while (1)
	{
		printf ("Player %d's turn.\n", p);
		
		ret = positionswap(p);
		if (ret == 0)
			continue;
		else if (ret == 2)
			return 0;
		else if (ret == 1)
			p = 3 - p; // player switch;
	}
	return 0;
}

