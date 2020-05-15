#pragma once

#include <vector>
#include "Player.h"
using namespace std;

class Jail
{
private:
    //Player *players[playerCount];
    //Player **players;
    vector<Player*> players;
    // int playerCount;


public:
    Jail();
    ~Jail();
	void tourney();
    int run(); // does one round, each player x each other
    void pit( Player*, Player*, int );
	char padded(Player*, int);
	void bunches(); // does a bunch of rounds, calcualte rank sum
	void sort();
	void sortr();
	void shuffle();

    // return the points for the given combination of choices.
    // Assumes we are scoring the player giving the FIRST 
    // char here.
    int slap( char, char );
 
    void standings();
};

