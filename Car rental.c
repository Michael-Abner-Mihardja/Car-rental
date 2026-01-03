#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// pendefinisian tipe mobil
struct carType {
    char typeName[20];
    int price;
    int available; // 1 = available, 0 = rented
};

// pendefinisian brand mobil
struct Brand {
    char brandName[30];
    struct carType cars[3];
};

// pendefinisian 3 brand mobil yang tersedia, beserta dengan tipe dan harga sewa per hari
struct Brand brands[3] = {
    {"Toyota", {
        {"Avanza", 300000, 1},
        {"Rush", 400000, 1},
        {"Innova", 350000, 1}
    }},
    {"Suzuki", {
        {"Ertiga", 280000, 1},
        {"Karimun", 180000, 1},
        {"APV", 250000, 1}
    }},
    {"Daihatsu", {
        {"Xenia", 270000, 1},
        {"Terios", 330000, 1},
        {"Zebra", 100000, 1}
    }}
};

//Bikin file
FILE *userList;
FILE *carList;
int isLogin = 0;

// prototype 
void mainmenu();
void reg();
void login();
void adminmenu();
void seecar();
void addcar();
void deletecar();
void loginmenu();
void rentCar();
void returnCar();

//Save user login data
char userNow[20];

// main menu
int main() {
	
	carList = fopen("carList.txt", "r");
	if(carList == NULL){		
		carList = fopen("carList.txt", "w");
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				fprintf(carList, "%s;%s;%d;%d;-\n", brands[i].brandName, brands[i].cars[j].typeName, brands[i].cars[j].price, brands[i].cars[j].available);
			}
		}
		fclose(carList);
	}
	else{
		fclose(carList);
	}
	
    mainmenu();
    return 0;
}

//Function menu
void mainmenu() {
    int choice;

    do {
        system("cls");
        printf("===== CAR RENT =====\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("====================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
				reg();
				break;
			case 2:
				login();
				break;
            case 3:
				exit(0);
            default:
				printf("Invalid choice!\n");
				getchar();
        }

        printf("\nPress Enter...");
        getchar();

    } while (1);
}

//Function buat register user baru ke file
void reg(){
	char userName[50];
    char passWord[50];
	
	system("cls");
	printf("===== REGISTER =====\n");
    printf("Username: ");
    scanf("%s", userName);
    printf("Password: ");
    scanf("%s", passWord);
    
    userList = fopen("userList.txt", "a");
    if(userList == NULL){
		printf("Failed to open file.\n");
		return;
	}
	fprintf(userList, "%s;%s\n", userName, passWord);
	fclose(userList);
}

//Function buat login user, login data dicek dari file
void login() {
    char userName[50];
    char fileuName[50];
    char passWord[50];
    char filepWord[50];
    
    int nemu = 0;

    printf("===== LOGIN =====\n");
    printf("Username: ");
    scanf(" %s", userName);
    printf("Password: ");
    scanf(" %s", passWord);
	
	//Login buat admin nanti masuk menu admin
	if(strcmp(userName, "Admin") == 0 && strcmp(passWord, "12345") == 0){
		adminmenu();
	}
	else{	//login user biasa
		userList = fopen("userList.txt", "r");
	    if(userList == NULL){
	        printf("File not found.\n");
	        return;
	    }
		
		while(fscanf(userList, "%[^;];%s\n", fileuName, filepWord) != EOF){		//Scan satu satu dari file
	        if(strcmp(userName, fileuName) == 0 && strcmp(passWord, filepWord) == 0){
	            strcpy(userNow, fileuName);
				nemu = 1;
	            break;
	        }
	    }
		fclose(userList);
		
	    if(nemu == 1){
	        loginmenu();
	    }
		else{
	        printf("Login failed! User not found.\n");
	    }
	    getchar();
	}
}

//menu admin
void adminmenu(){
	int choice;
    
    do {
		system("cls");	
	    printf("==== ADMIN MENU ====\n");
	    printf("1. See car list\n");
	    printf("2. Add car\n");
	    printf("3. Delete car\n");
	    printf("4. Back\n");
	    printf("====================\n");
        
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
            	seecar();
            	break;
			case 2:
				addcar();
				break;
			case 3:
				deletecar();
				break;
            case 4:
				return;
            default:
				printf("Invalid choice!\n");
				getchar();
        }

        printf("\nPress Enter...");
        getchar();

    } while (1);
}

