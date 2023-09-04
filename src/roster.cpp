#include <iostream>
#include <string>
#include "degree.h"
#include "student.hpp"
#include "roster.hpp"
#include <string>
#include <array>
using namespace std;

//constructor for classes
Roster::Roster(int classSize) {
    this->classSize = classSize;
    this->ind = 0;
    for (int i = 0; i < classSize; i++) {
        this->classRosterArray[i] = new Student;
    }
    return;
}

string Roster::GetStudentID(int index) {
    string studentID = classRosterArray[index]->getStudentID();
    return studentID;
}

//parsing method
void Roster::parse(string studentDataTable) {
    string studentID, firstName, lastName, emailAddress;
    int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;
    if (ind < classSize) {
        classRosterArray[ind] = new Student();

        int i = studentDataTable.find(",");
        studentID = studentDataTable.substr(0, i);
        classRosterArray[ind]->setID(studentID);

        int d = i + 1;
        i = studentDataTable.find(",", d);
        firstName = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->setFirstName(firstName);

        d = i + 1;
        i = studentDataTable.find(",", d);
        lastName = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->setLastName(lastName);

        d = i + 1;
        i = studentDataTable.find(",", d);
        emailAddress = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->setEmailAddress(emailAddress);

        d = i + 1;
        i = studentDataTable.find(",", d);
        studentAge = stoi(studentDataTable.substr(d, i - d));
        classRosterArray[ind]->setAge(studentAge);

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse1 = stoi(studentDataTable.substr(d, i - d));

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse2 = stoi(studentDataTable.substr(d, i - d));

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse3 = stoi(studentDataTable.substr(d, i - d));
        classRosterArray[ind]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

        d = i + 1;
        i = studentDataTable.find(",", d);
        string type = studentDataTable.substr(d, i - d);
        if (type == "SOFTWARE") {
            classRosterArray[ind]->setDegreeProgram(SOFTWARE);
        }
        else if (type == "SECURITY") {
            classRosterArray[ind]->setDegreeProgram(SECURITY);
        }
        else if (type == "NETWORK") {
            classRosterArray[ind]->setDegreeProgram(NETWORK);
        }
        else {
            cout << "Degree program not present." << endl;
        }
        ind++;
    }
    return;
}

//adding the student object to the roster method
void Roster::add(string studentID, string firstName, string lastName, string email, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    classRosterArray[classSize] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
};

//removing the student from the roster
void Roster::remove(string id) {

    bool foundStudent = false;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        else if (id == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (foundStudent == false) {
        cout << "Error: Student " << id << " was not found." << endl;
    }
    else if (foundStudent == true) {
        cout << "Student " << id << " removed." << endl;
    }
    return;
}

//call to print all
void Roster::printAll() {
    cout << "Displaying all current students: " << endl;
    cout << endl;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr)
        {
            continue;
        }
        else {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
    return;
}

//print average days in courses
void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < classSize; i++) {
        if (id == classRosterArray[i]->getStudentID()) {
                cout << id << "" << "'s average days in the courses: " <<
                    ((classRosterArray[i]->getDaysInCourse()[0] +
                        classRosterArray[i]->getDaysInCourse()[1] +
                        classRosterArray[i]->getDaysInCourse()[2]) / 3)
                    << endl;

        }
    }
    return;
}

//print all invalid emails
void Roster::printInvalidEmails() {
    cout << "Displaying all invalid email addresses: " << endl;
    cout << endl;
    for (int i = 0; i < classSize; ++i) {
        string emailAd = classRosterArray[i]->getEmailAddress();
        if ((emailAd.find('@') == string::npos) ||  (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
            cout<<"Invalid Email Address: " << classRosterArray[i]->getStudentID() << "'s  Email Address " << emailAd << " is invalid." << endl;
        }
    }
    cout << endl;
    return;
}


//print by degree program
void Roster::printByDegreeProgram(DegreeProgram degPro) {
    string degreeString;
    if (degPro == SECURITY) {
        degreeString = "SECURITY";
    }
    else if (degPro == NETWORK) {
        degreeString = "NETWORK";
    }
    else if (degPro == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    else {
        degreeString = "ERROR";
    }
    cout << "Students with the degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degPro) {
            classRosterArray[i]->print();
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "ERROR" << endl;
    }
    return;
}

Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    };

    
}
