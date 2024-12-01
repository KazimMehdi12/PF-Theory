#include<stdio.h>
struct Player{
	int ballScores[12];
	char playerName[30];
	int totalScore;
};
int validateScore(int score){
	if(score>=0 && score<=6) return 1;
	else return 0;
}
void playGame(struct Player *player){
	int score;
	for(int i=0; i<12; i++){
		printf("Enter score for ball %d : ",i+1);
		scanf(" %d",&score);
		if(validateScore(score)) {
			player->ballScores[i] = score;
			player->totalScore += score;
		}else {
			printf("Invalid score! This ball is marked but score is disregarded.\n");
			player->ballScores[i]=0;
		}
	}
}
void findWinner(struct Player player1,struct Player player2){
	if(player1.totalScore > player2.totalScore) printf("Congratulations! to %s, Won the game",player1.playerName);
	else if(player1.totalScore < player2.totalScore) printf("Congratulations! to %s, Won the game",player2.playerName);
	else if(player1.totalScore == player2.totalScore) printf("Match drawn!");
}
void displayMatchScoreboard(struct Player player1,struct Player player2){
	printf("\n\nMatch Score Board: \n\n");
	printf("%-15s","Player");
	for(int i=0;i<12;i++) printf("B%-5d",i+1);
	printf("\tTotal\tAverage\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("%-15s",player1.playerName);
	for(int i=0;i<12;i++) printf("%-6d",player1.ballScores[i]);
	printf(" %d\t%.2f",player1.totalScore,player1.totalScore/12.0);
	printf("\n");
	printf("%-15s",player2.playerName);
	for(int i=0;i<12;i++) printf("%-6d",player2.ballScores[i]);
	printf(" %d\t%.2f",player2.totalScore,player2.totalScore/12.0);
	printf("\n---------------------------------------------------------------------------------------------\n");
	
}
int main(){
	struct Player player1,player2;
	printf("Enter Name of player 1: ");
	gets(player1.playerName);
	printf("Enter Name of player 2: ");
	gets(player2.playerName);
	player1.totalScore=0;
	player2.totalScore=0;
	printf("\nPlayer %s's turn: \n",player1.playerName);
	playGame(&player1);
	printf("\nPlayer %s's turn: \n",player2.playerName);
	playGame(&player2);
	
	displayMatchScoreboard(player1,player2);
	printf("\n\nWinner announcement:\n");
	findWinner(player1,player2);

	return 0;
}
