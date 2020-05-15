#pragma once

#include "Town.h"

class Town; // needed because we refer to Town below.

class Person{
	
	private:

		Town *pTown; // pointer to this Town.  
		int base;    // number of couples in the town.
		string name; // first name of this person, no spaces
		string *likes; // array of names in order that this person likes them
		string spouse; // name of spouse, ="" if not married
		bool female; // true=female, false=male

	public:

		Person(); //sets up person's information, details in *.cpp file
        ~Person(); //clean up after program is done

		void setTheTown(Town*);//set up the pointer to pTown and set base
		void setLikes(); //populate the person's like array with members of opposite sex (random)
		void report(); //print the person and who they like
		void divorce(); // divorces a person, if married
		void marry(Person*); //marries a person if single
		bool willDo(string); // Given the name of a potential lover, this
		void setInfo(string, bool);//sets values of name, spouse, and sex
		bool checkMember(string, string *, int);//checks if element is in the array

		// ordinary setters and getters
		void setName( string n ) { name = n; }
		void setFemale( bool isf ) { female = isf; }
		void setSpouse(string s) { spouse = s; }
		string getSpouse() { return spouse; }
		string getName() { return name; }
		string *getLikes(){return likes;}//gets array of likes
		bool getGender(){ return female; }//returns gender
};