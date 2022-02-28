#include <iostream>
#pragma once
using namespace std;

class GameEntry {
public:
    GameEntry(const string& n="", int s=0, int r=0);
    string getName() const;
    int getScore() const;
    int getRound() const;
    void output(GameEntry& game) const;
    void setScore( int score1);
    void setRound(int roundTotal);
    ~GameEntry();
private:
    string name;
    int score;
    int roundTotal;

};
