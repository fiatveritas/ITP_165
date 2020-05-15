#include <iostream>
#include <sstream>
using namespace std;

//lab assignment

void showPointers( stringstream &ss, int array[], int const SIZE);

int main()
{
    int const SIZE= 5;
    int z[SIZE] = { 17, 4, 500, 68, -20 };
    stringstream ss;
   
    showPointers( ss, z, SIZE );
   
    cout << ss.str() << endl;
   
    return 0;
}

void showPointers( stringstream &ss,  int array[], int const SIZE ){
    for(int i= 0; i< SIZE; i++){
    	ss << "array element " << i << " ";
    	ss << "is at address " << &array[i] << " ";
    	ss << "and contains " << array[i] << endl;
    }
    return;
}