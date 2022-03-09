#include <iostream>
#include "GameEntry.hpp"


void GameEntry::output(GameEntry& game) const{                        //outputs name and score of an object
    std::cout << "The game name is: " << game.getName() << std::endl;
    std::cout << "The game score is: " << game.getScore() << std::endl;
}

GameEntry::GameEntry(const std::string& n, int s, int r): sportName(n), score(s), roundTotal(r){}    //constructor

std::string GameEntry::getName() const {return name;}                    //gets the name paramater of an object
int GameEntry::getScore() const {return score;}                     //gets the score paramater of an object
int GameEntry::getRound() const {return roundTotal;}                //gets the round paramater of an object
std::string GameEntry:: getSportName() const {return sportName;}         //gets the sportName paramater of an object


void GameEntry::setScore(int score1) {            //sets the score of an object
    score = score1;
}

void GameEntry::setRound(int roundTotal1){        //sets the round total of an object
    roundTotal = roundTotal1;
}

void GameEntry::setSportName(std::string sportName1){  //sets the sport name value of an object
    sportName = sportName1;
}

//void GameEntry::operator<<(const GameEntry& game){
    //Student::GameEntry =(game);

//}

//GameEntry::~GameEntry(){       //Destructor
  //  delete[] &name, score;
//}
