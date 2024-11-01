#include<stdio.h>
#include<string.h>

void modify(int size, char string[][100], int* rem);

int main(){
	int size;
	printf("How many words will you love to fix? : ");
	scanf("%d",&size);
	char str[size][100];
	for(int a=0;a<size;a++){
		printf("Enter word %d : ",a+1);
		scanf(" %[^\n]",str[a]);
	}
	
	static int removed=0;
	
	modify(size,str,&removed);

	printf("Corrected words are : ");

	for(int i=0;i<size;i++) {
		printf("%s",str[i]);
		if(i==size-1) ; else printf(", ");
	}
	
	printf("\nTotal %d characters removed",removed);
	
	return 0;
}

void modify(int size, char string[][100], int* rem){
	for(int rows=0; rows<size; rows++){
		for(int i=0; i<strlen(string[rows]); i++){
		
			if(string[rows][i] == string[rows][i+1]){
				for(int z=i;string[rows][z+1]!='\0';z++){
					string[rows][z]=string[rows][z+1];
				}
				string[rows][strlen(string[rows]) - 1] = '\0';
        		 i--;
        		 *rem+=1;
			}
			 
		}

	}
		
}
