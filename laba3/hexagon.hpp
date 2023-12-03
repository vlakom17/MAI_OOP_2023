#ifndef HEXAGON_HPP
#define HEXAGON_HPP
#include <string>
#include <iostream>
#include <vector>

#include "figure.hpp"


class Hexagon : public Figure
{
  friend std::ostream& operator<<(std::ostream& os, const Hexagon& p);
  friend std::istream& operator>>(std::istream& is, Hexagon& p);
public:
  // Constructors
  Hexagon();
  Hexagon(std::vector<std::pair<double, double>>& points);
    virtual ~Hexagon();


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
  bool operator==(const Hexagon &other) const;
  Hexagon& operator=(const Hexagon &other);
  Hexagon& operator=(Hexagon &&other);

  // explicit в данном случае запрещает случайный неявный вызов оператора преобразования типа
  explicit operator double() const override;

private:
  std::vector<std::pair<double, double>> _points;
  std::pair<double, double> _middle_point;
  double _area = 0;
  unsigned int n = 6; // Количество вершин 
};

inline std::ostream& operator<<(std::ostream& os, const Hexagon& p)
{
    std::vector<std::pair<double, double>> points = p.get_points();
    for (int i = 0; i != 6; ++i) {
        os << points[i].first << points[i].second << std::endl;
    }
    return os;
}

inline std::istream& operator>>(std::istream& is, Hexagon& p)
{
    std::vector<std::pair<double, double>> v(6);

    for (int i = 0; i < 6; ++i) {
        is >> v[i].first >> v[i].second;
    }
    p = Hexagon(v);

    return is;
}
#endif