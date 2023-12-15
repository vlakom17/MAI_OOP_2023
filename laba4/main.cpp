#include <iostream>
#include <string>
#include <vector>

#include "hexagon.hpp"
#include "methods.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"
#include "array.hpp"


int main() {
	Hexagon<double> hex_vector, hex_vector2;
	std::cin >> hex_vector;
	std::cin >> hex_vector2;

	//std::vector<std::pair<double, double>> hex_vector{{2, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 3}, {3, 2}};
	//std::vector<std::pair<double, double>> hex_vector2{{3, 1}, {1, 2}, {1, 3}, {3, 4}, {5, 3}, {5, 2}};
	//std::vector<std::pair<double, double>> pent_vector{{2, 1}, {1, 2}, {2, 3}, {3, 3}, {4, 2}};
	Hexagon<double> hex(hex_vector);
	Hexagon<double> hex2(hex_vector2);
	//Pentagon<double> pent(pent_vector);
	//std::cout << pent << std::endl;

	Hexagon<double> hex3;
	std::pair<double, double> pair1;
	std::pair<double, double> pair2;
	pair1.first = 0;
	pair1.second = 0;
	pair2.first = 0;
	pair2.second = 0;
	double area = figures::get_area<Hexagon<double>, double>(hex);
	double area1 = figures::get_area<Hexagon<double>, double>(hex2);
	pair2 = figures::get_middle_point<Hexagon<double>, double>(hex);
	std::shared_ptr<Hexagon<double>> sp_hex = std::make_shared<Hexagon<double>>(hex);
	std::shared_ptr<Hexagon<double>> sp_hex2 = std::make_shared<Hexagon<double>>(hex2);

	Array<Hexagon<double>> array{{sp_hex, sp_hex2}};
	Hexagon<double> out = *array[1];
	std::cout << out << std::endl;


	std::cout << "Areas: " << area << " " << area1 << std::endl << "Middle point: " << pair2.first << " " << pair2.second << std::endl;


	
	std::cout << "Total area: " << array.get_total_area() << std::endl;
}