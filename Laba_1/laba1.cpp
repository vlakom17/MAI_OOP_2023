#include <iostream>
#include <string>
#include "lab1.h"
int main()
{
    int a;
    std :: cout << "Введите число: " << std::endl;
    std::cin >> a;
    if (isnt_clean(a) == 1) std::cout << "Число не является чистым " << std::endl;
    else std::cout << "Число является чистым " << std::endl;
    return 0;
}