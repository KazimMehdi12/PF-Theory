#include<stdio.h>
struct date{
	int day,month,year;
};
struct Employee{
	char employeeName[30];
	unsigned int employeeCode;
	struct date dateOfJoining;
};
void assignValues(struct Employee emp[4]){
	for(int i=0; i<4; i++){
	printf("\nEnter Employee_%d's Code: ",i+1);
	scanf("%u",&emp[i].employeeCode);
	printf("Enter Employee_%d's Name: ",i+1);
	scanf("%29s",emp[i].employeeName);
	printf("Enter Employee_%ds Date of joining': ",i+1);
	printf("\nEnter year: ");
	scanf("%d",&emp[i].dateOfJoining.year);
	printf("Enter month: ");
	do{
		scanf("%d",&emp[i].dateOfJoining.month);
		if(emp[i].dateOfJoining.month<1 || emp[i].dateOfJoining.month>12)
			printf("Invalid month entered, Re-Enter please");
	}
	while(emp[i].dateOfJoining.month<1 || emp[i].dateOfJoining.month>12);
	printf("Enter day: ");
	do{
	scanf("%d",&emp[i].dateOfJoining.day);
	if(((emp[i].dateOfJoining.month==1 || emp[i].dateOfJoining.month==3 || emp[i].dateOfJoining.month==5 || emp[i].dateOfJoining.month==7 || emp[i].dateOfJoining.month==8 || emp[i].dateOfJoining.month==10 || emp[i].dateOfJoining.month==12) && (emp[i].dateOfJoining.day<1||emp[i].dateOfJoining.day>31)) || ((emp[i].dateOfJoining.month==11 || emp[i].dateOfJoining.month==9 || emp[i].dateOfJoining.month==6 || emp[i].dateOfJoining.month==4)&&(emp[i].dateOfJoining.day<1||emp[i].dateOfJoining.day>30)) || (emp[i].dateOfJoining.month==2 && ((emp[i].dateOfJoining.year%4==0 && (emp[i].dateOfJoining.day<1 || emp[i].dateOfJoining.day>29)) || emp[i].dateOfJoining.year%4!=0 && (emp[i].dateOfJoining.day<1 || emp[i].dateOfJoining.day>28))))
		printf("Invalid day entered, Re-Enter Please.");
	}while(((emp[i].dateOfJoining.month==1 || emp[i].dateOfJoining.month==3 || emp[i].dateOfJoining.month==5 || emp[i].dateOfJoining.month==7 || emp[i].dateOfJoining.month==8 || emp[i].dateOfJoining.month==10 || emp[i].dateOfJoining.month==12) && (emp[i].dateOfJoining.day<1||emp[i].dateOfJoining.day>31)) || ((emp[i].dateOfJoining.month==11 || emp[i].dateOfJoining.month==9 || emp[i].dateOfJoining.month==6 || emp[i].dateOfJoining.month==4)&&(emp[i].dateOfJoining.day<1||emp[i].dateOfJoining.day>30)) || (emp[i].dateOfJoining.month==2 && ((emp[i].dateOfJoining.year%4==0 && (emp[i].dateOfJoining.day<1 || emp[i].dateOfJoining.day>29)) || emp[i].dateOfJoining.year%4!=0 && (emp[i].dateOfJoining.day<1 || emp[i].dateOfJoining.day>28))));
	printf("\n");
	}
}
void tenure(struct Employee emp[4],int *count){
	int d,m,y;
	float years;
	printf("Enter Current date:");
	printf("\nEnter year: ");
	scanf("%d",&y);
	printf("Enter month: ");
	do{
		scanf("%d",&m);
		if(m<1 || m>12)
			printf("Invalid month entered, Re-Enter please");
	}
	while(m<1 || m>12);
	printf("Enter day: ");
	do{
	scanf("%d",&d);
	if(((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d<1||d>31)) || ((m==11 || m==9 || m==6 || m==4)&&(d<1||d>30)) || (m==2 && ((y%4==0 && (d<1 || d>29)) || y%4!=0 && (d<1 || d>28))))
		printf("Invalid day entered, Re-Enter Please.");
	}while(((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d<1||d>31)) || ((m==11 || m==9 || m==6 || m==4)&&(d<1||d>30)) || (m==2 && ((y%4==0 && (d<1 || d>29)) || y%4!=0 && (d<1 || d>28))));
	
	
	printf("\n\n");
	for(int i=0; i<4; i++){
		years=y-emp[i].dateOfJoining.year+(m-emp[i].dateOfJoining.month)/12.0 + (d-emp[i].dateOfJoining.day)/365.0;
		if(years>3) {
			printf("Employee's Name: %s, Employee's Code: %u, Employee's Date of Joining: %d-%d-%d\n",emp[i].employeeName,emp[i].employeeCode,emp[i].dateOfJoining.day,emp[i].dateOfJoining.month,emp[i].dateOfJoining.year);
			(*count)++;
		}
	}
}
int main(){
	struct Employee emp[4];
	assignValues(emp);
	
	int count=0;
	tenure(emp,&count);
	printf("\nThese %d Employees have tenure more than 3 years.",count);
	return 0;
}uuu