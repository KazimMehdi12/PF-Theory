#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Weather{
	float temp,rain,patterns;
}Weather;

typedef struct crop{
	char crop_type[20];
    char growth_stage[20];
    float expected_yield;
    Weather *weather;
}Crop;

typedef struct Equipment{
	char type[20];
    int operational_status; 
    float fuel_level;
    char activity_schedule[50];
}Equipment;

typedef struct Sensor{
	float soil_nutrients, pH_level;
	int pest_activity;
}Sensor;

typedef struct field{
	float GPS_C[2];
	float soilHealth;
    float moistureLevel;
    Equipment *equipment;
    Crop *crops;
    Sensor *sensors;  
    int n_crops, n_equipemts, n_sensors;
}Field;

typedef struct rhub{
	Field *fields;
	int n_fields;
}Regional_Hub;

int main(){
	Regional_Hub hub;
	hub.n_fields=1; //for now everything is 1 because nothing is specified in the question
	//number of everything can be increased and put every initialization into a loop
	//but for now as there is no specifications in the program, i have set everything to 1;
	hub.fields = (Field*)calloc(hub.n_fields,sizeof(Field));
	
	hub.fields[0].n_crops=1;
	hub.fields[0].n_equipemts=1;
	hub.fields[0].n_sensors=1;
	//memory allocation
	hub.fields[0].crops = (Crop *)malloc(hub.fields[0].n_crops * sizeof(Crop));
    hub.fields[0].equipment = (Equipment *)malloc(hub.fields[0].n_equipemts * sizeof(Equipment));
    hub.fields[0].sensors = (Sensor *)malloc(hub.fields[0].n_sensors * sizeof(Sensor));
    
    hub.fields[0].GPS_C[0] = 30.5; // Latitude
    hub.fields[0].GPS_C[1] = 140.2; // Longitude
    hub.fields[0].soilHealth = 45;          
    hub.fields[0].moistureLevel = 56;
	
	strcpy(hub.fields[0].crops[0].crop_type, "Rice");
    strcpy(hub.fields[0].crops[0].growth_stage, "Mature");
    hub.fields[0].crops[0].expected_yield = 350;
    hub.fields[0].crops[0].weather= (Weather*) malloc(sizeof(Weather)); //memory
    hub.fields[0].crops[0].weather->temp=21.6; //like fields[0] we can use fields-> because only 1 member
    hub.fields[0].crops[0].weather->rain=0.56;
    hub.fields[0].crops[0].weather->patterns=4;
    
    strcpy(hub.fields[0].equipment[0].type, "Tractor");
    hub.fields[0].equipment[0].operational_status = 1; // Active
    hub.fields[0].equipment[0].fuel_level = 65.0 ;
    strcpy(hub.fields[0].equipment[0].activity_schedule, "Daily 4am-8am");
    
    hub.fields[0].sensors[0].soil_nutrients = 85;
    hub.fields[0].sensors[0].pH_level = 6.51;
    hub.fields[0].sensors[0].pest_activity = 1;
    
    //all initialized using DMA and now free all
    free(hub.fields[0].crops[0].weather);
    free(hub.fields[0].crops);
    free(hub.fields[0].equipment);
    free(hub.fields[0].sensors);
    free(hub.fields);
	return 0;
}
