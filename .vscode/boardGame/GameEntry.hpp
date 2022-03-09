#include <iostream>
#include "Student.hpp"
#pragma once


class GameEntry: public Student {
public:
    GameEntry(const std::string& n="", int s=0, int r=0);
    //GameEntry(Student s) : Student(s) {}
    std::string getName() const;
    int getScore() const;
    int getRound() const;
    std::string getSportName() const;
    void output(GameEntry& game) const;
    void setScore( int score1);
    void setRound(int roundTotal);
    void setSportName(std::string sportName1);
    //void GameEntry::operator<<(const GameEntry& game);
    //friend void comparePlayers(GameEntry& game1, GameEntry& game2);
    //~GameEntry();
private:
    //string name;
    std::string sportName;
    int score;
    int roundTotal;

};

//void comparePlayers(GameEntry& game1, GameEntry& game2){
    //cout << "Works";
//};
