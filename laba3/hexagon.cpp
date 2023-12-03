#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>


#include "hexagon.hpp"

Hexagon::Hexagon() : _area(0)
{
	_points.resize(n);
	_middle_point.first = 0;
	_middle_point.second = 0;
}


Hexagon::Hexagon(std::vector<std::pair<double, double>> &points)
{
	
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

Hexagon::~Hexagon() {}

bool Hexagon::operator==(const Hexagon &other) const
{
    return _points == other._points;
}


Hexagon& Hexagon::operator=(const Hexagon &other) 
{
	_points = other.get_points();
	_middle_point = other.get_middle_point();
	_area = other.get_area();

	return *this;
}

Hexagon& Hexagon::operator=(Hexagon &&other) 
{
   	_points = std::move(other._points);
    _middle_point = std::move(other._middle_point);
    _area = std::move(other._area);

    return *this;
}

Hexagon::operator double() const {
    return get_area();
}