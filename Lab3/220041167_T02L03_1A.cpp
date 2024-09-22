#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Temperature {
private:
    double tempValue;
    string unit;


    bool isValidUnit(const string& unit) const {
        return (unit == "Celsius" || unit == "Fahrenheit" || unit == "Kelvin");
    }

    bool isValidTemperature(double value, const string& unit) const {
        if (unit == "Celsius" && value < -273.15) return false;
        if (unit == "Fahrenheit" && value < -459.67) return false;
        if (unit == "Kelvin" && value < 0) return false;
        return true;
    }

public:
    Temperature() : tempValue(0), unit("Celsius") {}

    void assign(double value, const string& unit) {

        if (!isValidUnit(unit)) {
            cout << "Invalid unit! Allowed units are 'Celsius', 'Fahrenheit', or 'Kelvin'." << endl;
            return;
        }


        if (!isValidTemperature(value, unit)) {
            cout << "Invalid temperature! The temperature cannot be below absolute zero." << endl;
            return;
        }

        this->tempValue = value;
        this->unit = unit;
    }
    double convert(const string& targetUnit) const {

        if (!isValidUnit(targetUnit)) {
            cout << "Invalid target unit! Allowed units are 'Celsius', 'Fahrenheit', or 'Kelvin'." << endl;
            return tempValue;
        }

        double result;

        double tempInCelsius;
        if (unit == "Celsius") {
            tempInCelsius = tempValue;
        } else if (unit == "Fahrenheit") {
            tempInCelsius = (tempValue - 32) * 5.0 / 9.0;
        } else {
            tempInCelsius = tempValue - 273.15;
        }

        if (targetUnit == "Celsius") {
            result = tempInCelsius;
        } else if (targetUnit == "Fahrenheit") {
            result = tempInCelsius * 9.0 / 5.0 + 32;
        } else {
            result = tempInCelsius + 273.15;
        }

        return result;
    }

    void print() const {
        cout << fixed << setprecision(2);
        cout << "The temperature is " << tempValue << " " << unit << "." << endl;
    }
};

int main() {
    Temperature temp;

    temp.assign(25.0, "Celsius");
    temp.print();

    cout << "Converted to Fahrenheit: " << temp.convert("Fahrenheit") << " Fahrenheit" << endl;

    cout << "Converted to Kelvin: " << temp.convert("Kelvin") << " Kelvin" << endl;

    temp.assign(-500.0, "Celsius");

    temp.assign(300.0, "Kelvin");
    temp.print();

    cout << "Converted to Celsius: " << temp.convert("Celsius") << " Celsius" << endl;

    temp.assign(100.0, "Rankine");

    return 0;
}
