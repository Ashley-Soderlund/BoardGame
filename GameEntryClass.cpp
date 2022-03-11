#include <iostream>
#include "GameEntry.hpp"


GameEntry::GameEntry(const std::string& n, int s, int r): sportName(n), score(s), roundTotal(r){}    //constructor
// GameEntry::GameEntry() : Student(), sportName(), score(0), roundTotal(0){}
// GameEntry::GameEntry(const std::string& n="", float g=0.0, int s=0, const std::string& sn="", int sc=0, int r=0)        Constructor From Book, led to errors
//     :Student (n, g, s), sportName(sn), score(sc), roundTotal(r) 
// {}

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

void comparePlayers(GameEntry& game1, GameEntry& game2){          //compares two players if they are in the same semester and sport

    std::cout << "Comparing two players based on their gpa and game score:" << std::endl;

    if(game1.getSportName() == game2.getSportName() && game1.getSemester() == game2.getSemester()){
        if(game1.getScore() >= game2.getScore() && game1.getGPA() >= game2.getGPA()){                                 //if player1's score and gpa are better
            std::cout << "The player " << game1.getName() << " is better than " << game2.getName() << std::endl;
        }
        else if (game1.getScore() <= game2.getScore() && game1.getGPA() <= game2.getGPA()){                           //if player2's score and gpa are better
            std::cout << "The player " << game2.getName() << " is better than " << game1.getName() << std::endl;
        }
        else if(game1.getScore() == game2.getScore() && game1.getGPA() == game2.getGPA()){                                //if they are equal
            std::cout << "The players " << game1.getName() << " and " << game2.getName() << " are equal." << std::endl;
        }
        else{                                                                                                                           //other conditions
            std::cout << "They are not equal and one player is not better in both the categories of gpa and score." << std::endl;
        }
    }
    else{
        std::cout << "These players cannot be compared because their semester and sport are not the same." << std::endl;
    }
    std::cout << std::endl;
};

void operator << (std::ostream& os, const GameEntry& game){                                 //Operator overloading to output GameEntry object information
        std::cout << game.getName() << ":" <<std::endl;
        std::cout << "GPA- " <<  game.getGPA() << std::endl;
        std::cout << "Semester- " <<  game.getSemester() << std::endl;
        std::cout << "Sport- " <<  game.getSportName() << std::endl;
        std::cout << "Score from Board Game- " <<  game.getRound() << "\n" << std::endl;
}

//GameEntry::~GameEntry(){       //Destructor
  //  delete[] &name, score;
//}
