 #ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <cmath>

using namespace std;

class Coordinate {
private:
    float abscissa, ordinate;

public:
    Coordinate();
    Coordinate(float x, float y);


    ~Coordinate();

    void display() const;
    float operator-(const Coordinate &c) const;
    float getDistance() const;
    void move_x(float val);
    void move_y(float val);
    void move(float x_val, float y_val);

    bool operator>(const Coordinate &c) const;
    bool operator<(const Coordinate &c) const;
    bool operator>=(const Coordinate &c) const;
    bool operator<=(const Coordinate &c) const;
    bool operator==(const Coordinate &c) const;
    bool operator!=(const Coordinate &c) const;

    friend void randomAssignment(Coordinate c[], int size);
};

#endif
