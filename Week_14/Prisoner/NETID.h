#pragma once

#include <ctime>//need this for randomization output
#include "Player.h"

class NETID : public Player
{
protected:
	int dCount=0; // number of defects from opponent, not necessary. just a dummy for a virtual function...
public:
    NETID( std::string );
    //~NETID();
    char play(int);
	void matchInit();
};
