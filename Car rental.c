#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct carType {
	char typeName[20];
    int price;
    int available;
};

struct Brand {
char brandName[30];
struct carType cars[3];
};

struct Brand brands[3] = {
    {
        "Toyota",
        {
            {"Avanza", 300000, 1},
            {"Rush", 400000, 1},
            {"Innova", 350000, 1}
        }
    },
    {
        "Suzuki",
        {
            {"Ertiga", 280000, 1},
            {"Karimun", 180000, 1},
            {"APV", 250000, 1}
        }
    },
    {
        "Daihatsu",
        {
            {"Xenia", 270000, 1},
            {"Terios", 330000, 1},
            {"Zebra", 100000, 1}
        }
    }
};
int isLogin = 0;

// prototype
void mainmenu();
void login();
void rentcar();
void returncar();
void clearscreen();

// bagian main menu
int main (){
	mainmenu ();
return 0;
}

// clearscreen
void clearscreen(){
	system ("cls");
}

void mainmenu (){
	int choice;
do {
clearscreen();

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

switch(choice) {
	case 1:
		login();
		break;
//	case 2:
//		rent car();
//		break;
//	case 3:
//		return car();
//		break;
	case 4:
		exit(0);
	default: 
		printf("Tidak ada di pilihan.\n");
}

printf("\nPress Enter");
getchar(); 
getchar();

} while(1);
}

// rent car system
void rentCar() {
	int brandChoice, carChoice, Duration;
	if(!isLogin) {
		printf("Please login first.\n");
		return;
	} 
clearScreen();
printf("===== Brand Selection =====\n");
for (int i = 0 ; i < 3 ; i++){
	printf("%d. %s\n", i + 1, brands[i].brandName);
}

printf("Choose The Car Brand: ");
scanf("%s", &brandChoice);

if(brandChoice < 1 || brandChoice > 3) {
	printf("Sorry, that brand is not on the list.\n");
return;
}

clearscreen();
printf("===== Select The Car Type (%s) =====\n), brands[brandChoice - 1].brandName);

	for (int i = 0 ; i < 3 ; i++) {
		printf("%d. %s - Rp.%d - %s\n", i + 1, 
			   brands[brandChoice - 1].cars[i].typeName,
               brands[brandChoice - 1].cars[i].price,
               brands[brandChoice - 1].cars[i].available ? "Available" : "Rented");
    }
printf("Choose the Car Type You Want To Rent: ");
scanf("%d", &carChoice);

if (carChoice < 1 || > 3) {
printf("The car type is not on the list\n");
}

 if (brands[brandChoice - 1].cars[carChoice - 1].available == 0) {
        printf("Car already rented!\n");
        return;
    }
printf("How long do you want to rent this car?: ");
scanf("%d", &duration);

 brands[brandChoice - 1].cars[carChoice - 1].available = 0;

    printf("\nCar rented successfully!\n");
    printf("Brand : %s\n", brands[brandChoice - 1].brandName);
    printf("Type  : %s\n", brands[brandChoice - 1].cars[carChoice - 1].typeName);
    printf("Total : Rp%d\n",
           brands[brandChoice - 1].cars[carChoice - 1].price * duration);
}
	

// Return car
void returnCar() {
    int brandChoice, carChoice;

    if (!isLogin) {
        printf("Please login first!\n");
        return;
    }

    clearScreen();
    printf("===== RETURN CAR =====\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, brands[i].brandName);
    }

    printf("Choose brand: ");
    scanf("%d", &brandChoice);

    if (brandChoice < 1 || brandChoice > 3) {
        printf("Invalid brand!\n");
        return;
    }

clearScreen();
    printf("===== CAR LIST (%s) =====\n",
           brands[brandChoice - 1].brandName);

    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %s\n",
               i + 1,
               brands[brandChoice - 1].cars[i].typeName,
               brands[brandChoice - 1].cars[i].available ? "Available" : "Rented");
    }

    printf("What car do you want to return: ");
    scanf("%d", &carChoice);

    if (carChoice < 1 || carChoice > 3) {
        printf("Invalid choice!\n");
        return;
    }

    if (brands[brandChoice - 1].cars[carChoice - 1].available == 1) {
        printf("This car is not rented!\n");
        return;
    }

    brands[brandChoice - 1].cars[carChoice - 1].available = 1;
    printf("The car has been returned.\n");
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
	if (strcmp(userName, "admin") == 0 && strcmp (passWord, "123") == 0) {
	isLogin = 1;
	printf("welcome %s", userName);
	}
	else {
	printf("authorization failed, please try again later");
	}
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









