// Jesse Gallegos
// ITP 165, 2020 spring
// Homework 01 Donut

/*This program computes the price of an
  order of donuts. Adding sprinkles increases
  the cost of the order.*/

#include <iostream>
#include <iomanip>
#include <string>
//using namespace std; //per instructor request commented out.

const double priceDonuts = 2.50, priceSprinkles = 0.30; //prices are in US dollars

int main(){
	
	std::string name;
	int numDonuts, numSprinkles;
	double price;

	std::cout << "What is your name? "; //prompts user for personalized experience
	std::cin >> name;

	std::cout << "How many donuts do you want? "; //for quantity of donuts
	std::cin >> numDonuts;

	std::cout << "How many with sprinkles? "; //ask for quantities of sprinkles
	std::cin >> numSprinkles;

	std::cout << name << ", your " << numDonuts << " donuts with "
	          << numSprinkles << " sprinkles costs $";

	price = (numDonuts * priceDonuts) + (numSprinkles * priceSprinkles); //compute price of customer order

	std::cout << std::fixed << std::setprecision(2) 
	          << price << "." << std::endl;


	return 0;
}