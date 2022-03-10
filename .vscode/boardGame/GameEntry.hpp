#include <iostream>
#include "Student.hpp"
#pragma once


class GameEntry: public Student {
public:
    GameEntry(const std::string& n="", int s=0, int r=0);           //is there a better way to make a constructor that add Student member variables?
    //GameEntry(Student s) : Student(s) {}
    std::string getName() const;
    int getScore() const;
    int getRound() const;
    std::string getSportName() const;
    void output(GameEntry& game) const;
    void setScore( int score1);
    void setRound(int roundTotal);
    void setSportName(std::string sportName1);
    //void GameEntry::operator<<(std::ostream& out, const GameEntry& game);     overloading the operator is not working, "too many paramaters"
    //friend ostream& operator<<(std::ostream& out, const GameEntry& game);       "cannot overload functions"
    friend void comparePlayers(GameEntry& game1, GameEntry& game2);
    //~GameEntry();
private:
    std::string sportName;
    int score;
    int roundTotal;
};

