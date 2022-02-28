#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include "GameEntry.hpp"
#include "Scores.hpp"
using namespace std;

void gameBoard(int sizeOfBoard);
//Pre-condition: size of board that is given by the user
//Post-condition: outputs board

int negativeFunction(int score, int sizeOfBoard);
//Pre-condition: current score of a player
//Post-condition: returns an updated score value as long as input was a prime number and result is <= 100

int positiveFunction(int score, int sizeOfBoard);
//Pre-condition: current score of a player
//Post-condition: returns an updated score value as long as input was a perfect number and result is <= 100

int play(int score, int sizeOfBoard);
//Pre-condition: current score of a player
//Post-condition: returns an updated score after adding the diceRoll then the positiveFunction and negativeFunction


int main(){
    srand(static_cast<unsigned int> (time(0)));                                       //initializing rand() function

    int numberOfPlayers;
    int sizeOfBoard;

    cout << "Enter the number of players (please enter 3)" << endl;                   //get number of players from user
    cin >> numberOfPlayers;
    cout << "Enter the highest value of the game board (use perfect squares, ie. 49, 100, 225)" << endl;        //get size of the board
    cin >> sizeOfBoard;
    cout << "\n" << endl;

    GameEntry player1("Ashley", 0, 0);                                                //create player objects
    GameEntry player2("Jon", 0, 0);
    GameEntry player3("Seth", 0, 0);

    Scores boardGameChampionship(numberOfPlayers);

    cout << "Game Board: " << endl;                                                   //See if you can merge next two lines
    gameBoard(sizeOfBoard);                                                           //output the game board
    cout << endl;

    int p1 = 0;                                                                       //declare and initialize variables
    int p2 = 0;                                                                       //which are used to keep track of
    int p3 = 0;                                                                       //different cycles in the while loop
    int countPlayersFinished = 0;
    int rounds = 1;

    while (countPlayersFinished < numberOfPlayers){                                                 //playing the game until all players have finished
        if(player1.getScore() < sizeOfBoard || player2.getScore() < sizeOfBoard || player3.getScore() < sizeOfBoard){   //scores must be below the size of board to add more to the score
            cout << "-------------------------------------------" << endl;
            cout << "                   Round-" << rounds << "\n" << "-------------------------------------------" << endl;
            
            player1.setScore(play(player1.getScore(), sizeOfBoard));                   //set the player score to the resulting value from playing a round
            cout << "Player 1- " << player1.getScore() << endl;

            player2.setScore(play(player2.getScore(), sizeOfBoard));                    //set the player score to the resulting value from playing a round
            cout << "Player 2- " << player2.getScore() << endl;

            player3.setScore(play(player3.getScore(), sizeOfBoard));                    //set the player score to the resulting value from playing a round
            cout << "Player 3- " << player3.getScore() << endl;
        
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


    cout << "\n" << "Final Scores: " << endl;
    boardGameChampionship.output(player1, player2, player3);            //output player's name and total rounds it took to win

    player1.~GameEntry();                                               //deallocation of object's memory
    player2.~GameEntry();
    player3.~GameEntry();
    boardGameChampionship.~Scores();

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
        cout << A[i] << " ";
        row++;
        if(row % M == 0){
            cout << "\n";
        }
    }

    cout << "\n" << "\n";

    delete[] A;                                                         //dealocate memory for the dynamic 2D array

}

int negativeFunction(int score, int sizeOfBoard){
    bool prime;                                                         //bool function to say if value is prime or not
    int temp = score;                                                   //create copy of score in temp variable

    if (score <= 5){                                                    //numbers <= 5 not included in prime for program
        prime = false;
    }

    for(int i = 5; i < score; i++){                                     //starting from 5 until the score, see if a value is prime
        if(score % i == 0){
            prime = false;
        }
        else{
            prime = true;
        }
    }
    
    if(prime == true){                                                    //if value is prime
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

int positiveFunction(int score, int sizeOfBoard){
    bool perfect;                                                         //bool variable to say if the score is a perfect number or not
    int sum = 0;
    int temp = score;                                                     //create a copy of score in temp variable

    for(int i = 1; i < score; i++){                                       //find the sum of a score value to check if it is a perfect number
        if(score % i == 0){                                             
            sum = sum + i;
        }
    }

    if(score == sum){                                                     //if sum and score are equal, then it is a perfect number
        perfect = true;
    }
    else{                                                                 //else, it is not a perfect number
        perfect = false;
    }

    

    if(perfect == true){                                            //if it is a perfect number
        if(score % 10 == 0){                                        //and can be divided by 10 with no remainder, then temp gains 17
            temp = temp + 17;
        }
        else{                                                       //if it is a perfect number, but not divisible by 10, then only gain 15
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

    cout << "Dice Roll: " << diceRoll << endl;

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
