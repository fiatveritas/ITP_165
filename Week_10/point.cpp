#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    double x_1= 0, y_1= 0,
           x_2= 0, y_2=0;
public:
    double distance(double &x, double &y);
    void getter(double &x_1_dummy, double &y_1_dummy, double &x_2_dummy, double &y_2_dummy);
    void output();
    void distance();
};

double Point::distance(double &x, double &y){
	double num = 0;
	return num;
}

void Point::getter(double &x_1_dummy, double &y_1_dummy, double &x_2_dummy, double &y_2_dummy){
	x_1 = x_1_dummy;
	y_1 = y_1_dummy;
	x_2 = x_2_dummy;
	y_2 = y_2_dummy;
}

void Point::output(){
	cout << "The distance between " ;
	cout << "(" << x_1 << "," << y_1 << ")";
	cout << " and ";
	cout << "(" << x_2 << "," << y_2 << ")";
	cout << " is "; distance(); cout << ".";
	cout << endl;
}

void Point::distance(){
	cout << sqrt( pow( x_1 - x_2, 2) +  pow( y_1 - y_2 , 2)  );
}

int main(){
	double x= 0, y= 0,
	       u= 0, v= 0;
    Point points;
    cout << "Enter 1st x:\n" ; cin >> x;
    cout << "Enter 1st y:\n" ; cin >> y;
    cout << "Enter 2nd x:\n" ; cin >> u;
    cout << "Enter 2nd y:\n" ; cin >> v;
    points.getter(x, y, u, v);
    points.output();

	return 0;
}