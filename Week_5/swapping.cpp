#include <iostream>
using namespace std;

void SwapValues(int& userVal1, int& userVal2);

int main(){
	int num1, num2;

	cin >> num1; cin >> num2; SwapValues(num1, num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}

void SwapValues(int& userVal1, int& userVal2){
	int holder = userVal1;
	userVal1 = userVal2;
	userVal2 = holder;
}