  #include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(const string& lp, const string& manu, double cs)
        : licensePlate(lp), manufacturer(manu), carriageSizeLimit(cs) {}

    Vehicle() : licensePlate(""), manufacturer(""), carriageSizeLimit(0) {}

    virtual ~Vehicle() {}

    virtual void maintenance() const = 0;
};

class GasolineVehicle : public virtual Vehicle {
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(const string& lp, const string& manu, double cs,
                    double ftc, const string& ftp)
        : Vehicle(lp, manu, cs), fuelTankCapacity(ftc), fuelType(ftp) {}

    GasolineVehicle() : Vehicle(), fuelTankCapacity(0), fuelType("Petrol") {}

    void maintenance() const override {
        cout << "GasolineVehicle - maintenance" << endl;
    }
};

class ElectricVehicle : public virtual Vehicle {
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(const string& lp, const string& manu, double cs,
                    double bc, int ct)
        : Vehicle(lp, manu, cs), batteryCapacity(bc), chargingTime(ct) {}

    ElectricVehicle() : Vehicle(), batteryCapacity(0), chargingTime(0) {}

    void maintenance() const override {
        cout << "ElectricVehicle - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string& lp, const string& manu, double cs,
                  double ftc, const string& ftp, double bc, int ct,
                  double ere)
        : Vehicle(lp, manu, cs),
          GasolineVehicle(lp, manu, cs, ftc, ftp),
          ElectricVehicle(lp, manu, cs, bc, ct),
          energyRegenerationEfficiency(ere) {}

    HybridVehicle() : GasolineVehicle(), ElectricVehicle(), energyRegenerationEfficiency(0) {}

    void maintenance() const override {
        cout << "HybridVehicle - maintenance" << endl;
    }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& lp, const string& manu, double cs,
               double ftc, const string& ftp)
        : GasolineVehicle(lp, manu, cs, ftc, ftp) {}

    Motorcycle() : GasolineVehicle() {}

    void maintenance() const override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& lp, const string& manu, double cs, double ftc,
        const string& ftp, int pc)
        : GasolineVehicle(lp, manu, cs, ftc, ftp), passengerCapacity(pc) {}

    Car() : GasolineVehicle(), passengerCapacity(0) {}

    void maintenance() const override {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& lp, const string& manu, double cs, double ftc,
          const string& ftp, double cc)
        : GasolineVehicle(lp, manu, cs, ftc, ftp), cargoCapacity(cc) {}

    Truck() : GasolineVehicle(), cargoCapacity(0) {}

    void maintenance() const override {
        cout << "Truck - maintenance" << endl;
    }
};

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& n, int i) : name(n), id(i) {}
    Employee() : name(""), id(0) {}

    virtual ~Employee() {}

    virtual void introduce() const = 0;
};

class Manager : public Employee {
public:
    Manager(const string& n, int i) : Employee(n, i) {}
    Manager() : Employee() {}

    void introduce() const override {
        cout << "Manager: Mr. " << name << endl;
    }
};

class Driver : public Employee {
public:
    Driver(const string& n, int i) : Employee(n, i) {}
    Driver() : Employee() {}

    void introduce() const override {
        cout << "Driver: " << name << endl;
    }
};

class Branch {
private:
    Vehicle* vehicles[50];
    Employee* employees[50];
    int vehicleCount;
    int employeeCount;

public:
    Branch() : vehicleCount(0), employeeCount(0) {}

    ~Branch() {
        for (int i = 0; i < vehicleCount; ++i) {
            delete vehicles[i];
        }
        for (int i = 0; i < employeeCount; ++i) {
            delete employees[i];
        }
    }

    void addVehicle(Vehicle* v) {
        if (vehicleCount < 50) {
            vehicles[vehicleCount++] = v;
        } else {
            cout << "Vehicle storage full!" << endl;
        }
    }

    void addEmployee(Employee* e) {
        if (employeeCount < 50) {
            employees[employeeCount++] = e;
        } else {
            cout << "Employee storage full!" << endl;
        }
    }

    void maintenance_all_vehicles() const {
        for (int i = 0; i < vehicleCount; ++i) {
            vehicles[i]->maintenance();
        }
    }

    void introduceEmployees() const {
        for (int i = 0; i < employeeCount; ++i) {
            employees[i]->introduce();
        }
    }
};

int main() {
    Branch dhaka;

    dhaka.addVehicle(new Car("1234", "Toyota", 1500, 50, "Petrol", 5));
    dhaka.addVehicle(new Truck("5678", "Ford", 5000, 150, "Diesel", 20000));
    dhaka.addVehicle(new ElectricVehicle("EV123", "Tesla", 1000, 100, 60));

    dhaka.addEmployee(new Manager("Alice", 1));
    dhaka.addEmployee(new Driver("Bob", 2));

    cout << "Maintenance for all vehicles:" << endl;
    dhaka.maintenance_all_vehicles();

    cout << "\nEmployee introductions:" << endl;
    dhaka.introduceEmployees();

    return 0;
}
