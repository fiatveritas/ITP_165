#include <iostream>
#include <iomanip>
using namespace std;

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon);

int main(){
	double drivenMiles = 2.0, milesPerGallon = 10.0, dollarsPerGallon = 1.0;
	cout << DrivingCost(drivenMiles, milesPerGallon, dollarsPerGallon);
	return 0;
}

double DrivingCost(double drivenMiles,
	double milesPerGallon, double dollarsPerGallon){
	return drivenMiles * (dollarsPerGallon / milesPerGallon);
}