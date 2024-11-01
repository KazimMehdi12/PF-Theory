#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
void assign_to_array(char arr[6][5]);
void display_array(char arr[6][5]);


int main(){

	char arr[6][5];
	assign_to_array(arr);
	display_array(arr);
	char search_string[7];
	int score=0,found;
	
	while(strcmp(search_string,"END") !=0 ){
		printf("Enter search string (enter END to exit): ");
		scanf("%6s", search_string);
		int len=strlen(search_string);
		found=1;
		
	if(strcmp(search_string,"END") ==0 ){
		printf("\nYou chose to quit\n");
		break;
	}
		
	//horizontal
	for(int i=0;i<6;i++){
		if(strncmp(search_string,arr[i],len) == 0){
			found=1;
			break;
		}else {
			found=-1;
		}
	}
	//Vertical

	for(int i=0;i<5;i++){
		if(found == -1){
			for(int j=0; j<len; j++){
				if(search_string[j]!=arr[j][i]){
					found=-1;
					break;
				}else {
					found=1;
				}
			}
		}
	}
	if(found==1){
			score++;
			printf("%s is present score %d\n\n",search_string,score);
	} else if(found ==-1){
			score--;
			printf("%s is not present score %d\n\n",search_string,score);
	}
	
	
	}
	
	
}



void assign_to_array(char arr[6][5]){
	srand(time(0));
	
	for(int i=0; i<6; i++){
		for(int j=0; j<5; j++){
			do{
				arr[i][j]= 'A' + rand()%65;
			}while(arr[i][j] < 'A' || arr[i][j] > 'Z');
		}
	}
	arr[5][0]='0';
	arr[5][2]='0';
	arr[5][1]='8';
	arr[5][3]='5';
}

void display_array(char arr[6][5]){
	printf(" -------------------\n");
	for(int i=0; i<6; i++){
		printf("| ");
		for(int j=0; j<5; j++){
			printf("%c ",arr[i][j]);
			printf("| ");
		}
		printf("\n -------------------\n");
	}
}

