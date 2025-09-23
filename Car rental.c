#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	
	FILE *fptr;
	fptr = fopen("Car_rental.txt", "a");
	
	switch (option) { //
		case 1: //list car
			listCar();
			break;
		case 2: //rent car
			break;
		case 3: //return car
			break;
		case 4: //quit program
			
			break;
	}
	// Declare  file pointer
    FILE *file;

    // Open file in writing mode ("w")
    file = fopen("daftar_mobil.txt", "w");

    // Write cars
    fprintf(file, "mobil 1.\n");
    fprintf(file, "available.\n");
    fprintf(file, "mobil 2.\n");
    fprintf(file, "available.\n");
    
    //display all available options and ask for which car
     
    printf("which car would you like to rent?");
    scanf()

	return(0);
}




