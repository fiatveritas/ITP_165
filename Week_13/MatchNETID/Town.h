#pragma once

#include "Person.h"

class Person; // needed because we refer to Person below

class Town{
	
	private:

		int base; // number of couples in the town
		Person *men; //array of men in town
		Person *women; //array of women in town
	public:

		Town(int); //sets ups the variables
		~Town(); // destructor.  Deallocate men[] and women[].

		void report(); // Prints out the people in town and array of who they like
		Person *findPerson( string n); //finds a person and return the pointer to the person	
		bool stable(); // return true iff everyone is married and no cheating!

		// ordinary getters 
		int getBase() { return base; }
		Person *getMen(){ return men; }
		Person *getWomen() { return women; }
};