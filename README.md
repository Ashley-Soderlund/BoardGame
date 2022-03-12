# BoardGame

*- Created By* [@Ashley-Soderlund](https://github.com/Ashley-Soderlund) <br>
An ongoing project in my current Data Structures course. <br>
- Programming Language: c++
- Version Control Sysetm: Git, Github
- IDE: Visual Studio Code

## Project Description
**Version 1.0**: Players progress across a square numbered board with a score from a dice; the score boosts and drops through each number property. A player who reaches the highest-numbered cell on the board with minimum turns/rounds wins. Boosts and drops are determined through the value of the number being a perfect or prime number. 

**Version 2.0**: Inheritance was added to the GameEntry class from the base class of Student with new paramaters. The additition of an overloaded insertion operator `<<` to print out an object. A compare function to look at two players and see which one has a better GPA and score from the board game results. Also, improved modularity of functions.

Removal of Global: `using namespace std;` <br>
Implimentation of: `std::cout & std::endl` <br>

## Usage
- Pull code from Github
- Use a c++ Compiler
- Compile `driver.cpp` `GameEntry.cpp` `Score.cpp` and `Student.cpp` all together
- Run the Resulting File, For Example: `./a.exe`
- Input the Number of Players (currently just 3)
- Input the Size of the Board (any number that can be taken the squareroot of)
- Watch Terminal for Output

## File Descriptions

### driver.cpp
The main file that calls all functions and classes. It drives the board game through various functions. The header includes all .hpp files and the libraries `<iostream>` `<stdlib.h` `<cmath` and `<time.h>` (which is a C library that will be changed to `<ctime>` at a later date).
- `gameBoard()`: The input provided by the user will decide the size of the board, but the input has to be able to form an equal square after divided. A two-dimensional dynamic array will then be created and outputted to the terminal with number counting from 0 to userInput.
- `negativeFunction()`: Takes the paramaters of the curent score (position on the board) and the size of the board. Calls `prime()` to check if the new position after the dice roll is a perfect number.
  - If the number is prime and can be divided by 7 with no remainder, 8 is subtracted from the score.
  - If the number is prime and cannot be divided by 7 with no remainder, 5 is subtracted from the score.
  - Else, nothing is subtracted.
  - As long as the score with the dice roll and additions is below the size of the board, the value is added to the score and returned.
- `positiveFunction()`: Takes the paramaters of the curent score (position on the board) and the size of the board. Calls `perfect()` to check if the new position after the dice roll is a perfect number.
  - If number is perfect and divides by 10 without a remainder, 17 is added to the score.
  - If number is perfect but 10 doesn't divide without a remainder, 15 is added to the score.
  - Else, nothing is added.
  - As long as the score with the dice roll and additions is below the size of the board, the value is added to the score and returned.
- `play()`: Takes the paramaters of the curent score (position on the board) and the size of the board. It then runs through the turn of a player (cycling from the 1st to the next and so on, until players are out then start loop back over). A turn consists of rolling a dice and recieving a number (1-6), moving to a new position on the board, calling `negativeFunction()` and `positiveFunction()` to see if score is boosted or dropped, and then returning the score that will be then set to the current player's object.
- `perfect()`: Checks if the current score is a perfect number or not and returns true of false to `positiveFunction()`.
- `prime()`: Checks if the current score is a prime number or not and returns true or false to `negativeFunction()`.

### GameEntry.hpp
- Interface file for GameEntry class. This class inherits from the base class Student, and each objects holds a sport's name, score of reaching end of board, number of turns player took to reach the end, and from Student a name, gpa, and semester at school.

### GameEntry.cpp
- Implementation file for GameEntry class: defines the constructor & destructor and setter & getter functions. 
- `comparePlayers()`: Two GameEntry objects are compared if they have the same semester and sport value. 
  - Then, if the first player has better GPA and least number of round totals to win the board game, they are better.
  - Else, if the sencond player has better GPA and least number of round totals to win the board game, they are better.
  - Else, if they are exactly the same, they are equal.
  - Else, the two players cannot be compared and have no result.
- Operator Overload `<<`: A GameEntry object can be sent to the output by `std::cout << playerName;`. The result is all information about the player being showed to the user.

### Score.hpp
- Interface file for Score class. Class used as a way to store players that have finished the board game through an array.

### Score.cpp
- Implementation file for Score class: defines the constructor & destructor.
- `output()`: Uses the GameEntry class to get the name and round total of each player to output to the user.
- `add()`: GameEntry objects are added into an array once they reach the end of the board to display winners in the output, once all players have finished.

### Students.hpp
- Interface file for Student class. It is a base class. A Student object holds a name, gpa, and semester member variables. The functions are all setters and getters for the variables. 
- Eventual addition of an insertion sort alogrithm to organize students by their GPA from highest to lowest.

### Students.cpp
- Implementation file for Student class: defines the constructor & destructor and setter & getter functions.
