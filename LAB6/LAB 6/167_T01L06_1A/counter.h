 #ifndef COUNTER_H
#define COUNTER_H

#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    int incrementStep;
    Counter(int step_val = 1);
    void setIncrementStep(int step_val);

    int getCount() const;

    void increment();

    void resetCount(int step = 1);

    Counter operator+(const Counter& other) const;

    Counter& operator+=(const Counter& other);


    bool operator==(const Counter& other) const;
    bool operator!=(const Counter& other) const;
    bool operator<(const Counter& other) const;
    bool operator>(const Counter& other) const;
    bool operator<=(const Counter& other) const;
    bool operator>=(const Counter& other) const;

    Counter& operator++();
    Counter operator++(int);
};

#endif
