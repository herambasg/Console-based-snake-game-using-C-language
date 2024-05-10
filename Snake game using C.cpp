#include <stdio.h>		//header file that helps us to perform input and output operations
#include <conio.h>		//header file that provides console input and output
#include <stdlib.h>		//header file that provides rand function
#include <windows.h>	//header file that provides access to Windows API functions and data types

void setup(); 	//User defined function to initialize the game setup including snake and fruit positions within the game boundary
void draw(); 	//User defined function to draw the game window, snake, and fruit
void input(); 	//User defined function to handle user input from the keyboard
void logic(); 	//User defined function to control the game logic including snake movement and collision detection

int height = 20, width = 40;	//Variables representing the height and width of the game window
int gameover = 0; 				//Variable indicating whether the game is over (0 for not over, 1 for game over)
int x, y; 						//Variables representing the current position of the snake
int fruitx, fruity;				//Variables representing the position of the fruit
int score = 0; 					//Variable representing the player's score
int flag; 						//Variable to store user input from the keyboard
int tailX[100], tailY[100]; 	//Arrays to store the coordinates of the snake's tail
int counttail = 0; 				//Variable representing the length of the snake's tail


int main() {
    int m, n;
    char ch;

    counttail = 0;
    setup();

    while (!gameover) {		//while loop that runs the draw, input and logic functions till the game is over
        draw();
        input();
        logic();

        for (m = 0; m < 10000; m++) {
            for (n = 0; n < 2000; n++) {
            }
        }		//For loops used to introduce delay, controlling the speed of the game
    }

    printf("GAME OVER\n");
    printf("Your Score= %d", score);
    return 0;
}

void setup() {
    gameover = 0;
    
    //coordinates for initial position of snake
    x = width / 2;
    y = height / 2;
    
    //generating coordinates for position of fruit

    label1:
    //rand() is used to generate random integer values
    //rand() % width will generate the fruits within the boundary of snake game
    fruitx = rand() % width; 
    if (fruitx == 0) //if fruitx is 0, the control will goto label1 and rand func will be executed once again
        goto label1; //goto statement can be used to jump from anywhere to anywhere within a function
	//this process will go on till the fruitx value becomes 0

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

    int i, j, k;  //integer variables for height and width of game window and tail length of snake
    
	//for loop draw a square window with border to identify game area
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

void logic() {		//This is the heart of program which controls the movement of snake, updation of score and termination of program
    int i;

//declaring the body of snake as an array
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2x, prev2y;
    tailX[0] = x;
    tailY[0] = y;

//for loop to increase the length of body of snake
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

//condition for game over when snake hits the wall
    if (x >= width || x < 0 || y >= height || y < 0)
        gameover = 1;

//condition for game over when snake hits itself
	for (i = 0; i < counttail; i++) {
        if (x == tailX[i] && y == tailY[i])
            gameover = 1;
    }

//condition for snake eating the fruit
    if (y == fruity && x == fruitx) {
    	
//condition for generation of new fruit
        label3:
        fruitx = rand() % width;
        if (fruitx == 0)
            goto label3;

        label4:
        fruity = rand() % height;
        if (fruity == 0)
            goto label4;

//updating the score and increasing the length of the snake every time the snake eats a fruit
        score += 10;
        counttail++;
    }
}
