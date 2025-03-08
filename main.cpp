#include <iostream>
#include "cal.h"

int main(void) {
    int num1 = 5;
    int num2 = 3;

    std::cout << "Addition: " << add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << minus(num1, num2) << std::endl;

    return 0;
}
