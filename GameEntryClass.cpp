#include <iostream>
#include "GameEntry.hpp"
using namespace std;


void GameEntry::output(GameEntry& game) const{                        //outputs name and score of an object
    cout << "The game name is: " << game.getName() << endl;
    cout << "The game score is: " << game.getScore() << endl;
}

GameEntry::GameEntry(const string& n, int s, int r): name(n), score(s), roundTotal(r){}    //constructor

string GameEntry::getName() const {return name;}                    //gets the name paramater of an object
int GameEntry::getScore() const {return score;}                     //gets the score paramater of an object
int GameEntry::getRound() const {return roundTotal;}                //gets the round paramater of an object


void GameEntry::setScore(int score1) {            //sets the score of an object
    score = score1;
}

void GameEntry::setRound(int roundTotal1){        //sets the round total of an object
    roundTotal = roundTotal1;
}

GameEntry::~GameEntry(){       //Destructor
    delete[] &name, score;
}