//Function buat ngasih liat list car di admin
void seecar(){
	system("cls");
	char listbrand[20], whooo[20];
	struct carType list;
	int number = 1;
	
	printf("=========================================== CAR LIST ============================================\n");
	
	carList = fopen("carList.txt", "r");
	if(carList == NULL){
        printf("File not found.\n");
	    return;
	}
	
	while(fscanf(carList, " %[^;];%[^;];%d;%d;%s\n", listbrand, list.typeName, &list.price, &list.available, whooo) != EOF){		//Scan satu satu dari file
		printf("||%2d.| Brand   : %10s ", number, listbrand);
	    printf("| Type    : %10s ", list.typeName);
	    printf("| Price   : %10d ", list.price);
	    if(list.available == 1) printf("| Status  : Available ||\n");
	    else printf("| Status   :   Rented ||\n");
	    number++;
	}
	printf("=================================================================================================\n");
	fclose(carList);
	
	getchar();
}

//Function buat nambah data car
void addcar(){
	struct carType temp;
	char tempN[20];
	
	system("cls");
	printf("============ ADD CAR ============\n");
	printf("Enter car brand : ");
	scanf(" %s", tempN);
	printf("Enter brand type : ");
	scanf(" %s", temp.typeName);
	printf("Enter price per day : ");
	scanf("%d", &temp.price);
	
	carList = fopen("carList.txt", "a");
	if(carList == NULL){
        printf("File not found.\n");
	    return;
	}

	fprintf(carList, "%s;%s;%d;%d;-\n", tempN, temp.typeName, temp.price, 1);

	fclose(carList);
	
	printf("Car added !\n");
	printf("=================================\n");
	
    getchar();
}

//Function buat delete car data
void deletecar(){
	int found = 0;
	char listbrand[20], deletebrand[20], deletetype[20], whoo[20];
	struct carType list;
	
	system("cls");
	
    carList = fopen("carList.txt", "r");
    if(carList == NULL){
        printf("File not found.\n");
	    return;
	}
	
	//Buat print list car yang bisa di delete
	printf("================ AVAILABLE CAR =================\n");
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", listbrand, list.typeName, &list.price, &list.available, whoo) != EOF){		//Scan satu satu dari file
	    if(list.available != 0){
			printf("|| Brand : %12s || Type : %12s||\n", listbrand, list.typeName);
		}
	}
    printf("================================================\n");
    
	printf("Enter car brand to delete : ");
	scanf("%s", deletebrand);
	printf("Enter brand type : ");
    scanf("%s", deletetype);

    //biar baca file dari awal lagi
    rewind(carList);
	
	FILE *temp;
    temp = fopen("temp.txt", "w");
    
    if(temp == NULL){
        printf("File error.\n");
        return;
    }
	
	//Buat search data car mana yang di delete
    while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", listbrand, list.typeName, &list.price, &list.available, whoo) != EOF) {
        if (!(strcmp(deletebrand, listbrand) == 0 && strcmp(deletetype, list.typeName) == 0)) {
            fprintf(temp, "%s;%s;%d;%d\n", listbrand, list.typeName, list.price, list.available);
        }
		else {
            found = 1;
        }
    }

    fclose(carList);
    fclose(temp);
	
	//Message kalau gagal remove carList.txt
    if (remove("carList.txt") != 0) {
        perror("Failed to remove carList.txt");
    }
	//Message kalau gagal rename temp.txt jadi carList.txt
    if (rename("temp.txt", "carList.txt") != 0) {
        perror("Failed to rename temp.txt to carList.txt");
        if (remove("temp.txt") != 0) {
            perror("Failed to remove temp.txt during cleanup");
        }
    }

    if(found){
    	printf("Car data deleted.\n");
    }
	else {
    	printf("Car not found.\n");
    }
    
    getchar();
}

//Menu login user
void loginmenu(){
	int choice;
    
    do {
		system("cls");	
	    printf("==== LOGIN MENU ====\n");
	    printf("1. Rent car\n");
	    printf("2. Return car.\n");
	    printf("3. Back.\n");
	    printf("====================\n");
        
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
            	rentCar();
            	break;
			case 2:
				returnCar();
				break;
			case 3:
				return;
            default:
				printf("Invalid choice!\n");
        }

        printf("\nPress Enter...");
        getchar();

    } while (1);
}

