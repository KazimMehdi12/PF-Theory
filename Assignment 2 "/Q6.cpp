#include<stdio.h>
int condition_for_win(int N);
int main(){
	int N;
    printf("\t\t *** Matchsticks Game ***\n\n");

    printf("Welcome to the Matchsticks Game!\n");
    printf("In this game, A plays first. The goal is to take the last matchstick.\n");
    printf("You can pick 1 to 4 matchsticks on each turn.\n\n");
    
    printf("Enter the number of matchsticks on the table: ");
    scanf("%d", &N);
    
    if (N <= 0) {
        printf("Please enter a positive number of matchsticks.\n");
        return 1; 
    }
	
	int result = condition_for_win(N);
    
    if (result == -1) {
        printf("It is impossible for A to win the game.\n");
    } else {
        printf("A should pick %d matchsticks in the first turn to win the game.\n", result);
    }
    
	return 0;
}

int condition_for_win(int N){
	if(N%5 == 0) return -1;
	else return N%5;
}