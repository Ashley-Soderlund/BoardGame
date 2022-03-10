#include <iostream>
#include "GameEntry.hpp"


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

void comparePlayers(GameEntry& game1, GameEntry& game2){

    std::cout << "Comparing two players based on their gpa and game score:" << std::endl;

    if(game1.getSportName() == game2.getSportName() && game1.getSemester() == game2.getSemester()){
        if(game1.getScore() >= game2.getScore() && game1.getGPA() >= game2.getGPA()){
            std::cout << "The player " << game1.getName() << " is better than " << game2.getName() << std::endl;
        }
        else if (game1.getScore() <= game2.getScore() && game1.getGPA() <= game2.getGPA()){
            std::cout << "The player " << game2.getName() << " is better than " << game1.getName() << std::endl;
        }
        else if(game1.getScore() == game2.getScore() && game1.getGPA() == game2.getGPA()){
            std::cout << "The players " << game1.getName() << " and " << game2.getName() << " are equal." << std::endl;
        }
        else{
            std::cout << "They are not equal and one player is not better in both the categories of gpa and score." << std::endl;
        }
    }
    else{
        std::cout << "These players cannot be compared because their semester and sport are not the same." << std::endl;
    }
    std::cout << std::endl;
};

void operator << (std::ostream& os, const GameEntry& game){
        std::cout << game.getName() << std::endl;
}

//GameEntry::~GameEntry(){       //Destructor
  //  delete[] &name, score;
//}
