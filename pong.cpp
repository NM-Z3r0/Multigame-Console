#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int pongWidth = 40;
const int pongHeight = 20;
int ballX, ballY;
int player1Y, player2Y;
int dirX = 1, dirY = 1;
int score1 = 0, score2 = 0;
bool cpuMode = false;
int difficulty = 1;

void drawPong() {
    system("cls");

    for (int i = 0; i < pongWidth + 2; i++) cout << "#";
    cout << "\n";

    for (int y = 0; y < pongHeight; y++) {
        cout << "#";
        for (int x = 0; x < pongWidth; x++) {
            bool isPlayer1 = (x == 1 && (y >= player1Y - 2 && y <= player1Y + 2));
            bool isPlayer2 = (x == pongWidth - 2 && (y >= player2Y - 2 && y <= player2Y + 2));
            bool isBall = (x == ballX && y == ballY);
            bool isCenterLine = (x == pongWidth / 2 && y % 2 == 0);

            if (isPlayer1) cout << "|";
            else if (isPlayer2) cout << "|";
            else if (isBall) cout << "O";
            else if (isCenterLine) cout << ":";
            else cout << " ";
        }
        cout << "#\n";
    }

    for (int i = 0; i < pongWidth + 2; i++) cout << "#";
    cout << "\nP1: " << score1 << "  P2: " << score2 << "\n";
}

void inputPong() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'w' && player1Y > 2) player1Y--;
        if (key == 's' && player1Y < pongHeight - 3) player1Y++;

        if (!cpuMode) {
            if (key == 'o' && player2Y > 2) player2Y--;
            if (key == 'l' && player2Y < pongHeight - 3) player2Y++;
        }
    }
}

void moveCPU() {
    int delay;
    switch (difficulty) {
        case 1: delay = 2; break;
        case 2: delay = 1; break;
        case 3: delay = 0; break;
        default: delay = 1;
    }

    static int counter = 0;
    counter++;
    if (counter >= delay) {
        if (ballY < player2Y && player2Y > 2) player2Y--;
        else if (ballY > player2Y && player2Y < pongHeight - 3) player2Y++;
        counter = 0;
    }
}

void logicPong() {
    ballX += dirX;
    ballY += dirY;

    if (ballY <= 0 || ballY >= pongHeight - 1) dirY *= -1;

    if (ballX == 2 && (ballY >= player1Y - 2 && ballY <= player1Y + 2)) dirX *= -1;
    if (ballX == pongWidth - 3 && (ballY >= player2Y - 2 && ballY <= player2Y + 2)) dirX *= -1;

    if (ballX <= 0) {
        score2++;
        ballX = pongWidth / 2;
        ballY = pongHeight / 2;
        dirX = 1;
    }

    if (ballX >= pongWidth - 1) {
        score1++;
        ballX = pongWidth / 2;
        ballY = pongHeight / 2;
        dirX = -1;
    }

    if (cpuMode) moveCPU();
}

void playPong() {
    char repeat;

    do {
        ballX = pongWidth / 2;
        ballY = pongHeight / 2;
        player1Y = pongHeight / 2;
        player2Y = pongHeight / 2;
        score1 = score2 = 0;

        int mode = 0;

        cout << "\n==============================\n";
        cout << "||           PONG           ||\n";
        cout << "==============================\n";

        do {
            cout << "Select game mode:\n";
            cout << "1. Player vs Player\n";
            cout << "2. Player vs CPU\n>> ";
            cin >> mode;

            if (mode != 1 && mode != 2) {
                cout << "Invalid option. Try again.\n";
            }
        } while (mode != 1 && mode != 2);

        cpuMode = (mode == 2);

        if (cpuMode) {
            do {
                cout << "\nSelect difficulty:\n";
                cout << "1. Easy\n2. Medium\n3. Hard\n>> ";
                cin >> difficulty;

                if (difficulty < 1 || difficulty > 3) {
                    cout << "Invalid difficulty. Try again.\n";
                }
            } while (difficulty < 1 || difficulty > 3);
        }

        cout << "\nControls:\n";
        cout << "Player 1: W (up), S (down)";
        if (!cpuMode) cout << " | Player 2: O (up), L (down)";
        cout << "\nPress X to exit during the game.\n";
        cout << "Best of 5 wins...\n";
        cout << "\nPress ENTER to start...";
        cin.ignore();
        cin.get();

        while (score1 < 5 && score2 < 5) {
            draw();
            inputPong();
            logic();
            Sleep(60);

            if (_kbhit() && _getch() == 'x') break;
        }

        if (score1 == 5 || score2 == 5) {
            cout << "\nGame over!\n";
            if (score1 == 5) cout << "\nPlayer 1 wins the match.\n";
            else cout << "\n" << (cpuMode ? "CPU" : "Player 2") << " wins the match.\n";
        } else {
            cout << "\nGame interrupted. P1: " << score1 << " | P2: " << score2 << "\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nReturning to the main menu...\n";
}
