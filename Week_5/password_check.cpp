#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isValidPW(string password);

int main(){
	string stuff;
	do{
	cout << "Enter password for validity check:" << endl
	     << "Checking validity..." << endl;
	cin.ignore();
	getline(cin, stuff);

	if(isValidPW(stuff)){cout << "Password is valid" << endl;}
	else{cout << "Password invalid!" << endl << endl;}
	}while(!isValidPW(stuff));
	return 0;
}

bool isValidPW(string password){
	int caps = 0, digits = 0, spaces = 0;
	for(char i = 'A'; i<= 'Z'; i++){
		for(int j = 0; j < (int)(password.size()); j++){
			if(i == password.at(j)){caps++;}
			if(caps >=3 ){break;}
		}
	}
	for(int k = 0; k <= 9; k++){
		for(int j = 0; j < (int)(password.size()); j++){
			if(isdigit(password.at(j))){digits++;}
			if(digits >= 2){break;}
		}
	}
	for(int j = 0; j< (int)(password.size()); j++ ){ if(isspace(password.at(j))){spaces++; break;} }
	if(caps >=3 && digits >= 2 && spaces == 0){return 1;}
	else{return 0;}
}
