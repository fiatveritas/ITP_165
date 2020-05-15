// #include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
//lab work
class Course
{
private:
    std::string name; // eg. "BIO-101"
    double* grades; // list of grades in the course, 0-100
    int numGrades; // how many grades array is defined to

public:
    Course();
    Course( std::string);
    ~Course();
    void addGrade(double);
    void report();
    double* getGrades() { return grades; }
    int getNumGrades() { return numGrades; }
    double getGPA();
    void setName(std::string n ) { name = n; }
    std::string getName() { return name; }
};

// default constructor, does allocations for grades
Course::Course()
{
    name = "no name";
    grades = new double[100]; // hack - will crash if you 
                              // get more than 100
    numGrades = 0;
}

// constructor, takes course name as argument,
// also does allocation
Course::Course( std::string n)
{
    name = n;
    grades = new double[100];
    numGrades = 0;
}

// deallocate grades
Course::~Course()
{
    delete[] grades;
}

// add this grade to the grades array
// (and increment the count)
void Course::addGrade( double g )
{
    grades[numGrades++] = g;
}

// tell stuff about a course ... name and all
// the grades.  
void Course::report()
{
    std::cout <<"grades for " <<name <<": ";
    for ( int i=0; i<numGrades; i++ )
    {
        std::cout <<grades[i] <<" ";
    }
    std::cout <<"\n";
    std::cout <<"avg=" <<getGPA() <<"\n";
}

// compute and return the GPA for the grades in
// THIS course
double Course::getGPA()
{
    double ret = 0;
    double points = 0;
    double base = 0;
    for ( int i=0; i<numGrades; i++ )
    {
        points += grades[i];
        base++;
    }
    if ( base>0 )  { ret = points/base;  }
    return ret;
}

class Student
{
private:
    std::string name; // full name of Student
    int level; // 0=freshman, 1=sophomore, etc.
    Course* previousCourses;
    int pcCount; // number of previous courses
    Course* currentCourses;
    int ccCount; // number of current courses
public:
    Student( std::string name );
    ~Student();
    Course* enrollCurrent(std::string courseName );
    Course* enrollPrevious(std::string courseName );
    void printCurrentCourses();
    void printPrevCourses();
    std::string getName() { return name; }
    double getGPA();
    Course* getPrevCourses() { return previousCourses; } 
    // 
    Course* getCurrentCourses(){ return currentCourses; }
    //
    int getLevel(){ return level; }  
    //setters
    void setName(std::string n) { name = n; }
    void setLevel(int lvl){ level = lvl; } 
    void reportInfo();
    void reportCourses();
    void reportGPA();
    void reportCourseNames();
    void report();
};

// constructor, take the person's name
// initializes the Course arrays
Student::Student( std::string n )
{
    name = n;
    currentCourses = new Course[100]; // hack, will blow over 100
    previousCourses = new Course[100]; // same
      ccCount = 0;
    pcCount = 0;
    level = 0;

}

// destructor, deallocate stuff
Student::~Student()
{
    delete[] previousCourses;
    delete[] currentCourses;
}

// create and add a course with this name to the
// current course list
Course* Student::enrollCurrent(std::string courseName )
{
    Course* pc = &(currentCourses[ccCount++]);
    pc->setName(courseName );
    return pc;
}

// create and add a course with this name to the
// previous course list.  Is a lot like the function
// preceding this one.
Course* Student::enrollPrevious(std::string courseName )
{
   // to do: Done
    Course *pc = &(previousCourses[pcCount++]);
    (*pc).setName(courseName);
    return pc;
}

// prints out all information about the current
// courses (calls Course.report() on each)
void Student::printCurrentCourses()
{
    std::cout <<"current courses for " <<name <<":\n";
    for ( int i=0; i<ccCount; i++ )
    {
        // to do: Done
        currentCourses[i].report();
    }
}

// prints out all information about the 
// previous courses
void Student::printPrevCourses()
{
    // to do: Done
    std::cout <<"previous courses for " <<name <<":\n";
    for ( int i=0; i<pcCount; i++ )
    {
        // to do: Done
        previousCourses[i].report();
    }
}

// compute and return the GPA (just average all
// of the course GPA, current and previous
double Student::getGPA()
{
    double gpa = 0;
    double points = 0;
    for ( int i=0; i<ccCount; i++ )
    {
        points += currentCourses[i].getGPA();
    }
    for ( int i=0; i<pcCount; i++ )
    {
        points += previousCourses[i].getGPA();
    }
    //Done
    int base = ccCount + pcCount;
    if (base>0 ) { gpa = 1.0 * points / base; }
    return gpa;
}

// print the person's basic info (name and
// level (freshman, sophomore ...) )
void Student::reportInfo()
{
    std::cout <<name <<" is a ";
    if      ( level==0 ) { std::cout <<"freshman"; }
    else if ( level==1 ) { std::cout <<"sophomore"; }
    else if ( level==2 ) { std::cout <<"junior"; }
    else if ( level==3 ) { std::cout <<"senior"; }
    std::cout <<"\n";
}

// print all information about current
// and previous courses
void Student::reportCourses()
{
    printPrevCourses();
    printCurrentCourses();
    std::cout <<"\n";

}

// This just prints out the course names,
// current and previous
void Student::reportCourseNames()
{
    //to do: Done
    std::cout << name << " is enrolled in..." << std::endl; 
    for(int j= 0; j< ccCount; j++){std::cout << currentCourses[j].getName() << " ";} std::cout << std::endl;
    std::cout << name << " was enrolled in..." << std::endl; 
    for(int j= 0; j< pcCount; j++){std::cout << previousCourses[j].getName() << " ";} std::cout << std::endl << std::endl;

}

// print out this student's GPA
void Student::reportGPA()
{
    std::cout <<name <<" has gpa " <<getGPA() <<"\n\n";
}

// does all of the reports, info, course names,
// courses (details), and GPA
void Student::report()
{
    reportInfo();
    reportCourseNames();
    reportCourses();
    reportGPA();
}

// main makes a couple of students and gives them
// some courses and then prints out ... to test out
// the member functions of Student and Course.
int main()
{
    Student s1("Tom Trojan");
    Student* ps2 = new Student("Sue Trojan");

    Course* c;

    c = s1.enrollCurrent( "BIO-101");
    c->addGrade(90);c->addGrade(80);c->addGrade(87);c->addGrade(95);

    c = s1.enrollCurrent( "ENG-307");
    c->addGrade(93);c->addGrade(50);c->addGrade(82);c->addGrade(99);

    c = s1.enrollCurrent( "ITP-165");
    c->addGrade(92);c->addGrade(80);c->addGrade(77);c->addGrade(84);

    c = s1.enrollPrevious( "PHYS-307");
    c->addGrade(100);c->addGrade(99);c->addGrade(98);

    c = s1.enrollPrevious( "MATH-307");
    c->addGrade(99);c->addGrade(95);c->addGrade(97);

    s1.report();

    c = ps2->enrollCurrent("ECON-202");
    c->addGrade(88);c->addGrade(91);c->addGrade(72);

    ps2->report();

    delete ps2;

    return 0;
}
