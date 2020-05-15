// Jesse Gallegos
// ITP 165, 2020 spring 
// Stable Marriage solver 

#include <iostream>
#include <ctime>
using namespace std;

#include "Person.h"
#include "Town.h"

void test_data_1(Town*, Person*, Person*, int);//I kept this native to this program, it's a choice...
void run();//this i kept in this file for demonstrations reasons...

int main(){
	srand( time(0) ); bool again= false; 
	string choice= "";
	while( again != true ){ 
		run(); 
		cout << "====================" << endl;
	    cout << "match again? \'q\' to quit ";
		cin >> choice;
		if(  choice== "q" || choice== "Q"  ){ again= true; }	
	}
	return 0;
}

void test_data_1(Town *utown, Person *umen, Person *uwomen, int base){//this is hardcoded data per project specs
	string data_men[]= {"Adam", "Bart", "Charlie"}; bool female= false;
	for(  int i= 0; i< base; i++  ){  umen[i].setInfo(data_men[i], female);  }

	string data_women[]= {"Ariel", "Belle", "Cher"}; female= true;
	for(  int i= 0; i< base; i++  ){  uwomen[i].setInfo(data_women[i], female);  }

	//setting according to sample output from specs sheet
	//Adam married to Ariel
	Person *man= nullptr; Person *woman= nullptr;
	man= utown->findPerson("Adam") ; woman= utown->findPerson("Ariel");
	man->marry(woman);
    //Bart married to Belle
    man= utown->findPerson("Bart"); woman= utown->findPerson("Belle");
	man->marry(woman);
	//Bart married to Belle
	man= utown->findPerson("Charlie"); woman= utown->findPerson("Cher");
	woman->marry(man);

    man= nullptr; woman= nullptr;
	delete man; delete woman;
	return;
}

void run(){
	int base= -1; bool done= false;
	Person *men= nullptr, *women= nullptr;//this points to array of men or women
	Person *man= nullptr, *woman= nullptr;//this points to a member of either men or women respectively

	cout << "Welcome to the Stable Marriage solver." << endl;
	cout << "Enter number of couple: "; /*cin >> base;*/ base= 3; //base is arbitrary, hard coded for testing
	
	Town *jersey_shore= new Town(base);
	cout << jersey_shore->getBase() << endl << endl;

	men= jersey_shore->getMen(); for(int j=0; j< base; j++){  men[j].setTheTown(jersey_shore);  };
	women= jersey_shore->getWomen(); for(int j=0; j< base; j++){  women[j].setTheTown(jersey_shore);  };
    	
	test_data_1(jersey_shore, men, women, base);//this sets up the arrays with men and women respectively
	
	for(int i= 0; i< base; i++ ){men[i].setLikes();} //this randomizes what man likes what woman
	for(int i= 0; i< base; i++ ){women[i].setLikes();} //this randomizes what woman what man
	
	//setting according to sample output from specs sheet
	jersey_shore->report();

    string gal= "", guy= ""; bool correct= false;//dummy variables for loops below
    while( !jersey_shore->stable() ){

		while(!correct){//pester the user for correct input, this nested loop is a necessary evil 
			cout << "Enter 2 names to marry, women first: "; cin >> gal; cin >> guy;
			woman= jersey_shore->findPerson(gal); man= jersey_shore->findPerson(guy);
			
			if(  (  woman != nullptr  ) && (  man != nullptr  )  ){//check if poiters are empty
				if(  (woman->getGender() == 1) && (man->getGender() == 0)  ){correct= true;}//check that gender is different
				else{cout << "input error!" << endl; continue;}
			}
			else{ continue;}
			
		}
		correct= false;
		woman->marry(man); cout << endl;
		jersey_shore->report();
	}
	man= nullptr, woman= nullptr; delete man, delete woman;//deltes single pointer
	men= nullptr; women= nullptr; delete men, delete women;
	jersey_shore= nullptr; delete jersey_shore;//deletes pointer to town
	return;
}