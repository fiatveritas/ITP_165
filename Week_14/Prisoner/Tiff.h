#pragma once

#include "Player.h"
#include <iostream>
using namespace std;

class Tiff : public Player
{
public:
    Tiff( std::string );
   // ~Tiff();
    char play(int);
	void matchInit()
	{
		//cout << "Tiff::matchInit(): starting ... \n"; 
	}
};

