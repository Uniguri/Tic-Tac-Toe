#include "function.h"

int main(){
	int x = 0;
	int y = 0;
	int check1 = 0;
	int check2 = 1;
	char winner = 0;
	char cell[3][3] = { {0, 0, 0}, 
						{0, 0, 0}, 
						{0, 0, 0}};
						
	CC;
	printCell(cell);
	printf("Write your cell like \"x,y\"(1 <= x,y <= 3) \n");
	
	int i = 0;
	while(1){
		do{ //A's turn
			check1 = 0;
			check2 = 1;
			REDC;
			printf("A's turn:");
			RESETC;
			check1 = ( scanf("%d,%d", &x, &y) == 2 );
			x--;y--;
			if( (cell[x][y] == 0) && (check1 == 1) && (0<=x) && (x<=2) && (0<=y) && (y<=2) )
				cell[x][y] = 'A';
			else
				check2 = 0;
			printCell(cell);
		} while( (check1 != 1) || !(check2) );
		i++;
		
		if( checkWinner(cell) ){
			REDC;
			printf("Winner is A\n");
			RESETC;
			goto end;
		}
		
		if(i == 9){
			printf("There is no Winner!..\n");
			goto end;
		}
		
		do{ //B's turn
			check1 = 0;
			check2 = 1;
			BLUEC;
			printf("B's turn:");
			RESETC;
			check1 = ( scanf("%d,%d", &x, &y) == 2 );
			x--;y--;
			if( (cell[x][y] == 0) && (check1 == 1) && (0<=x) && (x<=2) && (0<=y) && (y<=2) )
				cell[x][y] = 'B';
			else
				check2 = 0;
			printCell(cell);
		} while( (check1 != 1) || !(check2 ) );
		i++;
		
		if( checkWinner(cell) ){
			BLUEC;
			printf("Winner is B\n");
			RESETC;
			goto end;
		}
		
	}
end:
	getch();
	return 0;
}
