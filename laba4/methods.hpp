#pragma once
#include <cmath>
#include <utility>
#include "figure.hpp"
namespace figures {
    

	template <class C, typename T>
	std::pair<T, T> get_middle_point(C &cl) {
		std::pair<T, T> middle_point;
		for (int i = 0; i < cl.n; i++)
		{
			middle_point.first += cl.points[i].first / cl.n;
			middle_point.second += cl.points[i].second / cl.n;
		}
		return middle_point;
	}

	template <class C, typename T>
	T get_area(const C &cl) {
		T area = 0;
		std::vector<std::pair<T, T>> points2;
		std::pair<T, T> para; para.first = 0; para.second = 0;

		points2.push_back(para);
		for (int i = 0; i < cl.n; i++) {
			points2.push_back(cl.points[i]);
		}

		double s = 0, m = 0;
		for (int i = 1; i <= cl.n - 1; i++)
			s += points2[i].first * points2[i + 1].second;

		s += points2[cl.n].first * points2[1].second;
		for (int i = 1; i <= cl.n - 1; i++)
			m -= points2[i].second * points2[i + 1].first;
		m -= points2[cl.n].second * points2[1].first;

		area = 0.5 * abs(s + m);
		return area;
	}
}