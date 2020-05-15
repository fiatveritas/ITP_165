// Bkoster.cpp
// Barrett Koster 2019

#include "Bkoster.h"


Bkoster::Bkoster( std::string n ) : Player(n)
{
}

void Bkoster::matchInit()
{
	dCount = 0;
}

char Bkoster::play( int r )
{
	//cout << "Bkoster::play: entering ... ";
	char ret = 'c';
	if (dCount > 20) { ret = 'd'; } // more than 20 defects, defect
	else if (r < 1) { ret = 'c'; } // first round, cooperate
	else { ret = yourChoices.at(r - 1); } // else tit for tat

	if (ret == 'd') { dCount++; } // count defect if it is one
	//cout << "  and leaving\n";
	return ret;
}