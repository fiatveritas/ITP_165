// Jesse Gallegos
// ITP 165, 2020 spring
// Gloss

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;

struct Word{//this structure has the word with its attributes
	string da_word= ""; // this word is from the data_file
	double standard_frequency= -1.0; // ranges from 0 - 1, this is from the data_file
	int count= 0; // number of times da_word is in a document
	double ratio= -1.0; // count/standard_frequency
	bool printed= 0; // 1 if already printed to screen. By default 0.
};

void parse_file(bool &more);//this function checks if a file opens
Word *open_dictionary(int &unique_words);//this function opens the dictionary
string clean_up(string);//this file cleans up words
string punctuation(string);//this function gets rid of punctuation
string numbers(string);//this function removes numbers from string
string remove_caps(string);//this function removes words with capital letters
bool is_caps(string);//this checks if a string has caps, return 1 if true.
void op_file(string, string);//this creates a modified output file per specs. this will be used for word counting
void run_output(Word *example, string, int index);//this funtion loads the output file
int *top(Word *example, int);//this function returns the top 25
void swap(Word *example, int non_sorted[], int SIZE);//this is gives a bubble sorted array
void display(Word *example, int sorted[], int SIZE);//display top 25 words

int main(){
	bool more= 0;//this allows the loop to start, it is modified inside parse_file()
	
	while(!more){  parse_file(more);  }
	
	return 0;
}

void parse_file(bool &more){
	string file_name= "";//the user inputs this name
	int unique_words= -1; string op_name= "out.txt"; //out.txt is file produced that has modified strings

	cout << "enter filename to do gloss ('quit' to quit): ";
	cin >> file_name;
	ifstream data_file(file_name); if(file_name == "quit"){more= 1; return;}
	if(  data_file.is_open()  ){
		cout << "file opened!\n";
		op_file(file_name, op_name);
		Word *All_words = open_dictionary(unique_words); //need unique words to run loop, this line creates the words
		for(int i=0; i< unique_words; i++){  run_output(All_words, op_name, i);  }//this line counts words from user-typed file name
		int *top_25= top(All_words, unique_words); int const SIZE= 25;
	    display(All_words, top_25, SIZE);//this displays the top 25 words
		delete[] All_words; delete[] top_25;
	    All_words = nullptr; top_25= nullptr;remove("out.txt");
		data_file.close();
	}
	else{cout << "not a valid filename!\n";}

}

Word *open_dictionary(int &unique_words){
	ifstream dictionary("DictAnd.txt"); unique_words= -1;
	string holder= ""; double frequency= -1.0;
	
	if(  dictionary.is_open()  ){
		dictionary >> unique_words;//this line gets the total number of lines of the dict file
		Word *All_words = new Word[unique_words]; int i= 0; 

		while(  !dictionary.eof()  ){
			dictionary >> frequency; dictionary >> holder ;//the format is nice in dict file. cin >> double & cin >> string
            All_words[i].da_word= holder;
            All_words[i].standard_frequency= frequency;
            i++; if(i == unique_words){break;}//check if out of bond...avoid segfault
		}
		dictionary.close();
		return All_words;
	}
	else{cout << "error!\n"; return nullptr; }
}

string clean_up(string sentence){//this function run all the cleaning needed for the assignment
	string dummy="";
	
	//cout << sentence << endl;
	dummy= punctuation(sentence); //cout << dummy << endl; //this removes punctuation
	dummy= numbers(dummy); //cout << dummy << endl; //this removes numbers
	dummy= remove_caps(dummy); //cout<< dummy << endl; //this removes words with caps

	return dummy;
}

string punctuation(string sentence){//this function removes punctuation
	string dummy= "";
	for(  int j= 0; j< (int)sentence.length(); j++  ){
		if(  !ispunct(  sentence.at(j)  )  ){dummy.push_back(  sentence.at(j)  );}
		else{dummy.push_back(  ' '  );}
	}
	return dummy;
}

