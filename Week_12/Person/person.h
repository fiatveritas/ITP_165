#ifndef PERSON_H
#define PERSON_H

class Person{

private: 
	string first, last;
	double height, weight;
	int age;

public:
	Person();
	Person(int, double, double, string, string);
	void setAge(int);
	void setHeight(double);
	void setWeight(double);
	void setFirst(string);
	void setLast(string);
	void printInfo() const;

};

#endif