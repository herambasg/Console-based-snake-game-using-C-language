#include <stdio.h> //header file that helps us to perform input and output operations
#include <conio.h> //header file that provides console input and output
#include <stdlib.h> //header file that provides rand function
#include <windows.h>

void setup();
void draw();
void input();
void logic();

int height = 20, width = 40;
int gameover = 0;
int x, y;
int fruitx, fruity;
int score = 0;
int flag;
int tailX[100], tailY[100];
int counttail = 0;

int main() {
    int m, n;
    char ch;

    counttail = 0;
    setup();

    while (!gameover) {
        draw();
        input();
        logic();

        for (m = 0; m < 10000; m++) {
            for (n = 0; n < 2000; n++) {
            }
        }
    }

    printf("GAME OVER\n");
    printf("Your Score= %d", score);
    return 0;
}

void setup() {
    gameover = 0;
    x = width / 2;
    y = height / 2;

    label1:
    fruitx = rand() % width;
    if (fruitx == 0)
        goto label1;

    label2:
    fruity = rand() % height;
    if (fruity == 0)
        goto label2;
}

void draw() {
    // Move cursor to the top-left corner of the console window
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                printf("#");
            else {
                int isBody = 0;
                for (k = 0; k < counttail; k++) {
                    if (i == tailY[k] && j == tailX[k]) {
                        printf("o");
                        isBody = 1;
                        break;
                    }
                }
                if (!isBody) {
                    if (i == y && j == x)
                        printf("@");
                    else if (i == fruity && j == fruitx)
                        printf("*");
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }

    // Introduce a short delay to control the speed of the game
    Sleep(100);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                flag = 1;
                break;
            case 'd':
                flag = 2;
                break;
            case 'w':
                flag = 3;
                break;
            case 's':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void logic() {
    int i;

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2x, prev2y;
    tailX[0] = x;
    tailY[0] = y;

    for (i = 1; i < counttail; i++) {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }

    switch (flag) {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default:
            break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        gameover = 1;

    for (i = 0; i < counttail; i++) {
        if (x == tailX[i] && y == tailY[i])
            gameover = 1;
    }

    if (y == fruity && x == fruitx) {
        label3:
        fruitx = rand() % width;
        if (fruitx == 0)
            goto label3;

        label4:
        fruity = rand() % height;
        if (fruity == 0)
            goto label4;

        score += 10;
        counttail++;
    }
}
