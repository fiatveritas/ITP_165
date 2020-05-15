#include <iostream>
using namespace std;

#include "person.h"


int main()
{
	Person newPerson;
	std::string first, last;
	std::cout << "Please enter a first name:\n";
	std::getline(std::cin, first);
	std::cout << "Please enter a last name:\n";
	std::getline(std::cin, last);

	std::cout << "Please enter age:\n";
	int age;
	double height, weight;
	std::cin >> age;
	std::cout << "Please enter height in inches:\n";
	std::cin >> height;
	std::cout << "Please enter weight in lbs:\n";
	std::cin >> weight;
	cin.ignore();

	newPerson.setAge(age);
	newPerson.setHeight(height);
	newPerson.setWeight(weight);
	newPerson.setFirst(first);
	newPerson.setLast(last);

	std::cout << "Printing info....." << std::endl;
	newPerson.printInfo();

	return 0;
}