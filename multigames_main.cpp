#include <iostream>
#include <cstdlib>
#include <string>

#include "guess_number.cpp"
#include "rock_paper_scissors.cpp"
#include "tictactoe.cpp"
#include "snake.cpp"
#include "pong.cpp"

using namespace std;

void playGuess();
void playRPS();
void playTicTacToe();
void playSnake();
void playPong();

void showBanner() {
    cout << "=====================================\n";
    cout << "||         MULTIGAME CONSOLE       ||\n";
    cout << "=====================================\n";
    cout << "|| 1. Guess the Number             ||\n";
    cout << "|| 2. Rock, Paper, Scissors        ||\n";
    cout << "|| 3. Tic Tac Toe                  ||\n";
    cout << "|| 4. Snake Game                   ||\n";
    cout << "|| 5. Pong                         ||\n";
    cout << "|| 0. Exit                         ||\n";
    cout << "=====================================\n";
}

int main() {
    int op;
    do {
        system("cls");
        showBanner();
        cout << "\n>> Select your game (0-5): ";
        cin >> op;

        switch (op) {
            case 1: 
                playGuess(); 
                break;
            case 2: 
                playRPS(); 
                break;
            case 3: 
                playTicTacToe(); 
                break;
            case 4: 
                playSnake(); 
                break;
            case 5: 
                playPong(); 
                break;
            case 0: 
                cout << "\nThanks for playing. See you next time.\n"; 
                break;
            default: 
                cout << "\nInvalid option. Try again.\n"; 
                break;
        }

        if (op != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(); cin.get();
        }

    } while (op != 0);

    return 0;
}
