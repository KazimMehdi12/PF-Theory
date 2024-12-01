#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct c{
    char title[50];
    float rating;
    int runtime; // in minutes
    char encodingFormat[20];
} ContentMetadata;

typedef struct dp{
    int resolution;       
    int playback_History;  
    double bandwidth;     
} DevicePreferences;

int main(){
	int n_users=2, n_category=3,n_devices=3,n_content=3;
	
	//memory allocation
	double** engagementMatrix;
	engagementMatrix = (double**) calloc(n_users, sizeof(double*));
	for(int i=0; i<n_users; i++) engagementMatrix[i]= (double*) calloc(n_category, sizeof(double));
	
	DevicePreferences **Device_Matrix;
	Device_Matrix = (DevicePreferences**) calloc(n_users, sizeof(DevicePreferences*));
	for(int i=0; i<n_users; i++) Device_Matrix[i] = (DevicePreferences*) calloc(n_devices, sizeof(DevicePreferences));
	
	ContentMetadata **Content;
	Content = (ContentMetadata**) calloc(n_category, sizeof(ContentMetadata*));
	for(int i=0; i<n_category; i++) Content[i] = (ContentMetadata*) calloc(n_content, sizeof(ContentMetadata));
	
	//assigning example values
	for (int i = 0; i < n_users; i++) {
		for (int j = 0; j < n_devices; j++) {
            Device_Matrix[i][j].resolution = 1080+i*j;        // example resolution
            Device_Matrix[i][j].playback_History = i+j;      // example playback history
            Device_Matrix[i][j].bandwidth = (i>j ? i-j : j-i);          // example bandwidth
        }
    }
    
    for (int i = 0; i < n_category; i++) {
        for (int j = 0; j < n_content; j++) {
            strcpy(Content[i][j].title, "Example Title"); 
            Content[i][j].rating = 4.0+i-j;                   // Example rating
            Content[i][j].runtime = 120+i*j;                  // Example runtime
            strcpy(Content[i][j].encodingFormat, "H.264"); // Fixed format
        }
    }
    
    for (int i = 0; i < n_users; i++) {
        for (int j = 0; j < n_category; j++) {
            engagementMatrix[i][j] = i+j-i*j;
        }
    }
    
    printf("Engagement Matrix [User 1][Category 2]: %.2f\n", engagementMatrix[1][2]);
    printf("Device Matrix [User 0][Device 1]: Resolution = %d, Bandwidth = %.2f\n", Device_Matrix[0][1].resolution, Device_Matrix[0][1].bandwidth);
    printf("Content Matrix [Category 1][Content 2]: Title = %s, Rating = %.1f\n", Content[1][2].title, Content[1][2].rating);
           
    //free memory
    for (int i = 0; i < n_users; i++) free(engagementMatrix[i]);
    free(engagementMatrix);
    
    for(int i=0; i<n_users; i++) free(Device_Matrix[i]);
	free(Device_Matrix);
	
	for(int i=0; i<n_category; i++) free(Content[i]);
	free(Content);
		
	return 0;
}