// rent car function
void rentCar() {
    int number, carChoice, duration, sortChoice;
	char tempbrand[20], whooo[20];
	struct carType userLog;
	char yesnt;

	system("cls");
    printf("Login successful !\n\n");
	
	// pilihan untuk sorting
	printf("==== SORTING OPTIONS ====\n");
	printf("1. Sort by Price (Low to High)\n");
	printf("2. Sort by Price (High to Low)\n");
	printf("3. Sort by Brand (A to Z)\n");
	printf("4. Sort by Brand (Z to A)\n");
	printf("5. No sorting (Original order)\n");
	printf("==========================\n");
	printf("Choose sorting option (1-5): ");
	scanf("%d", &sortChoice);
	getchar();
	
	if(sortChoice < 1 || sortChoice > 5) {
		printf("Invalid choice. Using original order.\n");
		sortChoice = 5;
	}
	
	system("cls");
	printf("Login successful !\n\n");
	
	printf("================================ CAR LIST ==================================\n");
	
	carList = fopen("carList.txt", "r");
	if(carList == NULL){
        printf("File not found.\n");
	    return;
	}

	// mendeklarasikan semua barnd, tipe, dan harga moibl sebelum di sort
	char brands[100][20];
	char types[100][20];
	int prices[100];
	int availability[100];
	char rentedBy[100][20];
	int carCount = 0;
	int availableCount = 0;
	
	// membaca carlist berdasarkan user input
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", 
	             brands[carCount], 
	             types[carCount], 
	             &prices[carCount], 
	             &availability[carCount], 
	             rentedBy[carCount]) != EOF) {
	    if(availability[carCount] == 1) {
	        availableCount++;
	    }
	    carCount++;
	}
	
	// index mobil ato apalah
	int availableIndices[100];
	int availIndex = 0;
	for(int i = 0; i < carCount; i++) {
	    if(availability[i] == 1) {
	        availableIndices[availIndex] = i;
	        availIndex++;
	    }
	}
	
	// Buat ngelakuin sortingnya (sortChoice 1-4)
	if(sortChoice >= 1 && sortChoice <= 4) {
	    // Simple bubble sort for the available car indices
	    for(int i = 0; i < availableCount - 1; i++) {
	        for(int j = 0; j < availableCount - i - 1; j++) {
	            int idx1 = availableIndices[j];
	            int idx2 = availableIndices[j+1];
	            int shouldSwap = 0;
	            
	            switch(sortChoice) {
	                case 1: // Price Low to High
	                    shouldSwap = (prices[idx1] > prices[idx2]);
	                    break;
	                case 2: // Price High to Low
	                    shouldSwap = (prices[idx1] < prices[idx2]);
	                    break;
	                case 3: // Brand A to Z
	                    shouldSwap = (strcmp(brands[idx1], brands[idx2]) > 0);
	                    break;
	                case 4: // Brand Z to A
	                    shouldSwap = (strcmp(brands[idx1], brands[idx2]) < 0);
	                    break;
	            }
	            
	            if(shouldSwap) {
	                // Swap indices
	                int temp = availableIndices[j];
	                availableIndices[j] = availableIndices[j+1];
	                availableIndices[j+1] = temp;
	            }
	        }
	    }
	}
	
	// nampilin semua mobil yang udh disort
	number = 1;
	for(int i = 0; i < availableCount; i++) {
	    int idx = availableIndices[i];
	    printf("||%2d.| Brand   : %10s ", number, brands[idx]);
	    printf("| Type    : %10s ", types[idx]);
	    printf("| Price   : %10d ||\n", prices[idx]);
	    number++;
	}
	
	printf("============================================================================\n");
	
	// info sorting atau apalah
	switch(sortChoice) {
		case 1: printf("Sorted by: Price (Low to High)\n"); break;
		case 2: printf("Sorted by: Price (High to Low)\n"); break;
		case 3: printf("Sorted by: Brand (A to Z)\n"); break;
		case 4: printf("Sorted by: Brand (Z to A)\n"); break;
		case 5: printf("No sorting applied\n"); break;
	}
	printf("\n");
	
	printf("Input which car to rent (1 - %d) : ", availableCount);
	if (scanf("%d", &carChoice) != 1) {
		while (getchar() != '\n');
		printf("Invalid input.\n");
		fclose(carList);
		return;
	}
	
    if (carChoice < 1 || carChoice > availableCount) {
    	fclose(carList);
        printf("Invalid car choice!\n");
        getchar();
        return;
    }

    printf("Duration (days): ");
    scanf("%d", &duration);
    getchar();
	
	// ngambil index moibl berdasarkan yang udh di sort
	int chosenIndex = availableIndices[carChoice-1];
	
	// nyari posisi awal dari mobil di file
	rewind(carList);
	int originalPosition = 0;
	int filePosition = 0;
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
	    // Check if this is the chosen car (by comparing brand, type, and price)
	    if(strcmp(tempbrand, brands[chosenIndex]) == 0 && 
	       strcmp(userLog.typeName, types[chosenIndex]) == 0 &&
	       userLog.price == prices[chosenIndex]) {
	        originalPosition = filePosition;
	        break;
	    }
	    filePosition++;
	}
	
	// buka ulang file ato rewind buat nyari
	rewind(carList);
	int count = 0;
	int foundInFile = 0;
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
	    if(count == originalPosition) {
	        printf("Are you sure you want to rent %s %s for %d (Y/N)? ", tempbrand, userLog.typeName, userLog.price*duration);
	        scanf(" %c", &yesnt);
	        foundInFile = 1;
	        break;
	    }
	    count++;
	}
	
	if(!foundInFile || tolower(yesnt) == 'n'){
		fclose(carList);
		if(!foundInFile) printf("Error: Car not found in file.\n");
		else printf("Rent cancelled.\n");
		getchar();
		return;
	}
	
	rewind(carList);
	
	//Buat assign pengguna ke file
	FILE *assign;
	assign = fopen("assign.txt", "w");
	if(assign == NULL){
        printf("File not found.\n");
	    fclose(carList);
	    return;
	}
	
	//Buat search and replace data car mana yang di assign
    count = 0;
    rewind(carList);
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
        if (count == originalPosition) {
            fprintf(assign, "%s;%s;%d;0;%s\n", tempbrand, userLog.typeName, userLog.price, userNow);
        }
		else {
            fprintf(assign, "%s;%s;%d;%d;%s\n", tempbrand, userLog.typeName, userLog.price, userLog.available, whooo);
        }
        count++;
    }

    fclose(carList);
    fclose(assign);
	
	//Message kalau gagal remove carList.txt
    if (remove("carList.txt") != 0) {
        perror("Failed to remove carList.txt");
    }
	//Message kalau gagal rename assign.txt jadi carList.txt
    if (rename("assign.txt", "carList.txt") != 0) {
        perror("Failed to rename temp.txt to carList.txt");
        if (remove("assign.txt") != 0) {
            perror("Failed to remove assign.txt during cleanup");
        }
    }
	
	printf("Car rented !\n");
	getchar();
}

