#include "array.hpp"

Array::Array() 
{
    _size = 950;
    _figures = new Figure*[_size];

    for (int i = 0; i < _size; ++i)
        _figures[i] = nullptr;
    total_area = 0.0;
}

Array::Array(int size) 
{
    _size = size;
    _figures = new Figure*[_size];

    for (int i = 0; i < _size; ++i)
        _figures[i] = nullptr;
    total_area = 0.0;
}

Array::~Array(){}



Figure* Array::operator[](int i) const
{
    if (i >= _size)
        throw std::invalid_argument("Out of range");

    return _figures[i];
}

void Array::delete_figure(int i){
    if (i >= _size) throw std::out_of_range("Out of range");
    if(_figures[i] != nullptr){
        total_area -= _figures[i]->get_area();
        delete _figures[i];
        _figures[i] = nullptr;
    }
}
   
   


void Array::replace_figure(int i, Figure* figure)
{
    if (i >= _size)
        throw std::invalid_argument("Out of range");
    if(_figures[i] != nullptr){
        total_area -= _figures[i]->get_area();
        delete _figures[i];
    }
    _figures[i] = figure;
    total_area += figure->get_area();
    
}
double Array::get_total_area() {
    return total_area;
}