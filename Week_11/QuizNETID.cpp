// Jesse Gallegos
// ITP 165, 2020 spring
// Homework 08

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

struct QAPair{
	string question;
	string answer;
	bool gotit= 0; // 1 if user gets correct answer, otherwise 0 (by default)
};

void get_file(string &file_name, QAPair flash_cards[], const int SIZE, int &index, bool &opens);//this function opens the file and creates the flash_cards
QAPair make_card(string question, string answer);//this function makes a flashcard
void verity(bool &gotit, string question, string answer, string guess);//this function checks if the guess is the correct answer
void take_quiz(int index, QAPair flash_cards[], const int SIZE, string &guess);//this runs the quiz to start, after creating the flashcards
bool member(int num, int array[], const int SIZE);//this method checks if an element is a member of the array
void random_array(int random_list[], const int SIZE);//this method makes a random array
int score(QAPair flash_cards[], const int SIZE);//this computes the number of correct questions

int main(){
	srand(  time(0)  );
	const int SIZE= 200; QAPair flash_cards[SIZE]; //makes flashcards of fixed size
	string file_name= ""; int index= 0, correct= 0;//index counts space occupied by data
	string guess= "";//holder for user input
	bool opens= 0;//checks if file opens

	get_file(file_name, flash_cards, SIZE, index, opens);//opens and parses file.
	do{take_quiz(index, flash_cards, SIZE, guess);
	correct = score(flash_cards, index);}while(  correct < index && guess != "quit"  );
	if(opens){cout << "you got " << correct << " of " << index << endl;}

	return 0;
}

void get_file(string &file_name, QAPair flash_cards[], const int SIZE, int &index, bool &opens){
	cout << "Enter file name of quiz data: "; cin >> file_name; //file_name= "StateCapitals2.txt";
	ifstream quiz_file(file_name);
	string question= "", answer= "";

	if(  quiz_file.is_open()  ){
		cout << "file opened.\n"; opens= 1;
		getline(quiz_file, question, ',');
		getline(quiz_file, answer);
		cout << "Questions are " << question << " and answers are " << answer << ". \'quit\' to end." << endl;
		while( !quiz_file.eof() ){
			getline(quiz_file, question, ',');//this line splits the line and assigns the first word to question
			getline(quiz_file, answer);//this line gets the remaining and assigns it to answer
			flash_cards[index] = make_card(question, answer);//this makes the flashcards
			index++;//this number records the number of records in the database, important because this is the loop limit
		}
		quiz_file.close();
	}
	else{cout << "error opening file!\n";}
}

QAPair make_card(string q, string a){
	QAPair card;
	card.question = q;
	card.answer = a;
	return card;
}

void verity(bool &gotit, string question, string answer, string guess){
	if(answer == guess){gotit= 1; cout << "correct!\n";}//this updates 
	else{gotit= 0; cout << "oops, correct is " << answer << ".\n";}
}

void take_quiz(int index, QAPair flash_cards[], const int SIZE, string &guess){
	int seen[index]={}, random_list[index]= {};
	for(int j= 0; j<index; j++){seen[j]= -1;}//hard code array to all -1
	for(int j= 0; j<index; j++){random_list[j]= -1;}//ditto from line above
	random_array(random_list, index);
    for(int j=0; j< index; j++){
    	if( !flash_cards[ random_list[j] ].gotit )
    	{  cout << flash_cards[ random_list[j] ].question << " ? : "; cin >> guess;
           if(  guess == "quit"  ){return;}//end function if user types quit
           verity(flash_cards[ random_list[j] ].gotit, flash_cards[ random_list[j] ].question, flash_cards[ random_list[j] ].answer, guess);//checks if answer is correct
        }  
    	}

    //cout << endl;

}

bool member(int num, int array[], const int SIZE){//this function checks if a randomized number is in the array
	for(int j= 0; j< SIZE; j++){
		if( num == array[j] ){return 1;}
	}
	return 0;
}

void random_array(int random_list[], const int SIZE){//this array creates a randomized array to iterate over for the quiz, the quiz follows this order
	int num = -1;
	for(int j= 0; j< SIZE; j++){
		num = rand()% SIZE;
		while(  member(num, random_list, SIZE)  ){num= rand()% SIZE;}//while loop keeps running until it hits an unseen number
		random_list[j]= num;
	}
}

int score(QAPair flash_cards[], const int SIZE){
	int correct= 0;
	for(int j=0; j< SIZE; j++){
		if(  flash_cards[j].gotit > 0  ) {correct++;}//conditional only counts true values
	}
	return correct;
}