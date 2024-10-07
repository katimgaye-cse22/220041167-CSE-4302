 #include "Counter.h"

Counter::Counter(int step_val) : count(0) {
    incrementStep = (step_val > 0) ? step_val : 1;
}

void Counter::setIncrementStep(int step_val) {
    if (count == 0) {
        if (step_val > 0) {
            incrementStep = step_val;
        } else {
            cout << "Negative step not allowed. Keeping the previous step value.\n";
        }
    } else {
        cout << "Cannot set increment step when count is not zero.\n";
    }
}

int Counter::getCount() const {
    return count;
}

void Counter::increment() {
    count += incrementStep;
}

void Counter::resetCount(int step) {
    count = 0;
    incrementStep = (step > 0) ? step : 1;
}

Counter Counter::operator+(const Counter& other) const {
    if (this->incrementStep == other.incrementStep) {
        Counter temp;
        temp.count = this->count + other.count;
        temp.incrementStep = this->incrementStep;
        return temp;
    } else {
        cout << "Increment steps are not the same. Cannot add.\n";
        return *this;
    }
}

Counter& Counter::operator+=(const Counter& other) {
    *this = *this + other;
    return *this;
}

bool Counter::operator==(const Counter& other) const {
    return this->count == other.count;
}

bool Counter::operator!=(const Counter& other) const {
    return !(*this == other);
}

bool Counter::operator<(const Counter& other) const {
    return this->count < other.count;
}

bool Counter::operator>(const Counter& other) const {
    return this->count > other.count;
}

bool Counter::operator<=(const Counter& other) const {
    return this->count <= other.count;
}

bool Counter::operator>=(const Counter& other) const {
    return this->count >= other.count;
}

Counter& Counter::operator++() {
    increment();
    return *this;
}

Counter Counter::operator++(int) {
    Counter temp = *this;
    increment();
    return temp;
}
