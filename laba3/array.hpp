#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "figure.hpp"

class Array 
{
public:
  // constructors
    Array();
    Array(int size);
    virtual ~Array();

  // methods
    void delete_figure(int n);
    void replace_figure(int n, Figure* figure);
    double get_total_area();

  // operators
    Figure* operator[](int n) const;
private:
    Figure** _figures;
    int _size;
    double total_area;
};
#endif