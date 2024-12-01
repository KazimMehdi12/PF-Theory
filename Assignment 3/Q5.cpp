#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2. add
void AddSupplies(char** speciesSupplies,int specie_index,int *num_supplies){
	
	printf("Enter number of supplies for specie %d: ",specie_index);
	scanf("%d",&num_supplies[specie_index]);

	speciesSupplies[specie_index] = (char*)calloc(num_supplies[specie_index],100 * sizeof(char)); //contigous block of memory
	fflush(stdin);
	for(int i=0; i<num_supplies[specie_index]; i++){
		printf("Supply %d: ",i);
		gets(&speciesSupplies[specie_index][i*100]);
	}
}
void UpdateSupplies(char** speciesSupplies,int specie_index,int supply_index){
	if(speciesSupplies[specie_index]==NULL) {
		printf("No supply added for specie %d\nTry adding supplies!\n",specie_index);
		return;
	}
	char* New = (char*)malloc(100*sizeof(char));
	printf("Enter New Supply: ");
	fflush(stdin);
	gets(New);
	strcpy(&speciesSupplies[specie_index][100*supply_index],New);
	return;
}
void RemoveSpecies(char** speciesSupplies, int specie_index, int * numSpecies){
	speciesSupplies[specie_index]=NULL;
	if(specie_index==((*numSpecies)-1)){
		speciesSupplies[specie_index]=NULL;
		free(speciesSupplies[specie_index]);
	}else{
		for(int i=specie_index; i<*numSpecies; i++){
			speciesSupplies[specie_index]=speciesSupplies[specie_index+1];
		}
		speciesSupplies[*numSpecies]=NULL;
		free(speciesSupplies[*numSpecies]);
		(*numSpecies)--;
	}
	printf("Specie at index %d removed Sucessfuly!\n",specie_index);
}
void displayInventory(char** speciesSupplies, int numSpecies, int* numSupplies) {
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        if (speciesSupplies[i] == NULL || numSupplies[i] == 0) {
            printf("  No supplies added.\n");
        } else {
            for (int j = 0; j < numSupplies[i]; j++) {
                printf("  Supply %d: %s\n", j + 1, &speciesSupplies[i][j * 100]);
            }
        }
    }
}

int main(){
	printf(")--------------------------------------------( Welcome to Pets in Heart )------------------------------------------(\n");
	int num_species,*num_supplies;
	printf("\nEnter number of species: ");
	scanf("%d",&num_species);
	char** speciesSupplies = (char**)calloc(num_species,sizeof(char*));
	//1. Initialize
	for(int i=0; i<num_species; i++) speciesSupplies[i] = NULL;
		num_supplies= (int*)malloc(100*sizeof(int));
	int choice;
while(1){
	printf("\n");
	printf("\nMenu:\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supplies\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    switch(choice){
    	case 1:
    		int specieee_index;
    		printf("\nEnter index of Specie where you want to add: ");
    		scanf("%d",&specieee_index);
    		if(specieee_index<0||specieee_index>=num_species) {
			printf("Invalid index entered!");
			break;
			}
			AddSupplies(speciesSupplies, specieee_index, num_supplies);
			break;
		case 2:
			int speciee_index, supply_index;
			printf("Enter specie index and supply index: ");
			scanf("%d %d",&speciee_index,&supply_index);
			UpdateSupplies(speciesSupplies,speciee_index,supply_index);
			break;
		case 3:
			int specie_index;
			printf("Enter specie index : ");
			scanf("%d %d",&specie_index);
			if(specie_index>=0 && specie_index<num_species)
				RemoveSpecies(speciesSupplies, specie_index, &num_species);
			else printf("Invalid index entered!\n");
			break;
		case 4:
			displayInventory(speciesSupplies, num_species, num_supplies);
			break;
		case 5:
			printf("Exiting...");
			return 0;
		default:
			printf("Invalid choice!\n");
	}
}
}
