#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void drawBoard(char *e);
void playerTurn(char *e, char symbol);
void cpuTurn(char *e, char cpu, char player, int difficulty);
bool checkWinner(char *e, char symbol);
bool checkTie(char *e);

void playTicTacToe() {
    char repeat;

    do {
        system("cls");
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char player1 = 'X';
        char player2 = 'O';
        int mode = 0, difficulty = 1;

        // Game mode selection
        do {
            cout << "\n==============================\n";
            cout << "||        TIC TAC TOE       ||\n";
            cout << "==============================\n";
            cout << "Select game mode:\n";
            cout << "1. Player vs Player\n";
            cout << "2. Player vs CPU\n>> ";
            cin >> mode;

            if (mode != 1 && mode != 2) {
                cout << "Invalid option. Try again.\n";
            }
        } while (mode != 1 && mode != 2);

        // Difficulty selection
        if (mode == 2) {
            do {
                cout << "\nSelect difficulty:\n";
                cout << "1. Easy\n2. Medium\n3. Hard\n>> ";
                cin >> difficulty;

                if (difficulty < 1 || difficulty > 3) {
                    cout << "Invalid difficulty. Try again.\n";
                }
            } while (difficulty < 1 || difficulty > 3);
        }

        drawBoard(spaces);

        while (true) {
            playerTurn(spaces, player1);
            drawBoard(spaces);
            if (checkWinner(spaces, player1)) {
                cout << "Player 1 wins.\n";
                break;
            }
            if (checkTie(spaces)) {
                cout << "It's a tie.\n";
                break;
            }

            if (mode == 1) {
                playerTurn(spaces, player2);
            } else {
                cpuTurn(spaces, player2, player1, difficulty);
            }

            drawBoard(spaces);
            if (checkWinner(spaces, player2)) {
                cout << (mode == 1 ? "Player 2 wins.\n" : "CPU wins.\n");
                break;
            }
            if (checkTie(spaces)) {
                cout << "It's a tie.\n";
                break;
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nReturning to the main menu...\n";
}

void drawBoard(char *e) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << e[0] << "  |  " << e[1] << "  |  " << e[2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << e[3] << "  |  " << e[4] << "  |  " << e[5] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << e[6] << "  |  " << e[7] << "  |  " << e[8] << "  \n";
    cout << "     |     |     \n\n";
}

void playerTurn(char *e, char symbol) {
    int n;
    do {
        cout << "Player " << symbol << ", enter a cell (1-9): ";
        cin >> n;
        n--;
        if (n >= 0 && n < 9 && e[n] == ' ') {
            e[n] = symbol;
            break;
        } else {
            cout << "Invalid cell. Try again.\n";
        }
    } while (true);
}

void cpuTurn(char *e, char cpu, char player, int difficulty) {
    int n;
    for (int i = 0; i < 9; i++) {
        if (e[i] == ' ') {
            e[i] = cpu;
            if (checkWinner(e, cpu)) return;
            e[i] = ' ';
        }
    }

    if (difficulty >= 2) {
        for (int i = 0; i < 9; i++) {
            if (e[i] == ' ') {
                e[i] = player;
                if (checkWinner(e, player)) {
                    e[i] = cpu;
                    return;
                }
                e[i] = ' ';
            }
        }
    }

    srand(time(0));
    while (true) {
        n = rand() % 9;
        if (e[n] == ' ') {
            e[n] = cpu;
            break;
        }
    }
}

bool checkWinner(char *e, char symbol) {
    return (
        (e[0] == symbol && e[1] == symbol && e[2] == symbol) ||
        (e[3] == symbol && e[4] == symbol && e[5] == symbol) ||
        (e[6] == symbol && e[7] == symbol && e[8] == symbol) ||
        (e[0] == symbol && e[3] == symbol && e[6] == symbol) ||
        (e[1] == symbol && e[4] == symbol && e[7] == symbol) ||
        (e[2] == symbol && e[5] == symbol && e[8] == symbol) ||
        (e[0] == symbol && e[4] == symbol && e[8] == symbol) ||
        (e[2] == symbol && e[4] == symbol && e[6] == symbol)
    );
}

bool checkTie(char *e) {
    for (int i = 0; i < 9; i++) {
        if (e[i] == ' ') return false;
    }
    return true;
}
