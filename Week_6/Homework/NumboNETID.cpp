// Jesse Gallegos
// ITP 165, 2020 Spring
// Homework 5

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void welcome(); //this displays a message to the user
void run_game(int); //runs the game, termination depends on user input
void human_guesses(); //this function calls the game where the human guesses
void computer_guesses(); //this funciton call the game where the computer guesses
string transform(int); //this function converts a number to a string
int hits(string, string); //this function computes how digits are a hit
int bulls(string, string); //this function computes how many digits are bullseye
bool checker(vector<char>, char element); //check if element in the vector
void filter(bool possibles[], const int, int); //filter function, idea: eliminate four repeating digits ex...1111 or 2222, 3333, etc...
void filter_2(bool possibles[], const int, int, int); //this is the final filter that gets rid repeats

int main(){
	int the_game;
	srand(time(0));	

	welcome();
	run_game(the_game);
	return 0;
}

void welcome(){
	cout << "Welcome to Numbo\n" ;
}

void run_game(int the_game){
	bool choice = true;
	do{
		cout << "1=you guess, 2=computer guesses, 0=quit : " ;
		cin >> the_game;
		if(the_game == 1){human_guesses();}
		else if(the_game == 2){computer_guesses();}
		else if(the_game == 0){
			cout << "bye" << endl;
			choice = false;
		}
	}while(choice);
}

void human_guesses(){
	int guess, winning_number = rand() % 1000,
	    num_hits = 0, num_bulls = 0, turn = 0;
	string guess_changed, winning_changed;
	winning_changed = transform(winning_number);
	cout << "human guesses" << endl;
	do{
		num_hits = 0, num_bulls = 0;
		turn++;
		cout << "Enter a guess (4 digits number): "; cin >> guess;

		guess_changed = transform(guess);
		num_bulls = bulls(guess_changed, winning_changed);

		if(num_hits == 0 && num_bulls == 4){
			cout << "hits=" << num_hits;
			cout << " bulls=" << num_bulls;
			cout << "\nyou got it in " 
			     << turn << " tries!" << endl;
			     break;
			 }

		num_hits = hits(guess_changed, winning_changed);

		cout << "hits=" << num_hits;
		cout << " bulls=" << num_bulls;
		if(turn > 12){cout << "\nyou lose\nbye";}
		cout << endl;
	}while(turn <= 12);
}

void computer_guesses(){
	const int size = 10000;
	int counter = 0, number = rand()%10000, holder,
	    master_counter = 0, number_of_hits, number_bulls; /*master_counter number of turns left
	                          counter, holder are dummy variables*/
	bool possibles[size] = {}; // this tracks the guesses set to truth as default
	vector<char> dummies={}; //hard code initial guesses, first four
	vector<int> bull_values={};
	vector<int> bull_count={};
	string stuff = "", winning_number = ""; //dummy variable for initial guesses

    for(int i=0; i<size; i++){possibles[i] = 1;}

	cout <<"Think of a 4 digit code for me to try to guess.\n"
	     << "hit ENTER when you have it ..." << endl;
	cin >> number ;
	winning_number = transform(number); 

	while(counter < 4 ){
		holder = rand()%10;
		stuff = "";
		if( !checker(dummies, holder ) ){//make sure that each random number is unique
			stuff = to_string(holder) + to_string(holder) + to_string(holder) + to_string(holder); 
			dummies.push_back(holder); //add unique numbers into array, this is checked against

			number_of_hits = hits(stuff, winning_number),
			number_bulls = bulls(stuff, winning_number);
			cout << "I guess "<< stuff << "." ;
			cout << " enter hits: " << number_of_hits << " ";
			cout << " enter bulls: " << number_bulls << " ";

			if(number_bulls == 0){filter(possibles, size, holder);}//filter out bullseyes first

			cout << endl;
			if (number_bulls > 0)
			{
				counter += number_bulls;
				bull_values.push_back(holder);
				bull_count.push_back(number_bulls);
			}
			master_counter++;
			if(number_bulls == 4){
			cout << "you got it in " << master_counter << " tries!\n";
			return;}
		}
	}

	bool check = false;
	for(int i=0; i<10; i++){
		check = false;
		for(int j=0; j< (int)bull_values.size() ; j++){
			if( i == bull_values.at(j) ){
				check = true;
			}
		}
		if(!check){filter(possibles, size, i);}
	}

	for(int i=0; i< (int)bull_values.size(); i++ ){filter_2(possibles, size, bull_values.at(i), bull_count.at(i) );}//filter by repetitions

	vector<int> final_solution = {};

	for(int i=0; i<size; i++){
		if(possibles[i] == true){
		final_solution.push_back(i); }
	}

	int guess;

	do{
		guess = rand() % (int)final_solution.size();
		number_of_hits = hits( transform( final_solution.at(guess) ) , winning_number);
		number_bulls = bulls( transform( final_solution.at(guess) ), winning_number);
		cout << "I guess " << transform(final_solution.at(guess) )<< ". ";
		cout << "enter hits: " << number_of_hits << " ";
		cout << " enter bulls: " << number_bulls << " \n";
		if(number_bulls == 4){
			cout << "you got it in " << master_counter << " tries!\n";
			return;
		}

		master_counter++;
		final_solution.erase(final_solution.begin() + guess);
	}while(master_counter < 12);

	 }

