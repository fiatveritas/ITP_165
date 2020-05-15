#include "Randy.h"

Randy::Randy( std::string n) : Player(n)
{

}


//Randy::~Randy()  {}


char Randy::play( int r )
{
    char p = 'c';
    if ( r==0 ) { p = 'c'; }
    else { p = yourChoices[r-1]; }
    return p;
}
