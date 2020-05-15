#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int age, driving_start, accidents, model_year;
	double tally;
	
	cout << "How old are you in years? :" << endl;
	cin >> age;

	cout << "What year did you start driving? :" << endl;
	cin >> driving_start;

	cout << "How many accidents have you had in the last 3 years? :" << endl;
	cin >> accidents;

	cout << "What model year is your car? :" << endl;   
	cin >> model_year;

	tally = 900;

	if (age < 25){
		tally = tally + 100;}
	if (2020 - driving_start < 5){
		tally = tally + 100;}
	if (accidents >= 1){
		tally = tally + 100;}
	if (2020 - model_year > 5){
		tally = tally + 100;}

	cout << "Your car insurance premium is $" 
         << fixed << setprecision(2) << tally 
         << "." << endl;


	/*std::cout << std::fixed << std::setprecision(2) 
	          << price << "." << std::endl;*/
   return 0;
   }