#include <iostream>
using namespace std;

#include "person.h"

Person::Person(){
	first= "N/A"; last= "N/A";
	height= -1.0; weight= -1.0;
	age= -1;
}
Person::Person(int uage, double uheight, double uweight, string ufirst, string ulast){
	first= ufirst; last= ulast;
	height= uheight; weight= uweight;
	age= uage;
}

void Person::setAge(int uage){age= uage;}
void Person::setHeight(double uheight){height= uheight;}
void Person::setWeight(double uweight){weight= uweight;}
void Person::setFirst(string ufirst){first= ufirst;}
void Person::setLast(string ulast){last= ulast;}
void Person::printInfo() const{
	cout << "Name: " << first << " " << last << endl;
	cout << "Age: " << age << endl;
	cout << "Height: " << height << "in" << endl;
	cout << "Weight: " << weight << "lbs" <<endl;
	return;}