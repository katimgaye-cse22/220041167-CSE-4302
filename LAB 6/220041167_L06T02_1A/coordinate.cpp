 #include "Coordinate.h"
#include <cstdlib>
#include <ctime>

Coordinate::Coordinate() : abscissa(0), ordinate(0) {}

Coordinate::Coordinate(float x, float y) : abscissa(x), ordinate(y) {}

Coordinate::~Coordinate() {}

void Coordinate::display() const {
    cout << "Coordinate: (" << abscissa << ", " << ordinate << ")" << endl;
}

float Coordinate::operator-(const Coordinate &c) const {
    return sqrt(pow(c.abscissa - this->abscissa, 2) + pow(c.ordinate - this->ordinate, 2));
}

float Coordinate::getDistance() const {
    return sqrt(pow(this->abscissa, 2) + pow(this->ordinate, 2));
}

void Coordinate::move_x(float val) {
    this->abscissa += val;
}

void Coordinate::move_y(float val) {
    this->ordinate += val;
}

void Coordinate::move(float x_val, float y_val) {
    this->abscissa += x_val;
    this->ordinate += y_val;
}

bool Coordinate::operator>(const Coordinate &c) const {
    return this->getDistance() > c.getDistance();
}

bool Coordinate::operator<(const Coordinate &c) const {
    return this->getDistance() < c.getDistance();
}

bool Coordinate::operator>=(const Coordinate &c) const {
    return this->getDistance() >= c.getDistance();
}

bool Coordinate::operator<=(const Coordinate &c) const {
    return this->getDistance() <= c.getDistance();
}

bool Coordinate::operator==(const Coordinate &c) const {
    return this->getDistance() == c.getDistance();
}

bool Coordinate::operator!=(const Coordinate &c) const {
    return !(*this == c);
}

void randomAssignment(Coordinate c[], int size) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; i++) {
        float x = static_cast<float>(rand() % 100);
        float y = static_cast<float>(rand() % 100);
        c[i] = Coordinate(x, y);
    }
}
