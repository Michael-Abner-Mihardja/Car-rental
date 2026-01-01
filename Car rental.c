#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct Car {
//     char name[20];
//     int price;
//     int available; // 1 = tersedia, 0 = disewa
// };

struct carType {
	char typeName[20];
    int price;
    int available;
};

struct brand {
char brandName[30];
struct CarType cars [3];
};

struct Brand brands[3] = {
{"Toyota",
	{"Avanza", 300.000, 1 hari},
	{"Rush", 400.000, 1 hari},
	{"Kijang innova", 350.000, 1 hari}
	}
}, 
{"Suzuki",
	{"Ertiga", 280.000, 1 hari},
	{"Karimun", 180.000, 1 hari},
	{"APV", 250.000, 1 hari}
	}
},
{"Daihatsu",
	{"Xenia", 270.000, 1 hari},
    {"Terios", 330.000, 1 hari},
	{"Zebra", 100.000, 1 hari}
}
}
};
int isLogin = 0;

// rent car system
		



// prototype
void mainmenu();
void login();
void rentcar();
void returncar();
void clearscreen();

// bagian main menu
int main (){
	main menu ();
return 0;
}

void mainmenu (){
	int choice;
do {
clearScreen();

printf("===== CAR RENT =====\n");
printf("1. login\n");
printf("2. rent a car\n");
printf("3. return a car\n");
printf("4. exit\n");
printf("====================\n");
printf("enter your choice: ");

// ini potongan kode biar klo ada input salah gaakan ganggu program
if (scanf("%d", &choice) != 1) {
while (getchar() != '\n');
choice = 0;
}  

// fungsi clearscreen
void clearscreen(){
	system ("cls");
}

void login() {
	char userName [50];
	char passWord [50];

	printf("===== LOGIN =====\n");
	printf("enter your username: ");
	scanf("%s\n", &userName);
	printf("enter the password: ");
	scanf("%s\n", &passWord);

	// ini username ama passwordnya masih di set admin dan 123
	if (strcmp(userName, "admin") == 0 && strcmp (passWord, ("123") == 0) {
	isLogin = 1;
	printf("welcome %s", userName);
	}
	else {
	printf("authorization failed, please try again later");
	}





void file() {        // ini gw ganti namanya dari "int main" jadi "void file"
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






