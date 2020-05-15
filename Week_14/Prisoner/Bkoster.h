#pragma once

#include "Player.h"

class Bkoster : public Player
{
protected:
	int dCount=0; // number of defects from opponent
public:
    Bkoster( std::string );
    //~Bkoster();
    char play(int);
	void matchInit();
};
