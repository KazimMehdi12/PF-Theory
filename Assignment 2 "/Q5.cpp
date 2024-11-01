#include<stdio.h>
void horizontal_histogram(int a[], int len);
void vertical_histogram(int a[], int len);
int main(){
	int size;
	printf("How many values? :");
	scanf("%d",&size);
	int arr[size];
	printf("Enter values of array : ");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	horizontal_histogram(arr,size);
	vertical_histogram(arr,size);
	
}
void horizontal_histogram(int a[], int len){
	printf("\nHorizontal Histogram\n");
	for(int i=0;i<len;i++){
		printf("Value %d:",i+1);
		for(int j=0;j<a[i];j++){
			printf("*");
		}
		printf("\n");
	}
}
void vertical_histogram(int a[], int len){
	printf("\nVertical Histogram\n");
	int rows=a[0];
	for(int i=0;i<len;i++){
		if(rows<a[i]) rows=a[i];
	}
	for(int i=rows;i>=0;i--){
		if(i==0){
			for(int k=0;k<len;k++){
			printf("%d\t",a[k]);
			}
		} else{
			for(int j=0;j<len;j++){
				if(a[j]>=i) printf("*\t");
				else printf(" \t");
			}
			printf("\n");
		}
	}
}