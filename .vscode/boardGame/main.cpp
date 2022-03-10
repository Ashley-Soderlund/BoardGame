#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include "GameEntry.hpp"
#include "Scores.hpp"
#include "Student.hpp"


void gameBoard(int sizeOfBoard);
//Pre-condition: size of board that is given by the user
//Post-condition: outputs board

int negativeFunction(int score, int sizeOfBoard);
//Pre-condition: current score of a player, and size of board given by player
//Post-condition: returns an updated score value as long as input was a prime number and result is <= 100

int positiveFunction(int score, int sizeOfBoard);
//Pre-condition: current score of a player, and size of board given by player
//Post-condition: returns an updated score value as long as input was a perfect number and result is <= 100

int play(int score, int sizeOfBoard);
//Pre-condition: current score of a player, and size of board given by player
//Post-condition: returns an updated score after adding the diceRoll then the positiveFunction and negativeFunctio

int main(){
    srand(static_cast<unsigned int> (time(0)));                                       //initializing rand() function

    int numberOfPlayers;
    int sizeOfBoard;

    std::cout << "Enter the number of players (please enter 3)" << std::endl;                   //get number of players from user
    std::cin >> numberOfPlayers;
    std::cout << "Enter the highest value of the game board (use perfect squares, ie. 49, 100, 225)" << std::endl;        //get size of the board
    std::cin >> sizeOfBoard;
    std::cout << "\n" << std::endl;

    GameEntry player1("soccer", 0, 0);                                                //create player objects
    player1.name = "Ashley";
    player1.gpa = 3.9;
    player1.semester = 8;
    GameEntry player2("nothing", 0, 0);
    player2.name = "Jon";
    player2.gpa = 4.0;
    player2.semester = 8;
    GameEntry player3("nothing", 0, 0);
    player3.name = "Seth";
    player3.gpa = 3.7;
    player3.semester = 8;

    Scores boardGameChampionship(numberOfPlayers);

    std::cout << "Game Board: " << std::endl;                                                   //See if you can merge next two lines
    gameBoard(sizeOfBoard);                                                           //output the game board
    std::cout << std::endl;

    int p1 = 0;                                                                       //declare and initialize variables
    int p2 = 0;                                                                       //which are used to keep track of
    int p3 = 0;                                                                       //different cycles in the while loop
    int countPlayersFinished = 0;
    int rounds = 1;

    while (countPlayersFinished < numberOfPlayers){                                                 //playing the game until all players have finished
        if(player1.getScore() < sizeOfBoard || player2.getScore() < sizeOfBoard || player3.getScore() < sizeOfBoard){   //scores must be below the size of board to add more to the score
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "                   Round-" << rounds << "\n" << "-------------------------------------------" << std::endl;
            
            player1.setScore(play(player1.getScore(), sizeOfBoard));                   //set the player score to the resulting value from playing a round
            std::cout << "Player 1- " << player1.getScore() << std::endl;

            player2.setScore(play(player2.getScore(), sizeOfBoard));                    //set the player score to the resulting value from playing a round
            std::cout << "Player 2- " << player2.getScore() << std::endl;

            player3.setScore(play(player3.getScore(), sizeOfBoard));                    //set the player score to the resulting value from playing a round
            std::cout << "Player 3- " << player3.getScore() << std::endl;
        
            if(player1.getScore() == sizeOfBoard && p1 == 0){                           //when a player reaches 100, their object is added to the Scores object
                p1++;                                                                   //only enter if statement once.                             
                player1.setRound(rounds);
                boardGameChampionship.add(player1);
            }

            if(player2.getScore() == sizeOfBoard && p2 == 0){                           //when a player reaches 100, their object is added to the Scores object
                p2++;                                                                   //only enter if statement once.
                player2.setRound(rounds);
                boardGameChampionship.add(player2);
            }

            if(player3.getScore() == sizeOfBoard && p3 == 0){                           //when a player reaches 100, their object is added to the Scores object
                p3++;                                                                   //only enter if statement once.
                player3.setRound(rounds);
                boardGameChampionship.add(player3);
            }

            rounds++; 
            }
        else{                                             //If all scores are equal to 100, then while loop will end because players finished is equal to players playing
            countPlayersFinished = numberOfPlayers;
        }
    }


    std::cout << "\n" << "Final Scores: " << std::endl;
    boardGameChampionship.output(player1, player2, player3);            //output player's name and total rounds it took to win

    //player1.~GameEntry();                                               //deallocation of object's memory
    //player2.~GameEntry();
    //player3.~GameEntry();
    boardGameChampionship.~Scores();
    comparePlayers(player3, player2);

    return 0;
}

