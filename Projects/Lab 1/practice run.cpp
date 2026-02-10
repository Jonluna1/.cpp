#include <iostream>

int main() {
    int a;

    std::cout << "give me a number: ";
    std::cin >> a;

    if (a % 2 == 0) {
        std::cout << "a is even";
    } else {
        std::cout << "a is odd";
    }

    return 0;
}
