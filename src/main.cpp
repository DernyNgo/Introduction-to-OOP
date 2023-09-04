#include <iostream>
#include "student.hpp"
#include "roster.hpp"
#include "degree.h"
#include <string>
#include <array>
using namespace std;
//Print information on course
int main()
{
    cout <<"Title: Scripting and Programming" << endl;
    cout <<"Programming Language: C++" << endl;
    cout <<"Student ID: null" << endl;
    cout <<"Student Name: Daniel Ngo" << endl;
    cout << "    " << endl;
    cout << "    " << endl;
// Initialize Array with values
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Daniel,Ngo,null@null.com,25,10,18,7,SOFTWARE"
    };

    Roster * classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };
//functions
    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
    }
    cout << endl;
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    classRoster->printAll();
    cout << endl;
    cout << endl;

    classRoster->remove("A3");
    cout << endl;
    cout << endl;

    classRoster->~Roster();
    delete classRoster;
    
}
