#ifndef RHOMB_HPP
#define RHOMB_HPP
#include <string>
#include <iostream>
#include <vector>

#include "figure.hpp"
#include "methods.hpp"


template <typename T>
class Rhomb : public Figure<T>
{
public:
	unsigned int n = 4; // Количество вершин 
	std::vector<std::pair<T, T>> points;

	// Constructors
	Rhomb();
	Rhomb(std::vector<std::pair<T, T>> &_points);
	Rhomb(const Rhomb&);
	Rhomb(Rhomb&& other);
    virtual ~Rhomb();


	// Operators
	bool operator==(const Rhomb<T> &other) const;
	Rhomb& operator=(const Rhomb<T> &other);
	Rhomb& operator=(Rhomb<T> &&other);

	// explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
	explicit operator double() const override;

};

template <typename T>
inline std::ostream& operator<<(std::ostream& ostr, const Rhomb<T>& p)
{
    std::vector<std::pair<T, T>> points = p.get_points();
    for (int i = 0; i < 4; ++i) {
        ostr << points[i].first << points[i].second << std::endl;
    }
    return ostr;
}

template <typename T>
inline std::istream& operator>>(std::istream& istr, Rhomb<T>& p)
{
    std::vector<std::pair<T, T>> v(4);

    for (int i = 0; i < 4; ++i) {

        istr >> v[i].first >> v[i].second;
    }

    p = Rhomb<T>(v);
    return istr;
}



template <typename T>
Rhomb<T>::Rhomb()
{
	points.resize(n);
}

template <typename T>
Rhomb<T>::Rhomb(std::vector<std::pair<T, T>>& _points) {
	
	if (_points.size() != n) {
		throw std::invalid_argument("Amount error");
	}

	points = _points;
}

template <typename T>
Rhomb<T>::Rhomb(const Rhomb& other) {
    points = other.points;
}

template <typename T>
Rhomb<T>::Rhomb(Rhomb&& other) {
    points = std::move(other.points);
}


template <typename T>
Rhomb<T>::~Rhomb() {}


template <typename T>
bool Rhomb<T>::operator==(const Rhomb<T> &other) const
{
    return points == other.points;
}

template <typename T>
Rhomb<T>& Rhomb<T>::operator=(const Rhomb<T> &other) 
{
	points = other.points;

	return *this;
}

template <typename T>
Rhomb<T>& Rhomb<T>::operator=(Rhomb<T> &&other) 
{
   	points = std::move(other.points);

    return *this;
}

template <typename T>
Rhomb<T>::operator double() const {
    return (double)figures::get_area<Rhomb<T>, T>(*this);
}
#endif