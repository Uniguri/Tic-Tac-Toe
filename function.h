#include <stdio.h>
#include <stdlib.h>
#define REDC printf("\033[0;31m") //Set Print Color Red
#define BLUEC printf("\033[0;34m")   //Set Print Color Blue
#define RESETC printf("\033[0m")  //Reset Print Color 
#define CC system("cls")          //CC stands for Console Clear

void printCell(char cell[3][3]){ //Print Now Cell's State
	CC;
	for(int y = 0; y<3 ; y++){
		for(int x = 0; x<3 ; x++){
			if(cell[x][y] == 'A'){
				REDC;
				printf("A");
				RESETC;
			}
			else 
				if(cell[x][y] == 'B'){
					BLUEC;
					printf("B");
					RESETC;
				}
				else{
					printf("*");
				}
			printf(" ");
		}
		printf("          (1,%d), (2,%d), (3,%d)", (y+1), (y+1), (y+1));
		printf("\n");
	}
}

int checkWinner(char cell[3][3]){ //Check Winner Based On Now Cell's State
	// (0,0), (1,0), (2,0)     top line        le  mi  ri
	// (0,1), (1,1), (2,1)     middle line     ft  dd  gh
	// (0,2), (1,2), (2,2)     bottom line         le
	
	if(cell[0][0] != 0){
		if( (cell[0][0] == cell[1][0]) && (cell[1][0] == cell[2][0]) ) return 1; //top line
		if( (cell[0][0] == cell[1][1]) && (cell[1][1] == cell[2][2]) ) return 1; //left top line to right bottom line diagonal
		if( (cell[0][0] == cell[0][1]) && (cell[0][1] == cell[0][2]) ) return 1; //left 
	}
	if(cell[0][1] != 0){
		if( (cell[0][1] == cell[1][1]) && (cell[1][1] == cell[2][1]) ) return 1; //middle line
	}
	if(cell[0][2] != 0){
		if( (cell[0][2] == cell[1][2]) && (cell[1][2] == cell[2][2]) ) return 1; //bottom line
		if( (cell[0][2] == cell[1][1]) && (cell[1][1] == cell[2][0]) ) return 1; // left bottom to right top diagnoal
	}
	if(cell[1][0] != 0){
		if( (cell[1][0] == cell[1][1]) && (cell[1][1] == cell[1][2]) ) return 1; //middle
	}
	if(cell[2][0] != 0){
		if( (cell[2][0] == cell[2][1]) && (cell[2][1] == cell[2][2]) ) return 1; //right
	}
	
	return 0;
}