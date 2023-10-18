#pragma once
#include <iostream>
#include <string>
class Binary
{
public:
    Binary();
    Binary(const size_t &n, unsigned char t = 0);
    Binary(const std::initializer_list< unsigned char> &t);
    Binary(const std::string &t);
    Binary(const Binary& other);
    Binary(Binary&& other) noexcept;
    
    int get_size();
    unsigned char* get_array();
    std::string get_string_value();

    Binary add(const Binary& other);
    Binary remove(const Binary& other);
    bool bigger(const Binary& other);
    bool equals(const Binary& other);
    void print();

    virtual ~Binary() noexcept;
    
private:
    int lsize;
    unsigned char *larray;
};