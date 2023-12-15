#ifndef FIGURE_HPP
#define FIGURE_HPP
#include <string>
#include <iostream>
#include <vector>

// Вершины фигуры подаются на вход по часовой стрелке или против неё
template <class T>
class Figure
{
	template <class T_>
	friend std::ostream& operator<<(std::ostream& os, const Figure<T_>& p);
	template <class T_>
	friend std::ostream& operator>>(std::istream& is, Figure<T_>& p);

	

public:
	std::vector<std::pair<T, T>> points;
    virtual ~Figure() = default;

	std::vector<std::pair<T, T>> get_points() const {
        return points;
    }


	/* 0 говорит, что фукнция сугубо виртуальная, и в каждом 
	унаследованном классе она должна быть реализована */

	virtual explicit operator double() const = 0;

};
#endif