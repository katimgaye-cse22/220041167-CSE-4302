 #include "Coordinate.h"

void highest(Coordinate c[], int size) {
    Coordinate *maxCoord = &c[0];
    for (int i = 1; i < size; i++) {
        if (c[i] > *maxCoord) {
            maxCoord = &c[i];
        }
    }
    cout << "Coordinate with highest distance: ";
    maxCoord->display();
    cout << "Distance from origin: " << maxCoord->getDistance() << endl;
}
 void lowest(Coordinate c[], int size) {
    Coordinate *minCoord = &c[0];
    for (int i = 1; i < size; i++) {
        if (c[i] < *minCoord) {
            minCoord = &c[i];
        }
    }
    cout << "Coordinate with lowest distance: ";
    minCoord->display();
    cout << "Distance from origin: " << minCoord->getDistance() << endl;
}

int main() {
    const int n = 10;
    Coordinate coord[n];

    randomAssignment(coord, n);

    cout << "Coordinates generated:" << endl;
    for (int i = 0; i < n; i++) {
        coord[i].display();
        cout << "Distance from origin: " << coord[i].getDistance() << endl;
    }

    highest(coord, n);
    lowest(coord, n);

    return 0;
}
