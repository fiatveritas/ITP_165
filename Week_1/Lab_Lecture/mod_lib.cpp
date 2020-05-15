#include <iostream>
#include <string>
using namespace std;

int main(){
	string animal, place, thing;
	int number;

	cout << "Enter a type of animal: " << endl;
	cin >> animal;

	cout << "Enter a place name: " << endl;
	cin >> place;

	cout << "Enter a number (integer): " << endl;
	cin >> number;

	cout << "Enter a type of thing: " << endl;
	cin >> thing;

	cout << "There once was a " << animal 
	     << " who lived in " << place 
	     << ".\nThe " << animal << " made and shared " 
	     << number * 9000 << " copies of a "<< thing 
	     << "\nwhich made everyone in " << place 
	     << " happy." << endl; 
	return 0;
}