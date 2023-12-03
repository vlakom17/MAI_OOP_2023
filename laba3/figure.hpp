#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <vector>

class Figure
{
  friend std::ostream& operator<<(std::ostream& os, const Figure& p);
  friend std::istream& operator>>(std::istream& is, Figure& p);
 
protected:
  Figure() = default;

public:
  virtual ~Figure() = default;

  virtual std::pair<double, double> get_middle_point() const = 0;
  virtual double get_area() const = 0;
  virtual operator double() const {
    return get_area();
  }
private:
  std::vector<std::pair<double, double>> _points;
  std::pair<double, double> _middle_point;
  double _area = 0.0;
  unsigned int n = 0; // количество вершин 
};

#endif