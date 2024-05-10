# Console-based-snake-game-using-C-language
"Snake Game using C" is a classic arcade-style project that brings the beloved Snake game to life using the C programming language. Perfect for beginner programmers eager to delve into game development, this project offers a hands-on opportunity to explore core programming concepts like control structures, loops, functions, and data structures.

The game kicks off with a simple yet engaging premise: maneuver a snake across a grid-like board, gobbling up food to grow longer while steering clear of walls and the snake's own tail. Control is intuitive, with players directing the snake's movement using arrow keys on the keyboard.

What sets this project apart is its accessibility and simplicity. Developed exclusively with standard C libraries, it requires no additional software or external dependencies. This makes it an ideal starting point for those new to programming or looking to reinforce their C skills.

But don't let its simplicity fool you. The project is ripe for customization and expansion. With a solid foundation in place, budding developers can experiment with adding new features like multiple levels, obstacles, and power-ups, injecting their own creative flair into the classic game formula.

Moreover, the project isn't just about creating a game; it's about understanding the process behind game development. By building this Snake game in C, participants gain valuable insights into game design, user input handling, and debugging techniques. It's a holistic learning experience that combines theory with practical application, empowering programmers to tackle more ambitious projects down the line.

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
