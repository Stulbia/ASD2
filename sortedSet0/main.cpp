#include "setSimple.h"
#include <iostream>

int main() {
    auto a = setSimple(5);
    a.insert(1);
    a.insert(3);

    auto b = setSimple(5);
    b.insert(3);
    b.insert(4);

    //przeładowane operatory
    auto c = a + b; // {1, 3, 4}
    auto d = a * b; // {3}
    auto e = a - b; // {1}

    std::cout << "a+b contains 4: " << c.contains(4) << "\n"; // 1
    std::cout << "a*b contains 3: " << d.contains(3) << "\n"; // 1
    std::cout << "a-b contains 1: " << e.contains(1) << "\n"; // 1

    return 0;
}