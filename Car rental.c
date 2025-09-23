#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	//declare file pointer
	FILE *fptr;
	fptr = fopen("Car_rental.txt", "w"); //open file in writing mode ("w")
	fprintf//list car

	int option;
	
		
	do {
		listAction()
		switch (option) { //
		case 1: //list car
			
			break;
		case 2: //rent car
			
			break;
		case 3: //return car
			
			break;
		case 4: //quit program
			printf("Exiting\n")
			break;
		}
	}
		while (option != 4);
	return(0);
}

void listCar() {
	fptr = fopen("Car_rental.txt", "r");//read file
	char listCar[1000];
	fgets(listCar, 1000, fptr);
	printf("%s", listCar);
}



// // Declare  file pointer
//     FILE *file;

//     // Open file in writing mode ("w")
//     file = fopen("daftar_mobil.txt", "w");

//     // Write cars
//     fprintf(file, "mobil 1.\n");
//     fprintf(file, "available.\n");
//     fprintf(file, "mobil 2.\n");
//     fprintf(file, "available.\n");
    
//     //display all available options and ask for which car
     
//     printf("which car would you like to rent?");
//     scanf()