string numbers(string sentence){//function removes numbers
	string dummy= "";
	for(  int j= 0; j< (int)sentence.length(); j++  ){
		if(  !isdigit(  sentence.at(j)  )  ){dummy.push_back(  sentence.at(j)  );}
		else{dummy.push_back(  ' '  );}
	}
	return dummy;
}

string remove_caps(string sentence){
	string dummy= "", temp= "";
	for(  int j= 0; j< (int)sentence.length(); j++  ){
		if(  !isspace(  sentence.at(j)  )  ){temp.push_back(  sentence.at(j)  );}//get word until it hits a space
		else{
			if(  is_caps(temp)  ){dummy.push_back(' '); temp= "";}//if formed word has a cap it is discarded
			else{dummy+= temp; dummy += " "; temp="";}
		}
	}
	if(  !is_caps(temp)  ){dummy+= temp;}
	else{dummy += " ";}
	return dummy;
}

bool is_caps(string holder){//this methods checks if there a cap in the word
	for(  int j=0; j< (int)holder.length(); j++  ){
		if(  isupper(  holder.at(j)  )  ){return 1;}
	}
	return 0;
}

void op_file(string input_name, string output_name){//an output is created here and deleted at the end of program
	string file_name= input_name;
	ifstream data_file(file_name); ofstream output_file(output_name);
	string holder= "";

	if(  data_file.is_open() ){//this file outputs cleaned up strings
		//cout << "file opened!\n";
		while(  !data_file.eof()  ){
			getline(data_file, holder); 
			holder= clean_up(holder);
			output_file << holder; output_file << endl;//these lines output to a new file with modified strings
			holder= "";
		} 
		output_file.close();
		data_file.close();
	}
	else{cout << "file error!\n";}
	return;
}

void run_output(Word *example, string file_name, int index){//this function loads the new output file, this will be used to count
	ifstream filler(file_name); string holder= ""; 
	if(  filler.is_open() ){
		//cout << "file opened!\n";
		while(  !filler.eof()  ){
			filler >> holder;
			if(  holder == example[index].da_word  ){ example[index].count++; }//this increases the count of a word by one
		}
		filler.close();
	}
	else{cout << "file error!\n";}
	example[index].ratio= example[index].count / example[index].standard_frequency;//this computes the word ratio
	return;
}

int *top(Word *example, int unique_words){
	int const SIZE= 25; int non_zero= 0, dummy= 0;
	int *most_frequent= new int[SIZE]; 
	for(int j= 0; j< SIZE; j++){most_frequent[j]= -1;}//this sets the 25 most common words to zero, this holds indices of the frequent
	for(int i=0; i< unique_words; i++){ if(  example[i].count != 0  ){ non_zero++; }   }//this counts the number of non_zero words
    int bubble[non_zero]= {}; for(int j= 0; j< non_zero; j++){bubble[j]= -1;}//this sets up the array of non_zero words, initialized to -1
    for(int i=0; i< unique_words; i++){ if(  example[i].count != 0  ){ bubble[dummy]= i;dummy++; }   }//this populates the bubble with location of non_zero
    swap(example, bubble, non_zero);//this sorts the array of indices
    for(int i= 0; i< SIZE; i++){most_frequent[i]= bubble[i];}//this assigns the top 25
	return most_frequent;
}

void swap(Word *example, int non_sorted[], int SIZE){
	bool is_sorted= 0; int i= -1, dummy= -1;
	while(  !is_sorted  ){is_sorted= 1;
		for(int j= 0; j< SIZE; j++){
			i= j+1; if(  i == SIZE  ){is_sorted= 1; break;}
			if(  example[  non_sorted[j]  ].ratio<  example[  non_sorted[i]  ].ratio  ){//this does swapping for bubble sort
				dummy= non_sorted[j];
				non_sorted[j]= non_sorted[i];
				non_sorted[i]= dummy;
				is_sorted= 0; break;
			}
		}
	}
	return;
}

void display(Word *example, int sorted[], int SIZE){
	for(int i= 0; i< SIZE; i++){  cout << i << " : " << example[  sorted[i]  ].da_word << endl;  }  
}