// return car function

void returnCar() {
    int ada, number, count, carChoice;
    char tempbrand[20], whooo[20];
    struct carType userLog;
    char targetbrand[20], targettype[20];
	
	carList = fopen("carList.txt", "r");
    if(carList == NULL){
        printf("File not found.\n");
	    return;
	}
	
	printf("================== CAR RENTED =================\n", userNow);
	
	//Buat ngasih liat car apa yang user skrng rent
	number = 1, ada = 0;
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
        if(strcmp(userNow, whooo) == 0) {
            printf("||%2d| Brand : %10s | Type : %10s ||\n", number, tempbrand, userLog.typeName);
            ada = 1;
        	number++;
        }
    }
    printf("===============================================\n");
	if(ada == 0){
		fclose(carList);
		printf("No car rented.\n");
		getchar();
		return;
	}
	//Biar bisa baca dari awal lagi
	rewind(carList);
	
	printf("Which car do you want to return (1 - %d) : ", number-1);
	if (scanf("%d", &carChoice) != 1) {
		while (getchar() != '\n');
		printf("Invalid input.\n");
		fclose(carList);
		return;
	}
	
	if (carChoice < 1 || carChoice > number-1) {
		printf("Invalid choice!\n");
		fclose(carList);
        getchar();
        return;
    }
    
    //Buat nge-set target yang dihapus
    number = 0;
    while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
    	if(strcmp(userNow, whooo) == 0){
			number++;
		}
        if(carChoice == number) {
            strcpy(targetbrand, tempbrand);
            strcpy(targettype, userLog.typeName);
        	break;
        }
    }
	rewind(carList);
	
	FILE *hapus;
	hapus = fopen("hapus.txt", "w");
	if(hapus == NULL){
        printf("File not found.\n");
	    return;
	}
	
	//Buat update file carList
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
		if (strcmp(targetbrand, tempbrand) == 0 && strcmp(targettype, userLog.typeName) == 0) {
            fprintf(hapus, "%s;%s;%d;1;-\n", tempbrand, userLog.typeName, userLog.price);
        }
		else {
            fprintf(hapus, "%s;%s;%d;%d;%s\n", tempbrand, userLog.typeName, userLog.price, userLog.available, whooo);
        }
	}
	
	//Close file
	fclose(carList);
    fclose(hapus);
	
	//Message kalau gagal remove carList.txt
    if (remove("carList.txt") != 0) {
        perror("Failed to remove carList.txt");
    }
	//Message kalau gagal rename hapus.txt jadi carList.txt
    if (rename("hapus.txt", "carList.txt") != 0) {
        perror("Failed to rename hapus.txt to carList.txt");
        if (remove("hapus.txt") != 0) {
            perror("Failed to remove hapus.txt during cleanup");
        }
    }
	
	printf("Car has been returned successfully!\n");
	getchar();
}