string transform(int number){//this function transforms numbers into strings
	string digits; // dummy variable, this is what gets returned and concatenated

	if(number < 10){digits = "000" + to_string(number);}
	else if(number < 100){digits = "00" + to_string(number);}
	else if(number < 1000){digits = "0" + to_string(number);}
	else if(number < 10000){digits = to_string(number);}
	else{cout << "input error!";}

	return digits;
}

int hits(string guess, string winning_number){//this function counts the number of hits
	int num_hits = 0;
	vector<char> dummy = {};

	for(int i=0; i< (int)guess.length(); i++){
		for(int j=0; j< (int)winning_number.length(); j++){
			if( guess.at(i) == winning_number.at(i) )
				break;
			if( i!= j && (guess.at(i) == winning_number.at(j) ) ){//skip if the indices match and are equal, this would be a bullseye
				num_hits++;
				break;
			}
		}
	}
	return num_hits;
}

int bulls(string guess, string winning_number){//this function computes the number of bullseyes
	int num_bulls = 0;
	for(int i=0; i< (int)guess.length(); i++){
		for(int j=0; j< (int)winning_number.length(); j++){
			if(i==j && ( guess.at(i) == winning_number.at(j) ) ){num_bulls++;}
		}
	}
	return num_bulls;
}

bool checker(vector<char> dummy, char holder){//this method is for checking if an element is a member of the vector
	if( (int)dummy.size() == 0 ){return 0;}
	else if( (int)dummy.size() > 0 ){
		for(int i=0;  i< (int)dummy.size(); i++ ){
			if(dummy.at(i) == holder){return 1;}
		}
	}
	return 0;
}

void filter(bool possibles[], const int size, int eliminate){//this filter eliminates single 
	int counter =0;
	string index ="";
	char x = eliminate + 48;//typecase by ascii
	for(int i=0; i< size; i++){
		index = transform(i);
		for(int j=0; j<  (int)index.length(); j++ ){
			if(   index.at(j)    ==  x  ){
				possibles[i] = false;
				counter++;

			 }
		}
	}
	counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (possibles[i] == 0)
			counter++;
	}
}

void filter_2(bool possibles[], const int size, int answer, int occurences){//made false values for the wrong number of bulls
	string solution = "";
	int counter = 0;
	char x;
	for(int i = 0; i< size; i++){
		counter = 0;
		solution = transform(i);
		for(int j=0; j< (int)solution.size(); j++){
			x = answer + 48;
			if(solution.at(j) == x){counter++;}
		}
		if(counter != occurences){possibles[i] = false;}
	}
}