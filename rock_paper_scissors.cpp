#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playRPS() {
    system("cls");
    int player, cpu;
    string options[3] = {"Rock", "Paper", "Scissors"};
    char repeat;

    do {
        srand(time(NULL));

        cout << "\n==============================\n";
        cout << "||   ROCK, PAPER, SCISSORS  ||\n";
        cout << "==============================\n";
        cout << "Choose an option:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << ">> Your choice: ";
        cin >> player;

        if (player < 1 || player > 3) {
            cout << "Invalid option.\n";
        } else {
            cpu = rand() % 3 + 1;

            cout << "\nYou chose: " << options[player - 1] << "\n";
            cout << "CPU chose: " << options[cpu - 1] << "\n";

            if (player == cpu) {
                cout << "Result: It's a tie.\n";
            } else if ((player == 1 && cpu == 3) ||
                       (player == 2 && cpu == 1) ||
                       (player == 3 && cpu == 2)) {
                cout << "Result: You win!\n";
            } else {
                cout << "Result: You lose.\n";
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nReturning to the main menu...\n";
}
