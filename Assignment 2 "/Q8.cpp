#include<stdio.h>
#include<math.h>
#include<string.h>

int BinaryToDecimal(long long int number);
long long int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]); 
void BinaryToHexadecimal(long long int number); 
void HexadecimalToBinary(char hexNumber[]); 

int main(){
	
	printf("\t\tWelcome for numerical conversion \n\n");
	printf("Menu of functions :\n\n");
	printf("1. Convert a binary number to its decimal equivalent.\n");
	printf("2. Convert a decimal number to its binary equivalent.\n");
	printf("3. Convert a decimal number to its hexadecimal equivalent.\n");
	printf("4. Convert a hexadecimal number to its decimal equivalent.\n");
	printf("5. Convert a binary number to its hexadecimal equivalent.\n");
	printf("6. Convert a hexadecimal number to its binary equivalent.\n");
	
	printf("\nEnter your choice of function:");
	int choice;
	scanf("%d",&choice);
	
	int number,result;
	long long int num;
	char hexa[50];
	
	switch(choice){
		case 1:
			printf("Enter number : ");
			scanf("%lld",&num);
			result=BinaryToDecimal(num);
			if(result>=0)
			printf("Decimal: %lld",result);
			break;
		case 2:
			printf("Enter number : ");
			scanf("%d",&number);
			printf("Binary: %lld",DecimalToBinary(number));
			break;
		case 3:
			printf("Enter number : ");
			scanf("%d",&number);
			DecimalToHexadecimal(number);
			break;
		case 4:
			printf("Enter hexadecimal : ");
			scanf("%s",hexa);
			HexadecimalToDecimal(hexa);
			break;
		case 5:
			printf("Enter number : ");
			scanf("%lld",&num);
			BinaryToHexadecimal(num);
			break;
		case 6:
			printf("Enter hexadecimal : ");
			scanf("%s",hexa);
			HexadecimalToBinary(hexa);
			break;
		default :
			printf("Invalid choice entered!");
	}
	
	return 0;
}


int BinaryToDecimal(long long int number){
	long long int bin=number;
	int decimal=0;
	for(int i=0;bin!=0;i++){
		if(bin%10 != 1 && bin%10 != 0){
			printf("Invalid number entered\n");
			return -1;
		} else{
			decimal+=(bin%10)*pow(2,i);
			bin/=10;
		}
		
	}
	return decimal;
}


long long int DecimalToBinary(int number){
	long long int binary=0;
	for(long long int i=1;number!=0;i*=10){
		binary+=(number%2)*i;
		number/=2;
	}
	return binary;
}


void DecimalToHexadecimal(int number){
	int digits=0,temp=number,ans;
	for(;temp!=0;temp/=16,digits++); //digits in hexa
	char hex[digits];
	for(int i=digits-1;i>=0;i--){
		ans=number%16;
		if(ans>=1&&ans<=9){
			hex[i]=ans + '0'; //number to character
		} else{
			hex[i]= 'A' + ans - 10;
		}
		number/=16;
	}
	printf("Hexadecimal : %s",hex);
}


void HexadecimalToDecimal(char hexNumber[]){
	int len=strlen(hexNumber);
	long long int decimal=0;
	for(int i=len-1,j=0;i>=0;i--,j++){
		if((hexNumber[i]>='A' && hexNumber[i]<='F') || (hexNumber[i] >='0' && hexNumber[i]<='9') || (hexNumber[i]>='a' && hexNumber[i]<='f')){
		
			if(hexNumber[i]>='A' && hexNumber[i]<='F'){
			decimal+=( (hexNumber[i]-'A'+10) * pow(16,j));
			} else if((hexNumber[i]>='a' && hexNumber[i]<='f')){
				decimal+=((hexNumber[i]-'a'+10) * pow(16,j));
			} else{
				decimal+=((hexNumber[i]-'0') * pow(16,j));
			}
		}
		else {
			printf("Invalid number entered\n");
			decimal=-1;
			break;
		}
	
	}
	if(decimal>=0)
	printf("Decimal: %ld",decimal);
} 


void BinaryToHexadecimal(long long int number){
	int dec=BinaryToDecimal(number);
			if(dec>=0){
			DecimalToHexadecimal(dec);
			} 
			
}


void HexadecimalToBinary(char hexNumber[]){
		int len=strlen(hexNumber);
		if(len>4) 
			{
				printf("Sorry! Too long binary number for the compiler!");
			}
	else {
		long long int decimal=0;
	for(int i=len-1,j=0;i>=0;i--,j++){
		if((hexNumber[i]>='A' && hexNumber[i]<='F') || (hexNumber[i] >='0' && hexNumber[i]<='9') || (hexNumber[i]>='a' && hexNumber[i]<='f')){
		
			if(hexNumber[i]>='A' && hexNumber[i]<='F'){
			decimal+=( (hexNumber[i]-'A'+10) * pow(16,j));
			} else if((hexNumber[i]>='a' && hexNumber[i]<='f')){
				decimal+=((hexNumber[i]-'a'+10) * pow(16,j));
			} else{
				decimal+=((hexNumber[i]-'0') * pow(16,j));
			}
		}
		else {
			printf("Invalid number entered\n");
			decimal=-1;
			break;
		}
	
	}
	if(decimal>=0)
		printf("Binary: %lld",DecimalToBinary(decimal));
	}
	
}
