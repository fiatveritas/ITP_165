#include <iostream>
using namespace std;

#include "Town.h"
#include "Person.h"

Town::Town(int num){
	base= num;// number of couples in the town
	men= new Person[base]; //array of men in town
	women= new Person[base]; //array of women in town
}

Town::~Town(){// cleans up after the program is done
	delete []men; 
	delete []women;
} 

void Town::report(){//this function prints information about a person's name and their likes preference
    cout << "Here are the Town People:"<< endl;
	for(int i= 0; i< base; i++ ){men[i].report();} 
	for(int i= 0; i< base; i++ ){women[i].report();}
	return;
}

Person *Town::findPerson( string n){//finds a person in town of name n
	Person *holder= nullptr;
	for(int j= 0; j< base; j++){  if(  n == men[j].getName()  ){  holder= &(men[j]); return holder;  }  }//set address of person and return
	for(int j= 0; j< base; j++){  if(  n == women[j].getName()  ){  holder= &(women[j]); return holder;  }  }//same as above if not found above
	cout << "error: " << n << " not in Town!" << endl;
	return nullptr;
}
	
bool Town::stable(){//checks for cheaters and divorces them upon finding the first set of cheaters!
	bool is_married= true, cheating= false;
	Person *copy_men= men, *copy_women= women;
	for( int j= 0; j< base; j++ ){  if(  men[j].getSpouse() == ""  ){  is_married= false;  }  }
    for( int j= 0; j< base; j++ ){
		for( int i= 0; i< base; i++ ){
			if(  copy_men[j].willDo(  copy_women[i].getName()  )  ){  
				cout << "!!! " << copy_men[j].getName() << " cheats with " << copy_women[i].getName() << endl;
				men[j].divorce();//immediately divorce cheating man
				if(  women[i].getSpouse() != ""  ){  women[i].divorce();  }//divorce cheating woman, checks if already divorced by previous line. important for base > 3
				cheating= true; 
				copy_men= nullptr; copy_women= nullptr; 
				delete copy_men; delete copy_women; 
				return false;
			}  
		}
	}
	if(  (  is_married  == true  ) && (  cheating == false  )  ){//everyone married and happily married
		cout << "Everyone is happily married." << endl;
		copy_men= nullptr; copy_women= nullptr; 
		delete copy_men; delete copy_women; 
		return true;  
	}
	else{//false otherwise, just in case
		copy_men= nullptr; copy_women= nullptr; 
		delete copy_men; delete copy_women; 
		return false;
	}
} 