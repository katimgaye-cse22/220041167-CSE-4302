 #include <iostream>
#include "employee.h"

using namespace std;

int main() {
    Employee emp1, emp2;

    cout << "Enter details for Employee 1:" << endl;
    emp1.setInfo();

    cout << endl;


    cout << "Enter details for Employee 2:" << endl;
    emp2.setInfo();

    cout << endl;


    cout << "Employee 1 Information:" << endl;
    emp1.getInfo();

    cout << endl;

    cout << "Employee 2 Information:" << endl;
    emp2.getInfo();

    cout << endl;
    Employee elder = emp1.compareAge(emp2);
    cout << "The elder employee is: " << endl;
    elder.getInfo();

    return 0;
}
