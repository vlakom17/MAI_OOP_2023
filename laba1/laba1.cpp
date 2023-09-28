#include <iostream>
#include <string>
#include "lab1.h"
int main()
{
    int a;
    std :: cout << "Введите число: " << std::endl;
    std::cin >> a;
    if (is_clean(a) == 0) std::cout << "Число не является чистым " << std::endl;
    else std::cout << "Число является чистым " << std::endl;
    return 0;
}