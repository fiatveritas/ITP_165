#include <iostream>
using namespace std;

int main(){
	double num_1, num_2;
	char operation;

	cout << "Calculator..." << endl;

	cout << "Enter first number:" << endl;
	cin >> num_1;

	cout << "Enter second number:" << endl;
	cin >> num_2;

	cout << "Enter the operator, +, -, *, or / :" << endl;
	cin >> operation;

	if((num_2 == 0) &&(operation == '/')){
		cout << "Can't divide by 0." << endl;
		return 0;
	}
	cout << num_1 << " "
	     << operation << " "
	     << num_2 << " = ";

	if (operation == '+'){
		cout << num_1 + num_2 << endl;
	}
	else if (operation == '-'){
		cout << num_1 - num_2 << endl;
	}
	else if (operation == '*'){
		cout << num_1 * num_2 << endl;
	}
	else{
		cout << "invalid operator." << endl;
		return 0;
	}

	return 0;
}