// Player.cpp : 
//

//#include "stdafx.h"
#include <iostream>
#include "Player.h"

// comstructor, pass in the name of the Player
Player::Player( std::string n )
{
    name = n;
	rank = 0;
	rankSum = 0;
}

/*
Player::~Player()
{
    cout <<"Player " <<name <<" destruction.\n";
}
*/

// clears the match record for the next match
const void Player::rinit()
{
	myChoices.clear();
	yourChoices.clear();
}

//virtual char Player::play( int r );
//{
//    return 'c';
//}

// puts the opposing player's play into the vector
// that stores them (yourChoices).  
const void Player::record( int r, char x )
{
    //yourChoices[r] = x;
    yourChoices.push_back(x);
}

const void Player::addToScore( int x )
{
    score += x;
}

int Player::report()
{
    std::cout <<"player " <<name <<" scored " <<score 
		<<" rank=" <<rank 
		<<" rankSum=" <<rankSum
		<<".\n";
    return score;
}

