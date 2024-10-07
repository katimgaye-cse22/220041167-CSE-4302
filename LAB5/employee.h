#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string name;
    std::string dateOfBirth;
    double salary;

    int calculateAge(const std::string& dob) const;

public:

    Employee(std::string name = "John Doe", std::string dateOfBirth = "1 January 2002", double salary = 10000);

    std::string getName() const;
    std::string getDateOfBirth() const;
    double getSalary() const;


    void setName(const std::string& name);
    void setDateOfBirth(const std::string& dateOfBirth);
    void setSalary(double salary);


    void setInfo();
    void getInfo() const;

    Employee compareAge(const Employee& e) const;
};

#endif
