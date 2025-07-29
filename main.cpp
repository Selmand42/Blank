#include <iostream>
#include "bigint.hpp"

int main() {
    // Création de bigints
    bigint num1("200"), num2("42"), num3, num4(100);
    bigint num5 = num2;
    const bigint numC(60);

    // Test des opérateurs arithmétiques
    std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
    num3 = num1;
    num3 += num2;
    std::cout << "num3 += num2: " << num3 << std::endl;

    // Test des comparaisons
    std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
    std::cout << "num1 != num2: " << (num1 != num2) << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "num1 <= num2: " << (num1 <= num2) << std::endl;
    std::cout << "num1 > num2: " << (num1 > num2) << std::endl;
    std::cout << "num1 >= num2: " << (num1 >= num2) << std::endl;

    // Test des décalages avec entiers
    std::cout << "num1 << 2 = " << (num1 << 2) << std::endl;
    std::cout << "num1 >> 2 = " << (num1 >> 2) << std::endl;

    return 0;
}

