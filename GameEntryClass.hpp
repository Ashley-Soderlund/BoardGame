#include <iostream>
#include "Students.hpp"
#pragma once


class GameEntry: public Student {          //GameEntry inherited from Student Class
public:
    //GameEntry();
    //GameEntry(const std::string& n="", float g=0.0, int s=0, const std::string& sn="", int sc=0, int r=0);    
    
    GameEntry(const std::string& n="", int s=0, int r=0);                         //Constructor
    std::string getName() const;
    int getScore() const;
    int getRound() const;
    std::string getSportName() const;
    void setScore( int score1);
    void setRound(int roundTotal);
    void setSportName(std::string sportName1);
    friend void comparePlayers(GameEntry& game1, GameEntry& game2);                //compares two player objects based on their gpa and game score
    friend void operator << (std::ostream& os, const GameEntry& game);             //overloading the '<<' operator to print out an object
    //~GameEntry();
private:
    std::string sportName;
    int score;
    int roundTotal;
};
