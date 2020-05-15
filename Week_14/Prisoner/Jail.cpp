// Jail.cpp
// This is the driver class for the prisoner's dilemma game.
// Barrett Koster 2018-


#include <iostream>
#include <string>
#include <ctime>

#include "Bob.h"
#include "Sue.h"
#include "Tiff.h"
#include "Bkoster.h"
#include "Randy.h"
#include "NETID.h"

#include "Jail.h"


// create the Jail and run the tournament.
int main()
{
    cout <<"program starting \n";
    Jail* theJail = new Jail();
    theJail->tourney();
  
    delete theJail;
}

// This lets you play everyone against everyone a bunch of
// times, then shows the score board.  You can then pick
// how many to cut off the bottom and do it again.
// cut==0 quits.
void Jail::tourney()
{
	bool keepGoing = true;
	int clip;
	while (keepGoing)
	{
		//theJail->run();
		bunches();
		sortr();
		standings();
		cout << "How many to delete before rerun? ";
		cin >> clip;
		if (clip == 0) { keepGoing = false;  }
		for (int i = 0; i < clip; i++) { players.pop_back(); }
	}
}


// run() (everyone vs. everyone once)  5 times.
// For each of the 5, sort them, assign rank, 
// and sum the ranks across the 5.
void Jail::bunches()
{
	int times = 5;
	//cout << "how many bunches? : ";
	//cin >> times;
	for (Player* it : players) { it->clearRankSum();  }
	for (int i = 0; i < times; i++)
	{
		//for (auto it : players) { it->setScore(0); }
		run(); // now starts all scores at 0
		sort();
		int r = 0;
		for (auto it : players) { it->setRank(r++); }
	}
}

// add tothe players vector all of the Player objects
// in the tournament.
Jail::Jail()
{
    cout <<"Prisoner's Dilemma tournament\n\n";

	
	players.push_back(new Bob("mean1"));
	players.push_back(new Sue("nice1"));
	players.push_back(new Tiff("tiff1"));
	players.push_back(new Bkoster("bar1"));
	players.push_back(new Randy("randy1"));
	players.push_back(new Bob("mean2"));
	players.push_back(new Sue("nice2"));
	players.push_back(new Tiff("tiff2"));
	players.push_back(new Bkoster("bar2"));
	players.push_back(new Randy("randy2"));
	players.push_back(new NETID("jesse_1"));
	

    srand((int)(time(0)));
}

// put the vector of Players in random order, then
// play each one against each other, once.  
// Each player gets an accumulated score from all
// opponents.  
int Jail::run()
{
    int ROUNDS = 200 + rand()%5; // slightly random so you can't game
	                             // the end
	shuffle();
	for (auto it : players) { it->setScore(0); }

    int playerCount = (int)(players.size());
    for ( int i=0; i<playerCount-1; i++ )
    {
        for ( int j=i+1; j<playerCount; j++ )
        {
            Player *p0 = players[i];
            Player *p1 = players[j];

            pit( p0, p1, ROUNDS );
        }
    }

    return 0;
}

// put players vector in order of score
void Jail::sort()
{
	int playerCount = (int)(players.size());

	for (int i = 0; i < playerCount - 1; i++)
	{
		for (int j = i + 1; j < playerCount; j++)
		{
			if (players[i]->getScore() < players[j]->getScore())
			{
				Player* temp = players[i];
				players[i] = players[j];
				players[j] = temp;
			}
		}
	}
}

// put players vector in order of rankSum
void Jail::sortr()
{
	int playerCount = (int)(players.size());

	for (int i = 0; i < playerCount - 1; i++)
	{
		for (int j = i + 1; j < playerCount; j++)
		{
			if (players[i]->getRankSum() > players[j]->getRankSum())
			{
				Player* temp = players[i];
				players[i] = players[j];
				players[j] = temp;
			}
		}
	}
}

// randomize the order of players
void Jail::shuffle()
{
	int playerCount = (int)(players.size());

	for (int i = 0; i < playerCount; i++)
	{
		int j = rand() % playerCount;
		if (j!=i)
		{
			Player* temp = players[i];
			players[i] = players[j];
			players[j] = temp;
		}
	}
}

// put the two players against each other for 200+ rounds.
// We score and record what each player plays.
void Jail::pit( Player* p0, Player* p1, int ROUNDS )
{
    //cout <<"pitting " <<p0->getName() <<" against " 
    //   <<p1->getName() <<endl;

	p0->rinit(); // Player init, can't be changed by student
	p1->rinit();
	p0->matchInit(); // your init, whatever you need to do
	p1->matchInit();

    for( int r=0; r<ROUNDS; r++ )
    {
		char c0 = padded(p0, r); //  p0->play(r);
		char c1 = padded(p1, r); //  p1->play(r);

        if ( rand()%20 == 0 ) { c0 = 'd';}
        if ( rand()%20 == 0 ) { c1 = 'd';}

        p0->record( r, c1 );
        p1->record( r, c0 );

        p0->addToScore( slap( c0, c1 ) );
        p1->addToScore( slap( c1, c0 ) );
    }

}


// this gets a single play out of a player objects.  
// student code here can be buggy, so it's in a try-catch
// block to try to handle problems.  If your code geeks,
// we play 'c' for you.  
char Jail::padded(Player* p, int r)
{
	//cout << "entering padded for " << p->getName() << endl;
	char c;
	try { c = p->play(r); }
	catch (...)
	{
		cout << "error in play from " << p->getName() << endl;
		c = 'c';
	}
	return c;
}

// this function computes how many points go to the 
// first player here, the giver of 'my'.  It should be
// the same as the table in the writeup.
int Jail::slap( char my, char your )
{
    int ret=0;

    if ( my=='c' && your =='c' ) { ret = 5; }
    else if ( my=='c' && your =='d' ) { ret = 0; }
    else if ( my=='d' && your =='c' ) { ret = 6; }
    else if ( my=='d' && your =='d' ) { ret = 2; }

    return ret;
}

// prints out the score board.  If you want it sorted,
// do that before you call this.
void Jail::standings()
{
	int playerCount = (int)(players.size());

	cout << "\n\nstandings:\n";
	//sort();   

    for ( int i=0; i<playerCount; i++ )
    {
		cout << (i+1) << ": ";
        players[i]->report();
    }
	cout << "That's the score for " << playerCount << " players.\n";
}

// de-allocate all of the Player objects.
Jail::~Jail()
{
    for ( auto p : players )
    {
        delete p;
    }
}


