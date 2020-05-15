#include "Tiff.h"

Tiff::Tiff( std::string n) : Player(n)
{
  
}


//Tiff::~Tiff() {}


char Tiff::play( int r )
{
    char p = 'c';
    if ( r==0 ) { p = 'c'; }
    else { p = yourChoices[r-1]; }
    return p;
}
