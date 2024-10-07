 #include "Counter.h"
#include <iostream>

int main() {

    Counter c1;
    Counter c2(3);
    Counter c3(3);

    c1.setIncrementStep(5);
    c1.increment();
    c1.increment();

    c2.increment();
    c2.increment();

    std::cout << "c1 count: " << c1.getCount() << std::endl;
    std::cout << "c2 count: " << c2.getCount() << std::endl;

    c3 = c1 + c2;
    std::cout << "c3 (c1 + c2) count: " << c3.getCount() << std::endl;

    if (c1 == c2) {
        std::cout << "c1 and c2 have the same count\n";
    } else {
        std::cout << "c1 and c2 have different counts\n";
    }

    c1 += c2;
    std::cout << "c1 after += c2: " << c1.getCount() << std::endl;


    ++c1;
    std::cout << "c1 after prefix increment: " << c1.getCount() << std::endl;

    c1++;
    std::cout << "c1 after postfix increment: " << c1.getCount() << std::endl;

    return 0;
}
