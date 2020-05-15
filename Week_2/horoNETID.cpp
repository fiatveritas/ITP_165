//Jesse Gallegos
//ITP 165, 2020 Spring
//Homework 2

/*This program returns the user's zodiac sign and gives them
their horoscope*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int birth_month, birth_day;

	cout << "Welcome to your horoscope." << endl;

	cout << "Enter your birth month as a number: ";
	cin >> birth_month;

	cout << "Enter the day of the month on which you were born: ";
	cin >> birth_day;

/*The program takes all user input first. If either any of the inputs is
out range, the program terminates.*/

	if (birth_month == 1){
		if(birth_day >= 1 && birth_day <= 19){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Capricorn is :" << endl;
			cout << "Love ends. A new love begins. Open up tinder." << endl;
		}
		else if(birth_day >= 20 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Aquarius is :" << endl;
			cout << "Day of love approaches. Subscribe to eHarmony!" << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 2){
		if(birth_day >= 1 && birth_day <= 18){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Aquarius is :" << endl;
			cout << "Day of love approaches. Subscribe to eHarmony!"<< endl;
		}
		else if(birth_day >= 19 && birth_day <= 29){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Pisces is :" << endl;
			cout << "You are feeling you need stability. Try Match.com" << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 3){
		if(birth_day >= 1 && birth_day <= 20){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Pisces is :" << endl;
			cout << "You are feeling you need stability. Try Match.com" << endl;
		}
		else if(birth_day >= 21 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Aries is :" << endl;
			cout << "Restless fills your mind. Zoosk is there..." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 4){
		if(birth_day >= 1 && birth_day <= 19){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Aries is :" << endl;
			cout << "Restless fills your mind. Zoosk is there..." << endl;
		}
		else if(birth_day >= 20 && birth_day <= 30){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Taurus is :" << endl;
			cout << "Options overwhelm. Bumble never ghosts." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 5){
		if(birth_day >= 1 && birth_day <= 20){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Taurus is :" << endl;
			cout << "Options overwhelm. Bumble never ghosts." << endl;
		}
		else if(birth_day >= 21 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Gemini is :" << endl;
			cout << "You feel adventurous. Ashley Madison is discrete." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 6){
		if(birth_day >= 1 && birth_day <= 20){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Gemini is :" << endl;
			cout << "You feel adventurous. Ashley Madison is discrete." << endl;
		}
		else if(birth_day >= 21 && birth_day <= 30){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Cancer is :" << endl;
			cout << "Things are hectic. Remember that Coffee meets Bagel." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 7){
		if(birth_day >= 1 && birth_day <= 22){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Cancer is :" << endl;
			cout << "Things are hectic. Remember that Coffee meets Bagel." << endl;
		}
		else if(birth_day >= 23 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Leo is :" << endl;
			cout << "Age brings experience. CougarLife" << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 8){
		if(birth_day >= 1 && birth_day <= 22){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Leo is :" << endl;
			cout << "Age brings experience. CougarLife" << endl;
		}
		else if(birth_day >= 23 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Virgo is :" << endl;
			cout << "You miss things in your travels. Never miss with Hinge." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 9){
		if(birth_day >= 1 && birth_day <= 22){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Virgo is :" << endl;
			cout << "You miss things in your travels. Never miss with Hinge." << endl;
		}
		else if(birth_day >= 23 && birth_day <= 30){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Libra is :" << endl;
			cout << "It seems love is elusive. Plenty of Fish out there." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 10){
		if(birth_day >= 1 && birth_day <= 22){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Libra is :" << endl;
			cout << "It seems love is elusive. Plenty of Fish out there." << endl;
		}
		else if(birth_day >= 23 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Scorpio is :" << endl;
			cout << "Cuffing season brings flings. OkCupid is DTF." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 11){
		if(birth_day >= 1 && birth_day <= 21){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Scorpio" << endl;
			cout << "Cuffing season brings flings. OkCupid is DTF." << endl;
		}
		else if(birth_day >= 22 && birth_day <= 30){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Sagittarius is :" << endl;
			cout << "You want more. The League is for you." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else if(birth_month == 12){
		if(birth_day >= 1 && birth_day <= 21){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Sagittarius is :" << endl;
			cout << "You want more. The League is for you." << endl;
		}
		else if(birth_day >= 22 && birth_day <= 31){
			cout << "month: " << birth_month<< endl;
			cout << "day of birth: " << birth_day << endl;
			cout << "Horoscope for ";
			cout << "Capricorn is :" << endl;
			cout << "Love ends. A new love begins. Open up tinder." << endl;
		}
		else{
		cout << "Error: Invalid input." << endl;
	    }
	}
	else{
		cout << "Error: Invalid input." << endl;
	}

	return 0;
}