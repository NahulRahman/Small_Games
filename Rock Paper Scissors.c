#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, comp_choice;
    int result;

    // Generate a random choice for the computer
    srand(time(NULL));
    comp_choice = rand() % 3 + 1;

    // Get user's choice
    printf("Enter 1 for Rock, 2 for Paper, or 3 for Scissors: ");
    scanf("%d", &user_choice);

    // Determine the winner
    if (user_choice == comp_choice) {
        result = 0; // Tie
    } else if (user_choice == 1 && comp_choice == 3 ||
               user_choice == 2 && comp_choice == 1 ||
               user_choice == 3 && comp_choice == 2) {
        result = 1; // User wins
    } else {
        result = -1; // Computer wins
    }

    // Display the result
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win!\n");
    } else {
        printf("The computer wins!\n");
    }

    return 0;
}
