#include <iostream>
#include "Scores.hpp"
using namespace std;


Scores::Scores(int maxEnt){                           //constuctor 
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores(){                                    //destructor
    delete[] entries;
}

void Scores::output(const GameEntry& pl1, const GameEntry& pl2, const GameEntry& pl3){             //output round totals of each player
    cout << pl1.getName() << ": " << pl1.getRound() << endl;
    cout << pl2.getName() << ": " << pl2.getRound() << endl;
    cout << pl3.getName() << ": " << pl3.getRound() << endl;
}

void Scores::add(const GameEntry& e){                                                              //add an entry to object
    int newScore = e.getScore();
    if(numEntries == maxEntries){
        if(newScore <= entries[maxEntries-1].getScore()){
            return;
        }
    }
    else numEntries++;
   

    int i = numEntries - 2;
    while (i >= 0 && newScore > entries[i].getScore()){
     entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e;
}