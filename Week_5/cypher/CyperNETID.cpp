// Jesse Gallegos
// ITP 165, 2020 Spring
// Homework 4

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void greeting(); //display greeting
void cypher(string message[], string output_array[], int num_words); //code for the encryption method
void pretty_message(string message[], int num_words); //fix the spacing for output
void decypher(string message[], string output_array[], int num_words); //decrypt a message
void end_of_program(); //end of program statement

int main(){
	const int array_size = 1000;
	string message[array_size], output_array[array_size],
	              word = "";
	int num_words = 0, user_choice;
	istringstream ss;

	//word = "Now is the time for all good beings to come to the aid of their country endend\n";
	//word = "Now for to aid is all come of the good to their time beings the country endend\n";
	//ss.str(word);

	greeting();

	do{
		word = "";
		cout << "enter word: "; //ss >> word;
		cin >> word;

		if(word != "endend"){
			message[num_words] = word;
			num_words++;}
	}while(word != "endend");


	cout << "cypher:1, decypher:2. which? : "; cin >> user_choice;
	if(user_choice == 1){cypher(message, output_array, num_words);}
	else if(user_choice == 2){decypher(message, output_array, num_words);}


	//decypher(message, output_array, num_words);
	end_of_program();
	return 0;
}

void greeting(){
	cout << "==Encryption/Decryption="<<endl;
	cout << "========================"  << endl
	     << "Enter message one word at" << endl
	     << "a time. End message with"  << endl
	     << "\'endend\'." << endl;
	cout << "========================" << endl;
}

void cypher(string message[], string output_array[], int num_words){
	/*this method encrypts a message by outputting the fourth word away
	  from the starting index. this cypher uses 0th, 1st, 2nd, and 3rd
	  indices as starting points.*/
	int index = 0, output_index = 0;
	cout << "========================" << endl;
	do{
		for(int i = index; i < num_words; i+= 4){
			output_array[output_index] = message[i];
			output_index++;
		}
		index++;
	}while(index < 4);
	pretty_message(output_array, num_words);
	cout << "\nbye\n";
}

void pretty_message(string message[], int num_words){
	/*this method displays the message in a pretty
	  format. a total of*/
	int length_of_line = 0;
	for(int i = 0; i < num_words; i++){
		length_of_line += (int)( message[i].size() ); //keep track of length of words
		length_of_line++; //this extra addition accomodates for space
		if(length_of_line >= 30){
			cout << endl; //print a newline when you have more than 30 characters for the line
			length_of_line = 0;//reset the length_of_line to track next line
		}
		cout << message[i] << " ";
	}
}

void decypher(string message[], string output_array[], int num_words){
	int output_index = 0;
	int new_from_start = 0;
	int counter = 0;

	cout << "========================" << endl;
	cout << "hi, decypher" << endl;
	for(int i = 0; i < num_words; i++){
		if(i == 0){
			output_array[output_index] = message[i];
			continue;
		}
		if(i >= 1 && i <= 3){output_array[4*i] = message[i];}
		output_index += 4 ;
		if(output_index >= num_words){
			new_from_start = output_index - (num_words - 1);
			output_array[new_from_start] = message[i];
			counter++;
			output_index = counter;
		}
		else{
			output_array[i] = message[output_index];
		}
	}
	pretty_message(output_array, num_words);
	cout << "\nbye\n";

}

void end_of_program(){
	cout << "==========END==========" << endl;
}