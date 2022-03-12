# BoardGame

*- Created By* [@Ashley-Soderlund](https://github.com/Ashley-Soderlund) <br>
An ongoing project in my current Data Structures course. <br>
- Programming Language: c++
- Version Control Sysetm: Git, Github
- IDE: Visual Studio Code

## Project Description
Version 1.0: Players progress across a square numbered board with a score from a dice; the score boosts and drops through each number property. A player who reaches the highest-numbered cell on the board with minimum turns/rounds wins. Boosts and drops are determined through the value of the number being a perfect or prime number. 

Version 2.0: Inheritance was added to the GameEntry class from the base class of Student with new paramaters. The additition of an overloaded insertion operator '<<' to print out and object. A compare function to look at two players and see which one has a better GPA and score from the board game results. Also, improved modularity of functions.

Removal of Global: `using namespace std;` <br>
Implimentation of: `std::cout & std::endl` <br>

## Usage

## File Descriptions

### driver.cpp


### GameEntry.hpp
Interface file for GameEntry class. This class inherits from the base class Student, and each objects holds a sport's name, score of reaching end of board, number of turns player took to reach the end, and from Student a name, gpa, and semester at school.

### GameEntry.cpp


### Score.hpp


### Score.cpp


### Students.hpp
Interface file for Student class. It is a base class. A Student object holds a name, gpa, and semester member variables. The functions are all setters and getters for the variables. <br> Eventual addition of an insertion sort alogrithm to organize students by their GPA from highest to lowest.

### Students.cpp
Implementation file for Student class: defines the constructor & destructor and setter & getter functions.
