#include <iostream>
#include "GameEntry.hpp"
#pragma once
using namespace std;

class Scores{
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    void output(const GameEntry& pl1, const GameEntry& pl2, const GameEntry& pl3);
private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};
