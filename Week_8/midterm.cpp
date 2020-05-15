#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void create_data();
void give_max(double num[], const int size); //gives the max in the array
string tempWord(double);
void swap(double &num1, double &num2, double &num3); //moves values from indicies 1 to 3, 2 to 1, 3 to 2
string remove_stuff(string); //removes 'a' and 'e' from a string
void can_do(double);
void get_mean(); //computes mean
void names(); //gets user name
bool lock_725(); //checks if a combination opens a three number lock, asks in scope
void create_lock(int lock[], const int size); //checks for correct locker combination, user passes in an array containing the combination

int main(){ //code is commented out for testing purposes
	
	srand(  (int)time(0)  );

	int const size = 10; double num[size];
	for(int j= 0; j< size; j++){num[j] = rand() ; cout << num[j] << endl;}
		give_max(num, size);
	

	create_data();

	cout << tempWord(20.0) << endl;
	
	int counter = 0;
	for(int i= 100; i< 201; i++){
		counter++;
		cout << i << " ";
		if(counter == 10)   {cout << endl; counter = 0;}
	} cout << endl;

	
	double num1 = 1.0, num2 = 2.0, num3 = 3.0;
	swap(num1, num2, num3);
	cout << num1 << "|" << num2 << "|" << num3 << endl;
	

	
	string word = "abcdefg";
	string modified = remove_stuff(word);
	cout << modified << endl;
	

	
	double age = (int)rand()%40; cout << age << endl;
	can_do(age);
	

	get_mean();

	names();


	bool result = lock_725();
	cout << result << endl;


	int const size2 = 3;
	int num4 = 7 , num5 = 2, num6 = 5;
	int combination_lock[] = {num4, num5, num6};
	create_lock(combination_lock, size2);
	//

	return 0;
}

void create_data(){ //create data from file
  string line = ""; int counter = 0; 
  ifstream myfile ("script.txt");

  if (myfile.is_open())
  {
    cout << "file opened" << endl;
    myfile >> line;
    while(!myfile.eof()){
    	//cout << "|" << line;
    	counter++;
    	if(counter % 4 == 0){cout << line << " "; counter = 0;}
    	myfile >> line;
    }
    cout << endl;
    myfile.close();
  }

  else cout << "Unable to open file"; 

}

void give_max(double num[], const int size){ //returns the max of a function
	double holder;

	for( int j= 0; j< size; j++ ){
		if(  j == 0     ){ holder = num[j]; }
		else if (  num[j] > holder  ) {  holder = num[j];   }
	}

	cout << "max: " << holder << endl;
}

string tempWord(double temp){ //returns temperature
	if(temp < 5){return "cold";}
	else if(temp >= 5 && temp < 20){return "mild";}
	else if(temp >= 20){return "hot";}
}

void swap(double &num1, double &num2, double &num3){ //swaps three values, moves shifts num1 -> num3, num2 -> num1, and num3 -> num2
	double holder = num3;

	num3 = num2;
	num2 = num1;
	num1 = holder;

}

string remove_stuff(string word){ //removes 'a' and 'e' from a string
	string holder = "";
	for(int j= 0; j< (int)word.length(); j++       ){
		if(word[j] != 'a' && word[j] != 'e'){holder += word[j];}
	}
	return holder;
}

void can_do(double age){ //computers whether someone can drive, vote, or buy alcohol
	if(age >=16){ cout << "can drive" << endl;}
	if(age >=18){ cout << "can vote" << endl;}
	if(age >=21){ cout << "can buy alcohol" << endl;}
}

void get_mean(){ //compute the average from a file of numbers
	ifstream openFile("scores.txt");
	double holder, num = 0; int counter = 0;
	if(openFile.is_open()){
		cout << "file open" << endl;
		while(!openFile.eof()){
			openFile >> holder;
			num += holder;
			counter++;
			
		}
		cout << num / counter << endl;
		openFile.close();
	}
	else{
		cout << "error! file not read." << endl;
	}
}

void names(){ //ask the user's name
	string name = "";
	while(name != "bob"){
		cout << "type name: "; 
		cin >> name;
		if(name == "bob"){cout << "hi " << name << endl; break;}}
}

bool lock_725(){ //this checks if numbers are the combination below, ask for combination in scope
	int num1, num2, num3;
	cout << "input integer: "; cin >> num1;
	cout << "input integer: "; cin >> num2;
	cout << "input integer: "; cin >> num3;

	if (num1 == 7 && num2 == 2 && num3 == 5){return 1;}
	else{return 0;}

}

void create_lock(int lock[], const int size){ //this checks if three numbers passed in are the lock combination, passed in array
	int combination_lock[] = {7, 2, 5};

	for(int j= 0; j< size; j++){if(   lock[j]  !=  combination_lock[j]    ) {cout << "False" << endl; return;}}
	cout << "True" << endl;
}