// Jesse Gallegos
// ITP 165, 2020 spring
// Homework 07

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//This was the easiest solution was using brute force. Struct was not easy to implement because of scope.
void print_story(string story[], const int size, ofstream &output_file);//prints the story from the five arcs
void make_arrays(ifstream &input_file, int dim[], const int size, string beginning[], string protagonist[], string plot_development[], string action[], string conclusion[], string story[]);//makestory array
void make_story(const int NUMBER_STORIES, ifstream &input_file, int dim[], const int size, string story[], ofstream &output_file);//makes number of stories, set by user


int main(){
	srand( (int)time(0) );
	const int size = 5; int dim[size];//define an array with the dims of each part of the story
    const int NUMBER_STORIES = 10; // this can be changed for output, per request ten stories are ouput
	string story[size]; string story_parts, story_output; // define array that contain the plots, next two strings are file names
	string holder = ""; int index = 0, num_words = 0; //this will be passed into parsing through the file
	

	for(int j= 0; j< size; j++){dim[j] = -1; story[j] = "";} // initialize elements to -1

    cout << "Lets write some stories.\n"
         << "Enter filename to story parts: "; cin >> story_parts;//name of input file
    cout << "Enter filename for story output: "; cin >> story_output;//name of ouput file

    ifstream input_file(story_parts); ofstream output_file(story_output);

	if(input_file.is_open()){
		while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){dim[index] = num_words; index++; num_words = 0;}//this line gets dimension size of each plot line
			else{num_words++;}
		}
	}
	else{cout << "Input File error. bye." << endl; return 0;}
	
	make_story(NUMBER_STORIES, input_file, dim, size, story, output_file); // this runs function that populate the story

	input_file.close();
	output_file.close();
	return 0;
}

void print_story(string story[], const int size, ofstream &output_file){
	for(int i= 0; i< size; i++){output_file << story[i] << endl;}//this prints to the output file
		output_file << endl;
}

void make_arrays(ifstream &input_file, int dim[], const int size, string beginning[], string protagonist[], string plot_development[], string action[], string conclusion[], string story[]){
	int num_words = 0; string holder = "";//this function populates the arrays mentioned below

	while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){num_words = 0; break;}
			else{beginning[num_words] = holder; num_words++;}//populates the beginning array
		}


	story[0] = beginning[ rand() % dim[0] ];//chooses a random passage from beginning array

	while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){num_words = 0; break;}
			else{protagonist[num_words] = holder; num_words++;}//populates the protagonist array
		}

	story[1] = protagonist[ rand() % dim[1] ];//chooses a random passage from protagonist array

    while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){num_words = 0; break;}
			else{plot_development[num_words] = holder; num_words++;}//populates the plot_development
		}

	story[2] = plot_development[ rand() % dim[2] ];//chooses a random passage from plot_development

    while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){num_words = 0; break;}
			else{action[num_words] = holder; num_words++;}//populates actions array
		}

	story[3] = action[ rand() % dim[3] ];//chooses a random passage from action array

    while( !input_file.eof() ){
			getline(input_file, holder);
			if( holder.empty() ){num_words = 0; break;}
			else{conclusion[num_words] = holder; num_words++;}//populates conclusion array
		}

	story[4] = conclusion[ rand() % dim[4] ];//chooses a random passage from conclusion array
	return;
}

void make_story(const int NUMBER_STORIES, ifstream &input_file, int dim[], const int size, string story[], ofstream &output_file){
	for(int j= 0; j< NUMBER_STORIES; j++){
	input_file.clear();
	input_file.seekg(0, ios::beg);

	string beginning[ dim[0] ];//these lines set the size for each of the plot arrays
	string protagonist[ dim[1] ]; 
	string plot_development[ dim[2] ]; 
	string action[ dim[3] ]; 
	string conclusion[ dim[4] ];

	make_arrays(input_file, dim, size, beginning, protagonist, plot_development, action, conclusion, story);//this populates the arrays once the array sizes are determined

	print_story(story, size, output_file);
}

}
