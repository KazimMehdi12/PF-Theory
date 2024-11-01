#include<stdio.h>
void display_grid(char grid[5][5]);
void welcome(void);
int main(){
	
	welcome();
	
	char grid[5][5] = {
	{' ', ' ', '|', 'X', ' '},
	{' ', 'X', ' ', ' ', ' '},
	{'|', ' ', 'X', 'X', ' '},
	{' ', ' ', ' ', '|', 'X'},
	{' ', 'X', ' ', ' ', 'P'}
	};
	
	char move;
	int items=0,moves=0;
	int rowp=4,colp=4;
	
	while (1){
		printf("\nThe current grid is: \n");
		display_grid(grid);
		printf("Enter a move (W: up, S: down, A: left, D: right, Q: quit) : ");
		scanf(" %c",&move);
		moves++;
		
		if(move == 'W' || move == 'w'){
			if(rowp-1>=0){
			if(grid[rowp-1][colp] == 'X'){
				printf("can't move there, obstacle is present.\n");
			} else if(grid[rowp-1][colp] == '|'){
				printf("Congratulations! you have collected the item.\n");
				items++;
				rowp--;
				grid[rowp][colp]='P';
				grid[rowp+1][colp]=' ';
				
			}else if(grid[rowp-1][colp] == ' '){
				printf("You moved up.\n");
				rowp--;
				grid[rowp][colp]='P';
				grid[rowp+1][colp]=' ';
			}
			} else printf("Invalid move.\n");
		} 
		
		else if(move == 'S' || move == 's'){
			if(grid[rowp+1][colp] == 'X'){
				printf("can't move there, obstacle is present.\n");
			} else if(grid[rowp+1][colp] == '|'){
				printf("Congratulations! you have collected the item.\n");
				items++;
				rowp++;
				grid[rowp][colp]='P';
				grid[rowp-1][colp]=' ';
			}else if(grid[rowp+1][colp] == ' '){
				printf("You moved down.\n");
				rowp++;
				grid[rowp][colp]='P';
				grid[rowp-1][colp]=' ';
			} else printf("Invalid move.\n");
		}
		
		else if(move == 'A' || move == 'a'){
			if(colp-1>=0){
			if(grid[rowp][colp-1] == 'X'){
				printf("can't move there, obstacle is present.\n");
			} else if(grid[rowp][colp-1] == '|'){
				printf("Congratulations! you have collected the item.\n");
				items++;
				colp--;
				grid[rowp][colp]='P';
				grid[rowp][colp+1]=' ';
			}else if(grid[rowp][colp-1] == ' '){
				printf("You moved left.\n");
				colp--;
				grid[rowp][colp]='P';
				grid[rowp][colp+1]=' ';
			}
			} else printf("Invalid move.\n");
		}
		
		else if(move == 'D' || move == 'd'){
			if(colp+1<5){
			if(grid[rowp][colp+1] == 'X'){
				printf("can't move there, obstacle is present.\n");
			} else if(grid[rowp][colp+1] == '|'){
				printf("Congratulations! you have collected the item.\n");
				items++;
				colp++;
				grid[rowp][colp]='P';
				grid[rowp][colp-1]=' ';
			}else if(grid[rowp][colp+1] == ' '){
				printf("You moved rightward.\n");
				colp++;
				grid[rowp][colp]='P';
				grid[rowp][colp-1]=' ';
			}
			} else printf("Invalid move.\n");
		}
		
		else if(move == 'Q' || move == 'q'){
			printf("You chose to quit\n");
			printf("Items collected : %d\n",items);
			printf("Total moves : %d",moves-1);
			return 0;
		}
		
		else{
			printf("Invalid Move\n");
		}
	}
	
}

void display_grid(char grid[5][5]){
	for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				printf("%c ",grid[i][j]);
			}
			printf("\n");
		}
	printf("\n");
}

void welcome(void){
	printf("\n");
	for(int i=0;i<120;i++) printf("*");
	printf("\t\t\t\t\tWelcome to grid-based adventure game\n");
	for(int i=0;i<120;i++) printf("*");
	printf("\n");
}
