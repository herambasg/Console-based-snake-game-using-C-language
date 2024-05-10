# Console-based-snake-game-using-C-language
"Snake Game using C" is a beginner-friendly project that brings the classic arcade game to life in the C programming language. Players navigate a snake through a grid, gobbling food to grow while avoiding walls and the snake's tail using arrow keys. Built with standard C libraries, it's accessible and requires no additional software. But simplicity doesn't mean a lack of depth—this project offers room for customization, allowing developers to add levels, obstacles, and power-ups. Beyond creating a game, it's an educational journey into game development, teaching concepts like user input handling and debugging. Whether you're new to programming or a seasoned developer, "Snake Game using C" offers a fun and educational experience.

# Algorithm of the Program

1. Initialize the setup function to set the position of the snake and fruit within the boundary of square window.
2. Initialize the draw function to draw a square window with a border to identify the game area and a snake and a fruit consisting of one cell.
3. Place the snake initially in the middle of the game window.
4. Place a fruit on the board at a random location using the rand() function and use the goto statement once the fruit gets eaten by the snake.
5. Use the input function to take input from the keyboard and to further store the value in the flag variable.
6. Get a char input from the user.
7. Enter the logic function, and use a for loop to increase the length of the body of  snake.
8. Use a switch case to indicate which direction the snake moves on pressing a particular key.
9. Write the condition to end the game when the snake hits the wall and the snake hits itself.
10. Write the conditions for the snake eating the fruit and generation of a new fruit (using the goto statement).
11. Update the score and increase the length of the snake every time the snake eats a fruit.
12. End the game when the snake hits itself or the boundary walls game window.
