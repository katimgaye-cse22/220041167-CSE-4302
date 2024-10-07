 #include "employee.h"
#include <iostream>
#include <sstream>

using namespace std;

Employee::Employee(string name, string dateOfBirth, double salary) {
    setName(name);
    setDateOfBirth(dateOfBirth);
    setSalary(salary);
}

int Employee::calculateAge(const std::string& dob) const {
    stringstream ss(dob);
    string day, month, year;
    ss >> day >> month >> year;

    int birthYear = stoi(year);
    return 2024 - birthYear;
}

string Employee::getName() const {
    return name;
}

string Employee::getDateOfBirth() const {
    return dateOfBirth;
}

double Employee::getSalary() const {
    return salary;
}


void Employee::setName(const string& newName) {
    if (newName.length() > 2) {
        name = newName;
    } else {
        name = "John Doe";
    }
}

void Employee::setDateOfBirth(const string& newDateOfBirth) {
    if (calculateAge(newDateOfBirth) > 18) {
        dateOfBirth = newDateOfBirth;
    } else {
        dateOfBirth = "1 January 2002";
    }
}

void Employee::setSalary(double newSalary) {
    if (newSalary >= 10000 && newSalary <= 100000) {
        salary = newSalary;
    } else {
        salary = 10000;
    }
}


void Employee::setInfo() {
    string inputName, inputDob;
    double inputSalary;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, inputName);
    setName(inputName);

    cout << "Enter date of birth (e.g., 15 August 1995): ";
    getline(cin, inputDob);
    setDateOfBirth(inputDob);

    cout << "Enter salary: ";
    cin >> inputSalary;
    setSalary(inputSalary);
}

void Employee::getInfo() const {
    cout << "Name: " << getName() << endl;
    cout << "Date of Birth: " << getDateOfBirth() << endl;
    cout << "Salary: " << getSalary() << " BDT" << endl;
}

Employee Employee::compareAge(const Employee& e) const {
    if (calculateAge(this->dateOfBirth) > calculateAge(e.dateOfBirth)) {
        return *this;
    } else {
        return e;
    }
}
