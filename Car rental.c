#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isLogin = 0;

// prototype 
void mainmenu();
void login();
void rentCar();
void returnCar();
void clearscreen();

// main menu
int main() {
    mainmenu();
    return 0;
}

void clearscreen() {
    system("cls"); 
}

void mainmenu() {
    int choice;

    do {
        clearscreen();
        printf("===== CAR RENT =====\n");
        printf("1. Login\n");
        printf("2. Rent a Car\n");
        printf("3. Return a Car\n");
        printf("4. Exit\n");
        printf("====================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: login(); break;
            case 2: rentCar(); break;
            case 3: returnCar(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }

        printf("\nPress Enter...");
        getchar(); getchar();

    } while (1);
}

void login() {
    char userName[50];
    char passWord[50];

    printf("===== LOGIN =====\n");
    printf("Username: ");
    scanf("%s", userName);
    printf("Password: ");
    scanf("%s", passWord);

    if (strcmp(userName, "admin") == 0 &&
        strcmp(passWord, "123") == 0) {
        isLogin = 1;
        printf("Login success! Welcome %s\n", userName);
    } else {
        printf("Login failed! please try again.\n");
    }
}


// rent car function

void rentCar() {
    int brandChoice, carChoice, duration;

    if (!isLogin) {
        printf("Please login first!\n");
        return;
    }

    printf("===== BRAND =====\n");
    for (int i = 0; i < 3; i++)
        printf("%d. %s\n", i + 1, brands[i].brandName);

    printf("Choose brand: ");
    scanf("%d", &brandChoice);

    if (brandChoice < 1 || brandChoice > 3) {
        printf("Invalid brand!\n");
        return;
    }

    printf("===== CAR TYPE (%s) =====\n",
           brands[brandChoice - 1].brandName);

    for (int i = 0; i < 3; i++) {
        printf("%d. %s - Rp%d - %s\n",
               i + 1,
               brands[brandChoice - 1].cars[i].typeName,
               brands[brandChoice - 1].cars[i].price,
               brands[brandChoice - 1].cars[i].available ? "Available" : "Rented");
    }

    printf("Choose car: ");
    scanf("%d", &carChoice);

    if (carChoice < 1 || carChoice > 3) {
        printf("Invalid car choice!\n");
        return;
    }

    if (!brands[brandChoice - 1].cars[carChoice - 1].available) {
        printf("Car already rented!\n");
        return;
    }

    printf("Duration (days): ");
    scanf("%d", &duration);

    brands[brandChoice - 1].cars[carChoice - 1].available = 0;

    printf("\nCar rented successfully!\n");
    printf("Brand : %s\n", brands[brandChoice - 1].brandName);
    printf("Type  : %s\n", brands[brandChoice - 1].cars[carChoice - 1].typeName);
    printf("Total : Rp%d\n",
           brands[brandChoice - 1].cars[carChoice - 1].price * duration);
}

// return car function

void returnCar() {
    int brandChoice, carChoice;

    if (!isLogin) {
        printf("Please login first!\n");
        return;
    }

    printf("===== RETURN CAR =====\n");
    for (int i = 0; i < 3; i++)
        printf("%d. %s\n", i + 1, brands[i].brandName);

    printf("Choose brand: ");
    scanf("%d", &brandChoice);

    if (brandChoice < 1 || brandChoice > 3) {
        printf("Invalid brand!\n");
        return;
    }

    printf("===== CAR LIST (%s) =====\n",
           brands[brandChoice - 1].brandName);

    for (int i = 0; i < 3; i++) {
        printf("%d. %s - %s\n",
               i + 1,
               brands[brandChoice - 1].cars[i].typeName,
               brands[brandChoice - 1].cars[i].available ? "Available" : "Rented");
    }

    printf("Choose car to return: ");
    scanf("%d", &carChoice);

    if (carChoice < 1 || carChoice > 3) {
        printf("Invalid choice!\n");
        return;
    }

    if (brands[brandChoice - 1].cars[carChoice - 1].available) {
        printf("This car is not rented!\n");
        return;
    }

    brands[brandChoice - 1].cars[carChoice - 1].available = 1;
    printf("Car has been returned successfully!\n");
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










