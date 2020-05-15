// Jesse Gallegos
// ITP 165, 2020 spring
// Dogs

#include <iostream>
#include <ctime> 
#include <iomanip>
using namespace std;

void make_odds(int odds[], const int size);//this generates the array of 10 possibilites, 5 dogs, repeats are allowed, but each dog is in
void make_prob(int odds[], const int size, double probs[], const int num_dogs); //generates array of occurrences for each dog
void display_probabilities(double probs[], const int size);//this function displays the probabilities for a dog do win, index corresponds to i_th dog
void get_winnings(double &available, double gamble, double, bool);//this function computes earning for dog bet on
void get_gamble(double available, double &gamble, bool &stop); //thisfunction gets how much the user wants to gamble
void get_dog(int &what_dog); //dog to bet on
void player_result(int winner, int what_dog, bool &victory);//get player result; 1 for victor; 0 for loss
bool check_membership(int probs[], const int size, int candidate);//check if a candidate element is a member of the array
bool can_bet(double, double); // this function checks whether or not a gambler can place a bet based off funds left

int main(){
	srand(time(0)); cout << fixed << setprecision(2);//set a few things up for output and randomization
	const int size = 10;    int odds[size] = {}; //this sets up the odds array
	const int num_dogs = 5; double probs[num_dogs] = {};//this sets up the probabilities array
	double money = 100.00, gamble = 0.00; //money is the available amount for the game, gamble is what the user bets
	int what_dog= -1; bool victory = 1;//what_dog is the dog you're betting, victory is a boolean: 1 is win, 0 is a loss
	int winner = rand()%5; // generate if the dog won

	bool stop = true;
	do{
	stop = false;
	make_odds(odds, size);
	make_prob(odds, size, probs, num_dogs);
	display_probabilities(probs, num_dogs); cout << "You have $" << money << " available." << endl;
	get_dog(what_dog);
	get_gamble(money, gamble, stop); if(stop){break;}//get_gamble can change stop value
	player_result(winner, what_dog, victory);
	get_winnings(money, gamble, probs[winner], victory); cout << endl;
	if(money < 1) {stop = true;cout << "Not enough funds." << endl;}//check the user has money for another round
	}while(!stop);

	return 0;
}

void make_odds(int odds[], const int size){//create the odds array
	const int initial = 5; int holder[initial] = {};
	int index = 0, dummy = rand()%10 ;

	for(int i= 0; i< size; i++){odds[i] = -1;}//generates odds, needed so that computer doesn't give trash
	for(int i= 0; i< initial; i++){holder[i] = -1;}//again populate this to avoid trash, this gives my mapping for where dogs will go

	for(int i= 0; i< initial; i++){//this puts the dogs into the array at least once, guarantees uniqueness and random position
		bool repeat= false;
		do{//check for uniqueness
			dummy = rand()%10; 
			if(  !check_membership( holder, initial, dummy  ) ){//make sure each dog is assigned once, randomly
				holder[i] = dummy;
				odds[dummy] = i;  
				repeat = true;
			}   
		}while(!repeat);
		   
	}

    for(int i = 0; i< size; i++){ //this randomizes any remaining dogs into available spaces
    	if( odds[i] < 0 ) { 
    		odds[i] = rand()%5; 
    	}   
    }

}

void make_prob(int odds[], const int size, double probs[], const int num_dogs){
	int counter;//makes the occurences table
	for(int i= 0; i< num_dogs; i++){
		counter = 0;
		for(int j= 0; j< size; j++){if(  i ==  odds[j]  ){ counter++; }   }
		probs[i] = counter;
	}
}

void display_probabilities(double probs[], const int size){
	cout << fixed << setprecision(0);
	cout << "Here are the dogs you can bet on:" << endl;
	for(int i=0; i< size; i++){
		cout << "dog " << i 
		     << " prob:" << probs[i] * 10 << "\%\n";//multiply occurrences by 10
	}
}

void get_winnings(double &available, double gamble, double probability, bool victory){
	double holder;
	cout << fixed << setprecision(2);
	if(victory){//computes earning, subtract gamble from available
		available -= gamble;
		holder = gamble / (probability / 10);//compute earnings
		available += holder;//add earnings to available
		available--;//subtract the fee for gambling $1
		cout << "Your dog won!!\nYou won $" << holder
		     << " and you now have $" << available 
		     << " in your account.\n";
	}
	else{
		available -= gamble;
		cout << "Your dog lost and now you have $" 
		     << available << " in your account.\n";
	}
}

void get_gamble(double available, double &gamble, bool &stop){
	bool again = true;//determine if the gamble is within specifications

	do{
		again = true;

		cout << "Enter dollars to bet (0 to quit): ";
		cin >> gamble;

		if(gamble < 1 && gamble > 0){//user needs funds greater than 1
			cout << "Your bet must be greater than $1.00" << endl; 
			again = false;
		}
		else if(gamble > available){//make sure the sure has enough money to gamble
			cout << "You cannot bet more than you have." << endl;
			again = false;
		}
		else if (gamble == 0){again = true; stop = true;}

	}while(!again);

}

void get_dog(int &what_dog){//make sure the dog is in the correct range
	cout << "Pick a dog: ";
	cin >> what_dog;
	while(  !( what_dog >= 0 && what_dog <=5 )  ){
		cout << "Must be in the range 0 to 5. Try again." << endl;
		cout << "Pick a dog: ";
		cin >> what_dog;
	}
}

void player_result(int winner, int what_dog, bool &victory){//generate win or loss, 1 or 0
	if(winner == what_dog){victory = 1;}
	else{victory = 0;}
}

bool check_membership(int probs[], const int size, int candidate){//check if a dog is uniquely placed once
	for(int i= 0; i< size; i++){
		if(  probs[i] == candidate  ){
			return 1;
		}  
	}

	return 0;
}

bool can_bet(double available, double gamble){//determines if you can keep betting
	if(gamble <= available){return 1;}
	else{return 0;}
	return 0;
}