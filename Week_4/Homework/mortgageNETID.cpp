//Jesse Gallegos
//ITP 165, 2020 Spring
//Homework 3

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*This program computes whether a payment plan will finish
paying a mortgage. The user inputs the price_of_home, 
downpayment, the apr, and payment.

NOTE: I used to_string() method to get length of computed
doubles. I need the length of these numbers to set the
width to make things to look pretty. I comment where
these choices are made. Setting the width is done by
fiat.*/

int main(){

	double price_of_house, downpayment, holder, //holder is a dummy variable
	       apr, payment, principle; //principle is computed every month (in the iteration of loop)
	int counter = 0, counter_length, price_length, //these integers store the length for spacing function setw()
	    apr_length, payment_length, principle_length,
	    insurance_length;

	cout << fixed << setprecision(2); // set precision to decimal points

	cout << "Mortgage Payment Schedule" << endl;

	cout << "Enter house price: ";      cin >> price_of_house;
	cout << "Enter down payment: ";     cin >> downpayment;
	cout << "Enter interest rate \%: "; cin >> apr;
	cout << "Enter payment : ";         cin >> payment;
	
	/*The block below assigns constants to these variables*/
	principle = price_of_house - downpayment; //outstanding principal at signing
	counter_length = 5; //arbitrary choice, to make spacing look nice
	principle_length = to_string(principle).length(); // typecasted the number principle, then got the length of string
	apr_length = to_string((apr / 1200 * principle)).length(); //type casted the interest to string, then got the length of string
	insurance_length = 10 ; //this number is arbitrary, to make the spacing look nice
	payment_length = to_string(payment).length(); //type casted payment to string, then got the length of string

    /*The block below sets and outputs the 
    widths for the words printed*/
	cout << setw(counter_length) << "month:" 
	     << setw(principle_length) << "principle" << " +" 
	     << setw(apr_length) << "interest" << " +" 
	     << setw(insurance_length) << "insurance" << " -" 
	     << setw(payment_length) << "payment" << " = " 
	     << "new principle" << endl;

	do{
		counter++; //this counter shows the number of months into the payment
		holder = principle; // this variable is a dummy variable; it's useful to avoid overpaying

		cout << setw(counter_length - 1) << counter << " :" //subtracted counter value by one to match problem set
		     << setw(principle_length) << principle << " +" 
		     << setw(apr_length) << (apr / 1200 * principle); //interest rate for the month, done inline to avoid rounding error

		if(principle > (.80 * price_of_house)  ){
			cout << " +" << setw(insurance_length) << (0.5 / 1200 * principle); /*computes insuarance when 
			                                                                    more than 80% price_of_house owed*/
			principle = principle + (apr / 1200 * principle)
		              + (0.5 / 1200 * principle) - payment; //total principle owed, inline calculation
		}
		else{//this case gets activated when less than 80% of price_of_house is owed
			cout << " +" << setw(insurance_length) << 0.00; // $0.00 is paid for insuarance in this case

			principle = principle + (apr / 1200 * principle) //computes principle without insurance payment
		              - payment;

		    if(principle < 0){/*this avoids overpaying on the last payment, 
		                      bumps down payment to whatever was owed plus interest*/
		    	payment = holder + (apr / 1200 * holder); //last payment is equal to principal at the start plus interest
		        principle = holder + (apr / 1200 * holder) - payment; //should equal theory when all is done and paid
		    }
		}
		cout << " -"  << setw(payment_length) << payment 
		     << " = " << principle << endl;

		if (holder < principle){//make sure new principle is less than previous iteration
			cout << "payment is not enough,"
			     << " loan will never get paid\n";
			break;//cancel the calculation if this is the case
		}
	}while(principle > 0);

	return 0;
}