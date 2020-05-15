#include <iostream>
using namespace std;

int main(){
	int vowels, consonants;
	string word;
	char choice;

	do{
		vowels = 0, consonants = 0;
		word = "";
		cout << "Enter a string:" << endl;
		cin >> word;
		for(int i = 0; i < (int)(word.length()); i++){
			if( word[i] == 'A' || word[i] == 'a' || 
				word[i] == 'E' || word[i] == 'e' || 
				word[i] == 'I' || word[i] == 'i' ||
				word[i] == 'O' || word[i] == 'o' ||
				word[i] ==  'U'|| word[i] == 'u'){
				vowels++;
			}
			else{
				consonants++;
			}
		}
		cout << "There are " << vowels << " vowels and " 
		     << consonants << " consonants in \"" 
		     << word << "\"."<< endl;
		cout << "Would you like to try again? (y/n) :" << endl;
		cin >> choice;
	}while(choice != 'n');
	return 0;
}