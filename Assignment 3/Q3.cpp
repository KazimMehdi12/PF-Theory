#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int validateEmail(char* email);
int main(){
	char * email=(char*)malloc(50*sizeof(char));
	printf("Enter email for validation (shouldn't contain space)\n");
	scanf("%s",email); //instead of fgets to automatically discard the content after space 
	int len = strlen(email);
	email=(char*)realloc(email,len*sizeof(char));
	if(len>0 && email[len-1]=='\n'){
		email[len-1]='\0';
		len--;
	}
	if(validateEmail(email)) printf("Valid Email");
	else printf("Invalid Email");
	free(email);
	return 0;
}
int validateEmail(char* email){
	int count=0,dotcount=0;
	if(strlen(email)==0) return 0;
	for(int i=0; i<strlen(email); i++){
		if(email[i]=='@') {
			count++;
			if(count>1) return 0;
		}
		if(count==1){
			if(email[i]=='.') dotcount++;
		}
	}
	if (dotcount < 1) return 0;
	return 1;	
}