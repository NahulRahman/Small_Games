#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, numTries = 0, maxTries = 7;

    // Generate a random number between 1 and 100
    srand(time(NULL)); // Seed the random number generator with the current time
    secretNumber = rand() % 100 + 1;

    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    // Allow the user to guess the number within a limited number of tries
    while(numTries < maxTries) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess == secretNumber) {
            printf("Congratulations, you guessed the number in %d tries!\n", numTries+1);
            break;
        } else if(guess < secretNumber) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        numTries++;
    }

    // If the user couldn't guess the number within the limited number of tries
    if(numTries == maxTries) {
        printf("Sorry, you couldn't guess the number in %d tries. The number was %d.\n", maxTries, secretNumber);
    }

    return 0;
}
