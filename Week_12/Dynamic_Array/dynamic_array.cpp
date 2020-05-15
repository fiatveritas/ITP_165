#include <iostream>
using namespace std;
//lab work
void get_data();//this gets user input
void display(int[], int);//this prints the array
int main(){
    get_data();
	return 0;
}

void get_data(){
	int size= -1, dummy= -1, counter= 0;

	cout << "Enter number of scores followed by that many scores :\n";
	cin >> size;

	int nums[size]= {}; for(int j= 0; j< size; j++){ nums[j]= -1; }

	while(  counter< size  ){ cin >> dummy; nums[counter]= dummy; counter++; }
	display(nums, size);
	return;}

void display(int array[], int size){
	for(int i= (size- 1); i>= 0; i--){  cout <<  array[i]  << " ";  }
	cout << endl;
	return;
}