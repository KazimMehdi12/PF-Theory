#include<stdio.h>
int main(){
	int size;
	printf("How many slogans' frequency of letters will you love to analyze? : ");
	scanf("%d",&size);
	char str[size][100];
	for(int a=0;a<size;a++){
		printf("Enter slogan %d : ",a+1);
		scanf(" %[^\n]",str[a]);
	}
	//int freq[122];
	for(int i=0; i<size; i++){
		int freq[122]={0};
		for(int j=0; str[i][j]!='\0' ; j++){
			freq[ str[i][j] ]++;
		}
		printf("For \"%s\" : {",str[i]);
		for(int k=0,count=0;k<122;k++){
			if(freq[k] != 0 ){
				if(count!=0) printf(","); count++;
				printf("'%c':%d",k,freq[k]);
			}
		}
		printf("}\n");
		
	}
	}