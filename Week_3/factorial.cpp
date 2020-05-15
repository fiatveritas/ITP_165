#include <iostream>
using namespace std;

int main(){
	long long number, holder, product;



	do{
		product = 1;
		cout << "Enter a number to use to compute a factorial..." << endl;
		cout << "Enter a negative number to quit: " << endl;
		cin >> number;
		holder = number;
			if(number < 0){
				cout << endl << "Quitting!" << endl;
				return 0;
			}
			else if(number == 0){
				cout << number << "! = " << 1 << endl;
			}
			else if(number == 1){
				cout << number << "! = " << 1 << endl;
			}
			else if(number >= 1){
				do{
					product = product * holder;
					holder = holder -1;
				} while(holder > 1);
				cout << number << "! = " << product << endl;

		}
		cout << endl;
	}while(number >= 0);

	return 0;
}