 #include <iostream>
using namespace std;

class Calculator {
private:
    int currentStatus;

    int getCurrentStatus() const {
        return currentStatus;
    }

    void setCurrentStatus(int value) {
        currentStatus = value;
    }

public:

    Calculator() : currentStatus(0) {}

    Calculator(int initialValue) : currentStatus(initialValue) {}

    void add(int value) {
        setCurrentStatus(currentStatus + value);
    }

    void subtract(int value) {
        setCurrentStatus(currentStatus - value);
    }

    void multiply(int value) {
        setCurrentStatus(currentStatus * value);
    }

    int divideBy(int value) {
        if (value == 0) {
            cout << "Invalid arithmetic operation." << endl;
            return -1;
        }
        int remainder = currentStatus % value;
        setCurrentStatus(currentStatus / value);
        return remainder;
    }


    void clear() {
        setCurrentStatus(0);
    }

    void display() const {
        cout << "Calculator display: " << getCurrentStatus() << endl;
    }


    ~Calculator() {
        cout << getCurrentStatus() << endl;
        cout << "Destructor of the Calculator object is called." << endl;
    }
};

int main() {
    Calculator calc;

    calc.add(10);
    calc.display();

    calc.add(7);
    calc.display();

    calc.multiply(31);
    calc.display();

    calc.subtract(42);
    calc.display();

    calc.divideBy(7);
    calc.display();

    calc.divideBy(0);
    calc.display();
    calc.add(3);
    calc.display();
    calc.clear();
    calc.display();

    return 0;
}
