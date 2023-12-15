#ifndef HEXAGON_HPP
#define HEXAGON_HPP
#include <string>
#include <iostream>
#include <vector>

#include "figure.hpp"
#include "methods.hpp"


template <typename T>
class Hexagon : public Figure<T>
{
public:
	unsigned int n = 6; // Количество вершин 
	std::vector<std::pair<T, T>> points;

	// Constructors
	Hexagon();
	Hexagon(std::vector<std::pair<T, T>>& _points);
	Hexagon(const Hexagon&);
	Hexagon(Hexagon&& other);
    virtual ~Hexagon();


	// Standard operators
	bool operator==(const Hexagon<T> &other) const;
	Hexagon& operator=(const Hexagon<T> &other);
	Hexagon& operator=(Hexagon<T> &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& ostr, const Hexagon<T>& p)
{
    for (const auto& point : p.get_points()) {
        ostr << point.first << point.second;
    }

    return ostr;
}




template <typename T>
inline std::istream& operator>>(std::istream& istr, Hexagon<T> &p)
{
    std::vector<std::pair<T, T>> v(6);

    for (int i = 0; i < 6; ++i) {
        istr >> v[i].first >> v[i].second;
    }
    p = Hexagon<T>(v);

    return istr;
}
 
template <typename T>
Hexagon<T>::Hexagon()
{
	points.resize(n);
}

template <typename T>
Hexagon<T>::Hexagon(std::vector<std::pair<T, T>> &_points) {
	if (_points.size() != n) {
		throw std::invalid_argument("Amount error");
	}

	points = _points;
}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon& other) {
    points = other.points;
}

template <typename T>
Hexagon<T>::Hexagon(Hexagon&& other) {
    points = std::move(other.points);
}


template <typename T>
Hexagon<T>::~Hexagon() {}


template <typename T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const{
    return points == other.points;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T> &other) 
{
	points = other.points;

	return *this;
}

template <typename T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}

template <typename T>
Hexagon<T>::operator double() const {
    return (double)figures::get_area<Hexagon<T>, T>(*this);
}
#endif