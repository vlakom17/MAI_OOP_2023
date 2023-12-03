#ifndef RHOMB_HPP
#define RHOMB_HPP
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

#include "figure.hpp"


class Rhomb : public Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Rhomb& p);
	friend std::istream& operator>>(std::istream& is, Rhomb& p);
public:
	// Constructors
	Rhomb();
	Rhomb(std::vector<std::pair<double, double>>& points);
    ~Rhomb();


	// Getters
	std::vector<std::pair<double, double>> get_points() const {
		return _points;
	}

	std::pair<double, double> get_middle_point() const override {
		return _middle_point;
	}

	double get_area() const override {
		return _area;
	}

	// Standard operators
	bool operator==(const Rhomb &other) const;
	Rhomb& operator=(const Rhomb &other);
	Rhomb& operator=(Rhomb &&other);

	explicit operator double() const override;

private:
	std::vector<std::pair<double, double>> _points;
	std::pair<double, double> _middle_point;
	double _area = 0;
	unsigned int n = 4; // Количество вершин 

	static bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

};

inline std::ostream& operator<<(std::ostream& os, const Rhomb& p) {
    std::vector<std::pair<double, double>> points = p.get_points();
    for (int i = 0; i != 4; ++i) {
        os << points[i].first << points[i].second << std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Rhomb& p) {
    std::vector<std::pair<double, double>> v(4);

    for (int i = 0; i < 4; ++i) {

        is >> v[i].first >> v[i].second;
    }

    p = Rhomb(v);
    return is;
}

#endif