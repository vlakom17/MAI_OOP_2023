#ifndef PENTAGON_HPP
#define PENTAGON_HPP
#include <string>
#include <iostream>
#include <vector>
#include "methods.hpp"
#include "figure.hpp"

template <typename T>
class Pentagon : public Figure<T>
{
public:
	std::vector<std::pair<double, double>> points;
	unsigned int n = 5; // Количество вершин 
	// Constructors
	Pentagon();
	Pentagon(std::vector<std::pair<T, T>>& _points);
	Pentagon(const Pentagon&);
	Pentagon(Pentagon&& other);
    virtual ~Pentagon();



	// Standard operators
	bool operator==(const Pentagon &other) const;
	Pentagon& operator=(const Pentagon &other);
	Pentagon& operator=(Pentagon &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;


};

template <typename T>

inline std::ostream& operator<<(std::ostream& ostr, const Pentagon<T>& p)
{
    std::vector<std::pair<double, double>> points = p.get_points();

    for (int i = 0; i != 5; ++i) {
        ostr  << points[i].first  << points[i].second << std::endl;
    }
    return ostr;
}
template <typename T>
inline std::istream& operator>>(std::istream& istr, Pentagon<T>& p)
{
    std::vector<std::pair<T, T>> v(5);

    for (int i = 0; i < 5; ++i) {
        istr >> v[i].first >> v[i].second;
    }
    p = Pentagon<T>(v);

    return istr;
}



template <typename T>
Pentagon<T>::Pentagon()
{
	points.resize(n);
}



template <typename T>
Pentagon<T>::Pentagon(std::vector<std::pair<T, T>>& _points) {
	// Points amount check
	if (_points.size() != n) {
		throw std::invalid_argument("Amount error");
	}

	points = _points;
}

template <typename T>
Pentagon<T>::~Pentagon() {}

template <typename T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) const
{
    return points == other.points;
}


template <typename T>
Pentagon<T>::Pentagon(const Pentagon& other) {
    points = other.points;
}

template <typename T>
Pentagon<T>::Pentagon(Pentagon&& other) {
    points = std::move(other.points);
}

template <typename T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T> &other) 
{
	points = other.points;

	return *this;
}


template <typename T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}



template <typename T>
Pentagon<T>::operator double() const {
    return (double)figures::get_area<Pentagon<T>, T>(*this);
}

#endif