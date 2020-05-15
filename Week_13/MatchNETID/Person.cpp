#include <iostream>
#include <ctime>
using namespace std;

#include "Person.h"
#include "Town.h"

Person::Person(){//sets up person's information, details in *.cpp file
	Town *pTown= nullptr; // pointer to this Town.  
	int base= -1;    // number of couples in the town.
	string name= ""; // first name of this person, no spaces
	string *likes= nullptr; // array of names in order that this person likes them
	string spouse= ""; // name of spouse, ="" if not married
	bool female= false; // true=female, false=male
}

Person::~Person(){//clean up after program is done
	delete pTown; 
	delete []likes;
} 

void Person::setTheTown( Town *pt ){//set up the pointer to pTown and set base 
	pTown= pt;
	base= pTown->getBase();
	return;
} 

void Person::setLikes(){//populate the person's like array with members of opposite sex (random)
	likes = new string[base]; for(int j= 0; j< base; j++){  likes[j]= "";}
	if(  female == true  ){//activates if females
	    Person *temp_men= pTown->getMen();
		int dummy= rand()%base;

		for(int j=0; j< base; j++){//check if each member of like is in and randomize
			while(  !checkMember(  temp_men[j].getName(), likes, base  )  ){
				if(  likes[dummy] == "" ){  likes[dummy]= temp_men[j].getName(); dummy=rand()%base; break;}
				else{dummy=rand()%base;}
			}
		}
		temp_men= nullptr;
		delete temp_men;
	} 
	else if(  female == false  ){//activates if males
	    Person *temp_women= pTown->getWomen();
		int dummy= rand()%base;

		for(int j=0; j< base; j++){//randomize members of like
			while(  !checkMember(  temp_women[j].getName(), likes, base  )  ){
				if(  likes[dummy] == "" ){  likes[dummy]= temp_women[j].getName(); dummy=rand()%base; break;}
				else{dummy=rand()%base;}
			}
		}
		temp_women= nullptr;
		delete temp_women;
	}
	return;
}

void Person::report(){//print the person and who they like
	if(spouse != ""){cout << "\t";}	cout << name << " likes ";
	for(int j= 0; j< base; j++){if(spouse == likes[j]){cout << "*";} cout << likes[j] << " ";}
	cout << endl;
	return;
} 

void Person::divorce(){// divorces a person, if married
	Person *dummy= nullptr;
	if( spouse!= ""){//divorce if married
		dummy= pTown->findPerson(spouse);
		dummy->setSpouse("");
		spouse= "";
		}
	//else{cout << name << " is single!" << endl; return; dummy= nullptr; delete dummy;}
	dummy= nullptr;
	delete dummy;
	return;
}
void Person::marry(Person *partner){//marries a person if single
    if(  spouse == ""  ){//marry if single
	partner->setSpouse(name);
	spouse= partner->getName();
	}
	//else{cout << name << " is already married!"; cout<< endl;}
	return;
}

bool Person::willDo(string n){// Given the name of a potential lover, this
    int c_spouse_rank= -1, c_lover_ranks= -1;//for the object calling the function
	int o_spouse_ranks= -1, o_lover_ranks= -1;//for the party passed in
    bool caller_cheats= false, partner_cheats= false;
	Person *holder= pTown->findPerson(n);
	string *partner_likes= nullptr; 
	partner_likes= holder->getLikes();

    if(  spouse == ""  ){caller_cheats= true;} //if single, will sleep with the person

	for(int j= 0; j< base; j++){  
		if(  n == likes[j]  ){  c_lover_ranks= j;  }//get potential lover's rank
	    if(  spouse == likes[j]  ){  c_spouse_rank= j;  }//get spouse's rank
		if(  name == partner_likes[j]  ){  o_lover_ranks= j;  }//get how lover ranks person of interest(caller)
		if(  holder->getSpouse() == partner_likes[j]  ){  o_spouse_ranks= j;  }//gets potential lover's spouse rank
	}

	if(  (  spouse != ""  ) && (  c_lover_ranks < c_spouse_rank  )  ){  caller_cheats= true;  }//checks if single and compares ranks, caller
    if(  (  holder->getSpouse() != ""  ) && (  o_lover_ranks < o_spouse_ranks  )  ){  partner_cheats= true;  }//determines if potential lover will cheat on spouse
    
	partner_likes= nullptr; holder= nullptr;
	delete partner_likes; delete holder;
	if(  (  caller_cheats == true  ) && (  partner_cheats == true  )  ){  return true;  }//check if both individual will cheat
	return false;
}

void Person::setInfo(string uname, bool ufemale){//sets name and gender
	name = uname;
	female= ufemale;
	return;
	}

bool Person::checkMember(string word, string *array, int base){//checks if a name is a member of the random likes array
	for(  int j= 0; j< base; j++){  if(  word == array[j]  ){return 1;}  }
	return 0;
	}