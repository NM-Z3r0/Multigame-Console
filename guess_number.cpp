#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void playGuess() {
    system("cls");
    char repeat;

    do {
        int number;
        int guess;
        int attempts = 0;

        srand(time(NULL));
        number = rand() % 100 + 1;

        cout << "\n==============================\n";
        cout << "||     GUESS THE NUMBER     ||\n";
        cout << "==============================\n";
        cout << "I'm thinking of a number between 1 and 100...\n";

        do {
            cout << "\nEnter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > number) {
                cout << "Lower...\n";
            } else if (guess < number) {
                cout << "Higher...\n";
            } else {
                cout << "\nCorrect! You guessed it in " << attempts << " attempts.\n";
            }

        } while (number != guess);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nReturning to the main menu...\n";
}
