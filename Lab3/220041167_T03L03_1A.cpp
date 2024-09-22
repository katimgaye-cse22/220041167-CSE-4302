  #include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:

    Time() : hour(0), minute(0), second(0) {}


    int hours() const {
        return hour;
    }

    int minutes() const {
        return minute;
    }

    int seconds() const {
        return second;
    }

    void reset(int h, int m, int s) {

        hour = h % 24;
        minute = m % 60;
        second = s % 60;
    }

    void advance(int h, int m, int s) {

        second += s;
        minute += second / 60;
        second %= 60;

        minute += m;
        hour += minute / 60;
        minute %= 60;

        hour += h;
        hour %= 24;
    }


    void print() const {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << endl;
    }
};

int main() {

    Time t;


    cout << "Initial time: ";
    t.print();

    t.reset(23, 59, 59);
    cout << "Time after reset: ";
    t.print();


    t.advance(0, 0, 1);
    cout << "Time after advancing by 1 second: ";
    t.print();

    t.advance(1, 30, 45);
    cout << "Time after advancing by 1 hour, 30 minutes, and 45 seconds: ";
    t.print();

    return 0;
}
