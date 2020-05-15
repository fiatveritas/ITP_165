#pragma once

#include "Player.h"

class Randy : public Player
{
public:
    Randy( std::string );
    //~Randy();
    char play(int);
};

