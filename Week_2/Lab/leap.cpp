#include <iostream>
using namespace std;

int main() {
   int inputYear;
   bool isLeapYear = false;
   
   cin >> inputYear;
   
   cout << inputYear;

   if (inputYear % 100 != 0){
   	if (inputYear % 4 == 0){
   		isLeapYear = true;
   	}
   	else{
   		isLeapYear = false;
   	}
   }
   	else if (inputYear % 400 == 0){
   		isLeapYear = true;
   	}
   	else{
   		isLeapYear = false;
   	}
   	if (isLeapYear){
   		cout << " - leap year" << endl;
   	}
   	else{
   		cout << " - not a leap year" << endl;
   	}
   return 0;
}