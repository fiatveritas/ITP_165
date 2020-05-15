#pragma once

#include "Player.h"

class Bob : public Player
{
public:
    Bob( std::string );
    //~Bob();
    char play(int);
};

