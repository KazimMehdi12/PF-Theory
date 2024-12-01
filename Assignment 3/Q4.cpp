#include<stdio.h>
#include<stdlib.h>
typedef struct Employee{
    int* ratings;   
    int totalScore; 
} Employee;
void inputEmployees(Employee *employees, int numEmployees,int numPeriods){
	for(int i=0; i<numEmployees; i++){
		employees[i].ratings = (int*) calloc(numPeriods, sizeof(int));
		employees[i].totalScore=0;
		printf("\nEnter ratings for employee %d: \n",i+1);
		for(int j=0; j<numPeriods;j++){
			 do {
                printf("  Rating for period %d (1-10): ", j + 1);
                scanf("%d", &employees[i].ratings[j]);
                if (employees[i].ratings[j] < 1 || employees[i].ratings[j] > 10) {
                    printf("  \t\tInvalid rating entered! Rating must be between 1 and 10.\nRe-Enter");
                }
            } while (employees[i].ratings[j] < 1 || employees[i].ratings[j] > 10);
            employees[i].totalScore += employees[i].ratings[j];
		}
		printf("\n");
	}
}
void displayPerformance(Employee *employees, int numEmployees, int numPeriods){
	printf("\n----------------displaying performance------------\n");
	for(int i=0; i<numEmployees; i++){
		printf("\nDisplaying ratings for employee %d: \n",i+1);
		for(int j=0; j<numPeriods;j++){
			printf("  Rating for period %d : %d\n", j + 1, employees[i].ratings[j]);
		}
		printf("  -----------------------\n");
		printf("  Total score: %d\n\n",employees[i].totalScore);
	}
}
int findEmployeeOfTheYear(Employee *employees, int numEmployees, int numPeriods){
	int empi=0;
	float average,max=0;
	for(int i=0; i<numEmployees; i++){
		average = (float)employees[i].totalScore/numPeriods;
		if(max<average){
			max= average;
			empi=i;
		}
	}
	return empi;
}
int findHighestRatedPeriod(Employee *employees, int numEmployees, int numPeriods){
	int max=0,p_in=0,sum;
	float avg;
	for(int i=0; i<numPeriods; i++){
		sum=0;
		for(int j=0; j<numEmployees; j++){
			sum+=employees[j].ratings[i];
		}
		avg=(float) sum/numEmployees;
		if(avg>max){
			max=avg;
			p_in=i;
		}
	}
	return p_in;
}
int findWorstPerformingEmployee(Employee *employees, int numEmployees, int numPeriods){
	int empi=0;
	float average,min=9999;
	for(int i=0; i<numEmployees; i++){
		average = (float)employees[i].totalScore/numPeriods;
		if(min>average){
			min= average;
			empi=i;
		}
	}
	return empi;
}
int main(){
	int numEmployees, numPeriods;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);
    Employee* employees = (Employee*) calloc(numEmployees,sizeof(Employee));
    
    inputEmployees(employees,numEmployees,numPeriods);
    displayPerformance(employees, numEmployees, numPeriods);
    int best_emp = findEmployeeOfTheYear(employees, numEmployees, numPeriods);
    int worst_emp=findWorstPerformingEmployee(employees, numEmployees, numPeriods);
    int best_per = findHighestRatedPeriod(employees, numEmployees, numPeriods);
    
    printf("\n\n)------------------------------(Displaying Results)-------------------------------------(");
    
    printf("\nEmployee of the Year: Employee %d\n", best_emp + 1);
    printf("Highest Rated Period: Period %d\n", best_per + 1);
    printf("Worst Performing Employee: Employee %d\n", worst_emp + 1);
    
    for(int i=0; i<numEmployees; i++) free(employees[i].ratings);
    free(employees);
    
	return 0;
}
