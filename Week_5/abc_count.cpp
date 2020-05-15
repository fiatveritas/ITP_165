#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int character_counter(string, char);

int main(){
	char i;
	string word;
	cout << "Character Count Function Lab" << endl << endl;
	cout << "Enter string to search:" << endl; getline(cin, word);
	for(i = 'a'; i <= 'z'; i++){
		cout << i << " appears "
		      << character_counter(word, i) 
		      << " times." << endl;
	}
	return 0;
}

int character_counter(string holder, char stuff){
	int count = 0;
	for(int i = 0; i < (int)(holder.size()); i++){
		if(tolower(holder.at(i)) == stuff){
			count ++;
		}
	}
	return count;
}