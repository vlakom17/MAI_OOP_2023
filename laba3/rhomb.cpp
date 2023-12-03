#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

#include "rhomb.hpp"

Rhomb::Rhomb() : _area(0)
{
	_points.resize(n);
	_middle_point.first = 0;
	_middle_point.second = 0;
}


Rhomb::Rhomb(std::vector<std::pair<double, double>> &points)
{
	
	// Points amount check
	if (points.size() != n) 
	{
		throw std::invalid_argument("Wrong amount of points");
	}
	

	// Push points to _points and find middle point
	for (int i = 0; i < n; i++)
	{
		_points.push_back(points[i]);
		_middle_point.first += _points.back().first / n;
		_middle_point.second += _points.back().second / n;
	}

	double side1 = std::sqrt(std::pow(_points[0].first - _points[1].first, 2) + std::pow(_points[0].second - _points[1].second, 2));
	double side2 = std::sqrt(std::pow(_points[1].first - _points[2].first, 2) + std::pow(_points[1].second - _points[2].second, 2));
	double side3 = std::sqrt(std::pow(_points[2].first - _points[3].first, 2) + std::pow(_points[2].second - _points[3].second, 2));
	double side4 = std::sqrt(std::pow(_points[3].first - _points[0].first, 2) + std::pow(_points[3].second - _points[0].second, 2));
	
	if (!(is_equal(side1, side2))) {
		throw std::invalid_argument("Its not a rhomb");
	}
	if (!(is_equal(side2, side3))) {
		throw std::invalid_argument("Its not a rhomb");
	}
	if (!(is_equal(side3, side4))) {
		throw std::invalid_argument("Its not a rhomb");
	}
	std::vector<std::pair<double, double>> points2;
	std::pair<double, double> para; para.first = 0; para.second = 0;

	points2.push_back(para);
	for (int i = 0; i < n; i++) {
		points2.push_back(_points[i]);
	}

   
	double s = 0, m = 0;
	for (int i = 1; i <= n - 1; i++)
		s += points2[i].first * points2[i + 1].second;

	s += points2[n].first * points2[1].second;
	for (int i = 1; i <= n - 1; i++)
		m -= points2[i].second * points2[i + 1].first;
	m -= points2[n].second * points2[1].first;

	_area = 0.5 * abs(s + m);
}


Rhomb::~Rhomb() {}

bool Rhomb::operator==(const Rhomb &other) const {
    for (int i = 0; i < n; ++i) {
        if (!is_equal(_points[i].first, other._points[i].first) || !is_equal(_points[i].second, other._points[i].second)) {
            return false;
        }
    }
    return true;
}


Rhomb& Rhomb::operator=(const Rhomb &other) 
{
	_points = other.get_points();
	_middle_point = other.get_middle_point();
	_area = other.get_area();

	return *this;
}

Rhomb& Rhomb::operator=(Rhomb &&other) 
{
   	_points = std::move(other._points);
    _middle_point = std::move(other._middle_point);
    _area = std::move(other._area);

    return *this;
}

Rhomb::operator double() const {
    return get_area();
}