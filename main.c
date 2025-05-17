#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

void generatePassword(char *password, int length) {
    char allCharacters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:',.<>?/";
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        password[i] = allCharacters[rand() % strlen(allCharacters)];
    }
    password[length] = '\0';
}

int checkStrength(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);

    if (length < MIN_LENGTH)
        return 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSpecial = 1;
    }

    return hasUpper + hasLower + hasDigit + hasSpecial;
}

void displayStrength(int score) {
    switch (score) {
        case 4:
            printf("Strength: Very Strong\n");
            break;
        case 3:
            printf("Strength: Strong\n");
            break;
        case 2:
            printf("Strength: Medium\n");
            break;
        case 1:
            printf("Strength: Weak\n");
            break;
        default:
            printf("Strength: Very Weak\n");
    }
}

int main() {
    int choice, length, strengthScore;
    char password[100];

    printf("1. Generate Random Password\n");
    printf("2. Enter Custom Password\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter desired length (8-16): ");
        scanf("%d", &length);

        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length. Must be between 8 and 16.\n");
            return 1;
        }

        generatePassword(password, length);
        printf("Generated Password: %s\n", password);
    } else if (choice == 2) {
        do {
            printf("Enter your password (8-16 characters): ");
            scanf("%s", password);
        } while (strlen(password) < MIN_LENGTH || strlen(password) > MAX_LENGTH);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    strengthScore = checkStrength(password);
    displayStrength(strengthScore);

    return 0;
}
