#pragma once

#include <string>
#include <vector>
using namespace std;

//const int ROUNDS = 200;

class Player
{
protected:
    vector<char> myChoices; // 'c' or 'd' for as many rounds as there
    vector<char> yourChoices; // have been played so far
	// note: the start code keeps track of yourChoices, but if you 
	// want to keep myChoices, you have to do it yourself.

    //int score = 0;
    std::string name;
private:
	int rank; // 0 is best, 1, 2 ... 
	int rankSum; // sums rank for 5 runs, so low is still good.

	int score = 0; // this score accumulates over all other players,
	               // so do not reset at the start of a set of 200.



public:
       Player( std::string );
       //virtual ~Player();

    // given the round number, returns 'c' or 'd'
    virtual char play( int )=0;

	// called before the 200 rounds with each player
	// Students should use this to initialize whatever 
	// at the start of playing an opponent.
	virtual void matchInit(){}

	const void rinit(); // is called before each player plays another player
			  // for 200 rounds.  It clears out old records of
			  // previous choices.


    // record what the other player played, given round number
    // and their character 'c' or 'd'
    const void record( int , char );

    int report();

    const void addToScore( int );
    string getName() { return name; }
    const int getScore() { return score; } 
	const int getRank() { return rank; }
	const void setRank(int r) { rank = r; rankSum += r; }
	const void clearRankSum() {  rankSum = 0; }
	const int getRankSum() { return rankSum;  }
	const void setScore(int s) { score = s; }


};
