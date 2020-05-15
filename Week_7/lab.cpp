#include <iostream>
using namespace std;

void display(double holder[], const int size, int counter); // this function displays the output, new line every ten characters
void get_data(double holder[], const int size, int &counter); // get user input
void swap(double &num_1, double &num_2); //swaps values of two elements
void bubble_sort(double holder[], const int size, int counter); //bubble sort algorithm

int main(){
   const int size = 100; int counter = 0;
   double holder[size];

   /*holder[0] = 5; holder[1] = 4; holder[2] = 3;
   holder[3] = 2; holder[4] = 1; holder[5] = 0;
   counter = 6;*/
   get_data(holder, size, counter);
   bubble_sort(holder, size, counter);
   display(holder, size, counter);

   cout << endl;
   return 0;
   }

void display(double holder[], const int size, int counter){
   int dummy = 0;
   for(int i= 0; i< counter; i++){
      if(dummy > 9){
         cout << endl;
         dummy = 0;
      }
      cout<< holder[i] << " ";
      dummy++;
   }
}

void get_data(double holder[], const int size, int &counter){
   double dummy;
   cout << "Enter numbers, -1 to quit: \n";
   do{
      cin >> dummy;
      if(dummy >= 0){
         holder[counter] = dummy;
         counter++;
      }
   }while(dummy >= 0);
}

void swap(double &num_1, double &num_2){
   double holder = num_1;
   num_1 = num_2;
   num_2 = holder;
}

void bubble_sort(double holder[], const int size, int counter){
   bool sorted = false;
   do{
      sorted = true;
      for(int i= 0; i< counter; i++){
         if( ( i+1 ) >= counter  ){break;}
         if( holder[i] > holder[i+1] ){
            swap(holder[i], holder[i+1]); 
            sorted = false;
         }
      /**/
      }
   }while(!sorted);
}