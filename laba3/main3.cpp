#include <iostream>
#include <string>
#include <vector>
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"
#include "array.hpp"


int main(){
	/*Hexagon hex;
	std::cin >> hex;
	Pentagon pent;
	std::cin >> pent;*/
	Rhomb rh1;
	Rhomb rh2;
	std::cin >> rh1;
	std::cin >> rh2;

	/*std::cout << "Площадь: " << hex.get_area() << std::endl;
	std::cout << "Центральная точка: " << hex.get_middle_point().first << " " << hex.get_middle_point().second << std::endl;
	std::cout << hex << std::endl;

	std::cout << "Площадь: " << pent.get_area() << std::endl;
	std::cout << "Центральная точка: " << pent.get_middle_point().first << " " << pent.get_middle_point().second << std::endl;
	std::cout << pent << std::endl;
*/
	std::cout << "Площадь: " << rh1.get_area() << std::endl;
	std::cout << "Центральная точка: " << rh1.get_middle_point().first << " " << rh1.get_middle_point().second << std::endl;
	std::cout << rh1 << std::endl;

	std::cout << "Площадь: " << rh2.get_area() << std::endl;
	std::cout << "Центральная точка: " << rh2.get_middle_point().first << " " << rh2.get_middle_point().second << std::endl;
	std::cout << rh2 << std::endl;
	Array arr = Array(2);

	arr.replace_figure(0, &rh1);
	arr.replace_figure(1, &rh2);
	double total_area = arr.get_total_area();
	std::cout << "Общая площадь: " << total_area << std::endl;
	return 0;
}