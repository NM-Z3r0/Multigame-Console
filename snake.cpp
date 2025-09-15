#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int snakeWidth = 20;
const int snakeHeight = 10;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void setup() {
    gameOver = false;
    dir = STOP;
    x = snakeWidth / 2;
    y = snakeHeight / 2;
    fruitX = rand() % snakeWidth;
    fruitY = rand() % snakeHeight;
    score = 0;
    nTail = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < snakeWidth + 2; i++) cout << "#";
    cout << "\n";

    for (int i = 0; i < snakeHeight; i++) {
        for (int j = 0; j < snakeWidth; j++) {
            if (j == 0) cout << "#";

            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "#";
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "*";
                        printTail = true;
                    }
                }
                if (!printTail) cout << " ";
            }

            if (j == snakeWidth - 1) cout << "#";
        }
        cout << "\n";
    }

    for (int i = 0; i < snakeWidth + 2; i++) cout << "#";
    cout << "\nScore: " << score << "\n";
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    if (x < 0 || x >= snakeWidth || y < 0 || y >= snakeHeight)
        gameOver = true;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % snakeWidth;
        fruitY = rand() % snakeHeight;
        nTail++;
    }
}

void playSnake() {
    system("cls");
    char repeat;

    do {
        cout << "\n==============================\n";
        cout << "||          SNAKE           ||\n";
        cout << "==============================\n";

        cout << "Controls:\n";
        cout << "Move: W (up), A (left), S (down), D (right)\n";
        cout << "Exit: X\n";
        cout << "\nPress ENTER to start...";
        cin.ignore();
        cin.get();

        setup();

        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(100);
        }

        cout << "\nGame over. Final score: " << score << "\n";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "\nReturning to the main menu...\n";
}
