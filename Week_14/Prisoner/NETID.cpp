// Jesse Gallegos
// ITP 165, 2020 spring
// Prisoner's Dilemma


#include "NETID.h"

NETID::NETID( std::string n ) : Player(n)
{
}

void NETID::matchInit()
{
	dCount = 0;//dummy variable, needed to avoid abstract class. 
}

char NETID::play( int r )
{
	//this a random player. it will get lucky ...
	char ret = 'a'; //intial character to avoid junk
    int num= rand()% 2;
    if(num== 0){ret='c';}
    else{ret= 'd';}
	return ret;
}