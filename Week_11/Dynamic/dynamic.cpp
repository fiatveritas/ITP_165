#include <iostream>
using namespace std;
//lab work
struct Car{
	string brand= "";
	string model= "";
	string year= "";
};

int main(){
	bool more= 0; char choice= ' ';
	string holder1= "", holder2= "", dummy= "";
	int i= 0;

	while( !more ){
		Car *Owned = new Car;
		cout << "Make:" << endl;  getline(cin, holder1); (*Owned).brand= holder1;
		cout << "Model:" << endl; getline(cin, holder2); (*Owned).model= holder2;
		cout << "Year:" << endl;  getline(cin, dummy);   (*Owned).year= dummy;
		cout << "Car: " << (*Owned).year << " " << (*Owned).brand << " "<< (*Owned).model << endl;
		cout << "------------------------" << endl;
		cout << "Do you have another car? (Y/N):" << endl; cin >> choice;
		cin.ignore(); 
		delete Owned; //i++;
		if( choice == 'N'  || choice == 'n' ){ more= 1;  } //if( i == 5 ){break;}
	}
	//Owned = nullptr;
	return 0;
}