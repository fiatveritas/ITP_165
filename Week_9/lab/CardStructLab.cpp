// CardStructLab.cpp 
// This lab has the programmer create a struct named Card
// and then makes a deck of cards using it

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const string suits[] = {"spades","hearts","diamonds","clubs"};
const string values[] = {"ace","2","3","4","5","6","7","8","9",
                            "10","jack","queen","king"};


// struct Card represents a playing card, so has two 
// parts the suit and the value, both strings
struct Card{
  string s;
  string v;

};


// prototypes
Card makeCard( int s, int v );
int userPick();

int main()
{
   // welcome to the program
    cout <<"Card Struct Lab\n";

   // declare an array of 52 Cards, call it deck.
   const int size = 52;
   Card deck[size];

   // run double nested loop on suit and value to fill
   // up a deck of cards with 4 suits x 13 values each.
    for ( int s=0; s<4; s++ )
    {
        for ( int v=0; v<13; v++ )
        {
            deck[13*s+v] = makeCard(s,v);
        }
    }

    // let the user pick a number from 0-51 (or -1 to quit)
    // and show the Card at that index in the deck.
    int i;
    while ( (i=userPick()) >= 0 )
    {
       // show the ith card in the deck
       cout << "card " << i << " is "
            << deck[i].v << " of " << deck[i].s <<  endl;

    }
    
    cout <<"bye" <<endl;

    return 0;
}

// ask user to pick card inex (0-51), returns the int
// -1 also allowed, that's the quit signal
int userPick()
{
    int n=-1;
    do
    {
        cout <<"enter card number (0-51, -1 to quit):\n";
        cin >>n;
    }
    while (n<-1 || n>51 );
    return n;
}

// make a Card struct using suits[s] and values[v]
// from the constant lists at the top of the program.
// Return the Card.  Note: there is no erro checking
// here, be careful.
Card makeCard( int s, int v )
{
    Card c;

   // assign the two parts of c values from suit[] 
   // and values[].
   c.s = suits[s];
   c.v = values[v];

    return c;
}
