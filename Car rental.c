#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct carType {
    char typeName[20];
    int price;
    int available; // 1 = available, 0 = rented
};

struct Brand {
    char brandName[30];
    struct carType cars[3];
};

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

void login() {
    char userName[50];
    char fileuName[50];
    char passWord[50];
    char filepWord[50];
    
    int nemu;

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
        }

        printf("\nPress Enter...");
        getchar();

    } while (1);
}

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
	    else printf("| Status   :    Rented ||\n");
	    number++;
	}
	printf("=================================================================================================\n");
	
	getchar();
}

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
    int number, carChoice, duration;
	char tempbrand[20], whooo[20];
	struct carType userLog;
	char yesnt;
	
	system("cls");
    printf("Login successful !\n\n");
	
	printf("================================ CAR LIST ==================================\n");
	
	carList = fopen("carList.txt", "r");
	if(carList == NULL){
        printf("File not found.\n");
	    return;
	}
	
	number = 1;
	while(fscanf(carList, " %[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF){		//Scan satu satu dari file
		if(userLog.available == 1){
			printf("||%2d.| Brand   : %10s ", number, tempbrand);
		    printf("| Type    : %10s ", userLog.typeName);
		    printf("| Price   : %10d ||\n", userLog.price);
		}
	    number++;
	}
	printf("============================================================================\n");
	
	printf("Input which car to rent (1 - %d) : ", number);
	scanf("%d", &carChoice);
	
    if (carChoice < 1 || carChoice > number) {
        printf("Invalid car choice!\n");
        return;
    }

    printf("Duration (days): ");
    scanf("%d", &duration);
    getchar();
	
	//Buat baca file dari awal lagi
	rewind(carList);
	int count = 1;
	while(fscanf(carList, " %[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF){		//Scan satu satu dari file
		if(count ==  carChoice){
			printf("Are you sure you want to rent %s %s for %d (Y/N)? ", userLog.price*duration);
			scanf("%c", &yesnt);
			if(toupper(yesnt) != 'Y' || toupper(yesnt != 'N')){
				return;
			}
			break;
		}
		else{
			count++;
		}
	}
	rewind(carList);
	
	
	//Buat assign pengguna ke file
	FILE *assign;
	assign = fopen("assign.txt", "w");
	if(assign == NULL){
        printf("File not found.\n");
	    return;
	}
	
	//Buat search and replace data car mana yang di assign
    count = 1;
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
        if (count == carChoice) {
            fprintf(assign, "%s;%s;%d;%d;$s\n", tempbrand, userLog.typeName, userLog.price, userLog.available, userNow);
        }
		else {
            fprintf(assign, "%s;%s;%d;%d;$s\n", tempbrand, userLog.typeName, userLog.price, userLog.available, whooo);
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
    int number, count, carChoice;
    char tempbrand[20], whooo[20];
    struct carType userLog;
	
	carList = fopen("carList.txt", "r");
    if(carList == NULL){
        printf("File not found.\n");
	    return;
	}
	
	printf("================ CAR $s RENTED ================\n", userNow);
	
	number = 1;
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
        if(strcmp(userNow, whooo) == 0) {
            printf("||%2d| Brand : %10s | Type : %10s ||\n", number, tempbrand, userLog.typeName);
        }
        number++;
    }
    printf("===============================================\n");
	rewind(carList);
	
	printf("Which car do you want to return (1 - %d) : ", number);
	scanf("%d", carChoice);
	
	if (carChoice < 1 || carChoice > number) {
        printf("Invalid choice!\n");
        return;
    }
	
	FILE *hapus;
	hapus = fopen("hapus.txt", "w");
	if(hapus == NULL){
        printf("File not found.\n");
	    return;
	}
	
	while(fscanf(carList, "%[^;];%[^;];%d;%d;%s\n", tempbrand, userLog.typeName, &userLog.price, &userLog.available, whooo) != EOF) {
		if (strcmp(whooo, userNow) == 0) {
            fprintf(hapus, "%s;%s;%d;%d;-\n", tempbrand, userLog.typeName, userLog.price, userLog.available);
        }
		else {
            fprintf(hapus, "%s;%s;%d;%d;$s\n", tempbrand, userLog.typeName, userLog.price, userLog.available, whooo);
        }
	}
	
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