void gameBoard(int size){
    int M = sqrt(size);
    int N = M;

    int* A = new int[M * N];                                            // dynamically allocate memory of size `M × N`
 
    int num = 1;                                                        // assign values to the allocated memory
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            *(A + i*N + j) = num;
            num++;
        }
    }

    int row = 0;                                                       //output array backwards from highest value to 1
    for (int i = size-1; i >= 0; i--){
        std::cout << A[i] << " ";
        row++;
        if(row % M == 0){
            cout << "\n";
        }
    }

    std::cout << "\n" << "\n";

    delete[] A;                                                         //dealocate memory for the dynamic 2D array

}

bool prime(int score){
    if (score <= 5){                                                    //numbers <= 5 not included in prime for program
        return false;
    }

    for(int i = 5; i < score; i++){                                     //starting from 5 until the score, see if a value is prime
        if(score % i == 0){
            return false;
        }
        else{
            return true;
        }
    }

    return false;
}

int negativeFunction(int score, int sizeOfBoard){       
    int temp = score;                                                   //create copy of score in temp variable

    bool primeResult = prime(score);
    
    if(primeResult == true){                                                    //if value is prime
       if(score % 7 == 0){                                                //if the remainder of score/7 is 0
           temp = temp - 8;                                               //subtract 8 from current temp value
        } 
        else{                                                             //else, only subtract by 5
            temp = temp - 5;
        }
    }

    if (temp > sizeOfBoard){                                              //if score is over the size of the board, player doesn't move
        score = score;                                                    //if it is under, score change with new temp value
    }
    else
    {
        score = temp;
    }

    return score;
}

bool perfect(int score){
    int sum = 0;
    for(int i = 1; i < score; i++){                                       //find the sum of a score value to check if it is a perfect number
        if(score % i == 0){                                             
            sum = sum + i;
        }
    } 

    if(score == sum){                                                     //if sum and score are equal, then it is a perfect number
        return true;
    }
    else{                                                                 //else, it is not a perfect number
        return false;
    }

    return false;
}

int positiveFunction(int score, int sizeOfBoard){
    int temp = score;                                                     //create a copy of score in temp variable

    bool perfectResult = perfect(score);

    if(perfectResult == true){                                            //if it is a perfect number
        if(score % 10 == 0){                                              //and can be divided by 10 with no remainder, then temp gains 17
            temp = temp + 17;
        }
        else{                                                             //if it is a perfect number, but not divisible by 10, then only gain 15
            temp = temp + 15;
        }
    }

    if (temp > sizeOfBoard){                                    //if score is over the size of the board, player doesn't move
        score = score;
    }
    else
    {
        score = temp;
    }

    return score;
}

int play(int score, int sizeOfBoard){
    int randomNumber = rand();                               //create a random number
    int diceRoll = (randomNumber % 6 + 1);                   //make dice roll between 1 and 6

    cout << "Dice Roll: " << diceRoll << std::endl;

    int temp = 0;
    if(score + diceRoll <= sizeOfBoard){                    //sum of score a diceRoll must be less than the size of the board to move again
        score = score + diceRoll;
        if(diceRoll != 6){                                  //rolls of 6 are not affected by negativeFunction
            temp = negativeFunction(score, sizeOfBoard);    //check if value is a prime number, will return same or changed score
        }
        temp = positiveFunction(score, sizeOfBoard);        //check if value is a perfect number, will return same or changed score

    }
    else{                                                   //if sum of diceRoll and score are over the size of the board, temp score will stay the same
        temp = score;
    }

    return temp;                                                
}