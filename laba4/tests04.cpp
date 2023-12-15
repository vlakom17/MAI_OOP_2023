#include <gtest/gtest.h>
#include <iostream>

#include "array.hpp"
#include "hexagon.hpp"
#include "pentagon.hpp"
#include "rhomb.hpp"
#include "methods.hpp"

std::vector<std::pair<double, double>> hex_vector{{2, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 3}, {3, 2}};
std::vector<std::pair<double, double>> hex_vector2{{3, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 4}, {4, 3}};
std::vector<std::pair<double, double>> hex_zero_vector{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

TEST(hexagon, default_constructor)
{
	Hexagon<double> hex;
	std::pair<double, double> pair;
	std::pair<double, double> pair2;
	pair.first = 0;
	pair.second = 0;
	pair2.first = 0;
	pair2.second = 0;
	double area = figures::get_area<Hexagon<double>, double>(hex);
	pair2 = figures::get_middle_point<Hexagon<double>, double>(hex);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(pair2, pair);
	ASSERT_EQ(hex.points, hex_zero_vector);
	
}

TEST(hexagon, area1)
{
	Hexagon<double> hex(hex_vector);
	double area = figures::get_area<Hexagon<double>, double>(hex);
	ASSERT_EQ(area, 4);
	ASSERT_EQ(hex.points, hex_vector);
}

TEST(hexagon, area2)
{
	Hexagon<double> hex(hex_zero_vector);
	double area = figures::get_area<Hexagon<double>, double>(hex);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(hex.points, hex_zero_vector);
}

TEST(hexagon, middle_point1)
{
	Hexagon<double> hex(hex_vector);
	std::pair<double, double> pair;
	pair.first = 2;
	pair.second = 2.5;
	std::pair<double, double> middle_point = figures::get_middle_point<Hexagon<double>, double>(hex);
	ASSERT_EQ(middle_point, pair);
	ASSERT_EQ(hex.points, hex_vector);
}

TEST(hexagon, middle_point2)
{
	Hexagon<double> hex(hex_zero_vector);
	std::pair<double, double> pair;
	pair.first = 0;
	pair.second = 0;
	std::pair<double, double> middle_point = figures::get_middle_point<Hexagon<double>, double>(hex);
	ASSERT_EQ(middle_point, pair);
	ASSERT_EQ(hex.points, hex_zero_vector);
}

TEST(hexagon, side_amount)
{
	std::vector<std::pair<double, double>> v(8);

	EXPECT_THROW(Hexagon<double> hex(v), std::invalid_argument);
}

TEST(hexagon, eq_operator)
{
	Hexagon<double> hex1(hex_vector);
	Hexagon<double> hex2(hex_vector);
	Hexagon<double> hex3(hex_vector2);

	ASSERT_EQ(hex1, hex2);
	ASSERT_FALSE(hex1 == hex3);
}

TEST(hexagon, copy_operator)
{
	Hexagon<double> hex1;
	Hexagon<double> hex2(hex_vector);
	Hexagon<double> hex3(hex_vector2);

    hex1 = hex2;
    ASSERT_EQ(hex1, hex2);
    Hexagon<double> hex4;
    hex4 = hex1;
    hex2 = hex3;
    ASSERT_EQ(hex1, hex4);
}

TEST(hexagon, double_cast) {
    Hexagon<double> hex1(hex_vector);
    double a = (double)hex1;
    EXPECT_EQ(a, 4);
}

std::vector<std::pair<double, double>> pent_vector{{2, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 3}};
std::vector<std::pair<double, double>> pent_vector2{{3, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 4}};
std::vector<std::pair<double, double>> pent_zero_vector{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

TEST(pentagon, default_constructor)
{
	Pentagon<double> pent;
	std::pair<double, double> pair;
	std::pair<double, double> pair2;
	pair.first = 0;
	pair.second = 0;
	pair2.first = 0;
	pair2.second = 0;
	double area = figures::get_area<Pentagon<double>, double>(pent);
	pair2 = figures::get_middle_point<Pentagon<double>, double>(pent);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(pair2, pair);
	ASSERT_EQ(pent.points, pent_zero_vector);
	
}

TEST(pentagon, area1)
{
	Pentagon<double> pent(pent_vector);
	double area = figures::get_area<Pentagon<double>, double>(pent);
	ASSERT_EQ(area, 3.5);
	ASSERT_EQ(pent.points, pent_vector);
}

TEST(pentagon, area2)
{
	Pentagon<double> pent(pent_zero_vector);
	double area = figures::get_area<Pentagon<double>, double>(pent);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(pent.points, pent_zero_vector);
}


TEST(pentagon, middle_point2)
{
	Pentagon<double> pent(pent_zero_vector);
	std::pair<double, double> pair;
	pair.first = 0;
	pair.second = 0;
	std::pair<double, double> middle_point = figures::get_middle_point<Pentagon<double>, double>(pent);
	ASSERT_EQ(middle_point, pair);
	ASSERT_EQ(pent.points, pent_zero_vector);
}

TEST(pentagon, side_amount)
{
	std::vector<std::pair<double, double>> v(9);

	EXPECT_THROW(Pentagon<double> pent(v), std::invalid_argument);
}

TEST(pentagon, eq_operator)
{
	Pentagon<double> pent1(pent_vector);
	Pentagon<double> pent2(pent_vector);
	Pentagon<double> pent3(pent_vector2);

	ASSERT_EQ(pent1, pent2);
	ASSERT_FALSE(pent1 == pent3);
}

TEST(pentagon, copy_operator)
{
	Pentagon<double> pent1;
	Pentagon<double> pent2(pent_vector);
	Pentagon<double> pent3(pent_vector2);

    pent1 = pent2;
    ASSERT_EQ(pent1, pent2);
    Pentagon<double> pent4;
    pent4 = pent1;
    pent2 = pent3;
    ASSERT_EQ(pent1, pent4);
}

TEST(pentagon, double_cast) {
    Pentagon<double> pent1(pent_vector);
    double a = (double)pent1;
    EXPECT_EQ(a, 3.5);
}


std::vector<std::pair<double, double>> rhomb_vector{{2, 1}, {1, 2}, {2, 3}, {3, 2}};
std::vector<std::pair<double, double>> rhomb_vector2{{3, 2}, {2, 3}, {3, 4}, {4, 3}};
std::vector<std::pair<double, double>> rhomb_zero_vector{{0, 0}, {0, 0}, {0, 0}, {0, 0}};

TEST(rhomb, default_constructor)
{
	Rhomb<double> rhomb;
	std::pair<double, double> pair;
	std::pair<double, double> pair2;
	pair.first = 0;
	pair.second = 0;
	pair2.first = 0;
	pair2.second = 0;
	double area = figures::get_area<Rhomb<double>, double>(rhomb);
	pair2 = figures::get_middle_point<Rhomb<double>, double>(rhomb);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(pair2, pair);
	ASSERT_EQ(rhomb.points, rhomb_zero_vector);
	
}

TEST(rhomb, area1)
{
	Rhomb<double> rhomb(rhomb_vector);
	double area = figures::get_area<Rhomb<double>, double>(rhomb);
	ASSERT_EQ(area, 2);
	ASSERT_EQ(rhomb.points, rhomb_vector);
}

TEST(rhomb, area2)
{
	Rhomb<double> rhomb(rhomb_zero_vector);
	double area = figures::get_area<Rhomb<double>, double>(rhomb);
	ASSERT_EQ(area, 0);
	ASSERT_EQ(rhomb.points, rhomb_zero_vector);
}

TEST(rhomb, middle_point1)
{
	Rhomb<double> rhomb(rhomb_vector);
	std::pair<double, double> pair;
	pair.first = 2;
	pair.second = 2;
	std::pair<double, double> middle_point = figures::get_middle_point<Rhomb<double>, double>(rhomb);
	ASSERT_EQ(middle_point, pair);
	ASSERT_EQ(rhomb.points, rhomb_vector);
}

TEST(rhomb, middle_point2)
{
	Rhomb<double> rhomb(rhomb_zero_vector);
	std::pair<double, double> pair;
	pair.first = 0;
	pair.second = 0;
	std::pair<double, double> middle_point = figures::get_middle_point<Rhomb<double>, double>(rhomb);
	ASSERT_EQ(middle_point, pair);
	ASSERT_EQ(rhomb.points, rhomb_zero_vector);
}

TEST(rhomb, side_amount)
{
	std::vector<std::pair<double, double>> v(10);

	EXPECT_THROW(Rhomb<double> rhomb(v), std::invalid_argument);
}

TEST(rhomb, eq_operator)
{
	Rhomb<double> rhomb1(rhomb_vector);
	Rhomb<double> rhomb2(rhomb_vector);
	Rhomb<double> rhomb3(rhomb_vector2);

	ASSERT_EQ(rhomb1, rhomb2);
	ASSERT_FALSE(rhomb1 == rhomb3);
}

TEST(rhomb, copy_operator)
{
	Rhomb<double> rhomb1;
	Rhomb<double> rhomb2(rhomb_vector);
	Rhomb<double> rhomb3(rhomb_vector2);

    rhomb1 = rhomb2;
    ASSERT_EQ(rhomb1, rhomb2);
    Rhomb<double> rhomb4;
    rhomb4 = rhomb1;
    rhomb2 = rhomb3;
    ASSERT_EQ(rhomb1, rhomb4);
}

TEST(rhomb, double_cast) {
    Rhomb<double> rhomb1(rhomb_vector);
    double a = (double)rhomb1;
    EXPECT_EQ(a, 2);
}

TEST(array, default_constructor) {
	Array<Hexagon<double>> arr;

	ASSERT_EQ(arr.get_total_area(), 0);
	EXPECT_THROW(arr.delete_figure(1), std::invalid_argument);
}

TEST(array, replace_figure) {
	Rhomb<double> rh(rhomb_vector);
	Rhomb<double> rh2(rhomb_vector2);
	std::shared_ptr<Rhomb<double>> sp_rhomb = std::make_shared<Rhomb<double>>(rh);
	std::shared_ptr<Rhomb<double>> sp_rhomb2 = std::make_shared<Rhomb<double>>(rh2);

	Array<Rhomb<double>> arr{{sp_rhomb, sp_rhomb2}};

	ASSERT_EQ(arr.get_total_area(), 4);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}