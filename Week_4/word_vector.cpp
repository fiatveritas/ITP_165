#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int i;
	vector<string> words;
	string word;
	do{
		word = "";
		cin >> word;
		words.push_back(word);
	}while(word != "nomore");

	for(i=words.size()-1; i >= 0; i--){
		if(words.at(i) != "nomore"){cout << words.at(i) << endl;}
	}

	return 0;
}