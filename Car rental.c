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
	
	return(0);
}



