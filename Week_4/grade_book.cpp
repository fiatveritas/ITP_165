#include <iostream>
using namespace std;

int main(){
	int choice, score[3] = {76, 95, 89};
	string first_name[3] = {"Ray", "Heather", "Julia"}, last_name[3] = {"Kim", "Romero", "Lin"};
	while(choice != 3){
		cout << "Choose a person to see their score:" << endl;
		cout << "0: Ray Kim" << endl;
		cout << "1: Heather Romero" << endl;
		cout << "2: Julia Lin" << endl;
		cout << "3: Quit" << endl;
		cout << "Number:" << endl;
		cin >> choice;

		if(choice > 3){
			cout << "Invalid option! Try again:" << endl;
			cin >> choice;
		}
		else if(choice == 3){
			break;
		}

		cout << first_name[choice] << " "
		     << last_name[choice] << "'s score is: "
		     << score[choice] << endl;
	}

	return 0;
}