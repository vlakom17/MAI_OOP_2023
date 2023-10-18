#include <cstring>
#include "binary.h"

// Конструктор создания (тривиальный случай)
Binary::Binary(): lsize(1)
{
    larray = new unsigned char [1];
    larray[0] = '0';
}

// Конструктор заполнения
Binary::Binary(const size_t &n, unsigned char t)
{
    if(t < '0' or t > '1') throw std::logic_error("not correct input");
    larray = new unsigned char[n];
    for (int i{0}; i < n; ++i)
        larray[i] = t;
    lsize = n;
}

// Конструктор создания массива
Binary::Binary(const std::initializer_list<unsigned char> &t)
{
    larray = new unsigned char[t.size()];
    int i = 0;
    for (auto el : t)
        larray[i++] = el;
    lsize = t.size();
}

// Конструктор копирования строки
Binary::Binary(const std::string &t)
{
    larray = new unsigned char[t.size()];
    lsize  = t.size();

    for(int i = 0; i<lsize; ++i) larray[i] = t[i];
}

// Конструктор копирования
Binary::Binary(const Binary &other)
{
    lsize  = other.lsize;
    larray = new unsigned char[lsize];

    for(int i = 0;i<lsize;++i) larray[i] = other.larray[i];
}

// Rvalue конструктор
Binary::Binary(Binary &&other) noexcept
{
    lsize = other.lsize;
    larray = other.larray;

    other.lsize = 0;
    other.larray = nullptr;
}

// Размер 
int Binary::get_size(){
    return lsize;
}

// Получить указатель на массив
unsigned char* Binary::get_array(){
    return larray;
}

// Получить строку
std::string Binary::get_string_value(){
    std::string res = "";

    for (int i{lsize - 1}; i >= 0; --i) {
        res += larray[i];
    }

    return res;
}



// Равенство двух объектов
bool Binary::equals(const Binary &other){
    if (lsize > other.lsize){
        return false;
    }
    else if(lsize < other.lsize){
        return false;
    }
    else{
        for(int i{lsize-1};i>=0;--i){
            if(larray[i] != other.larray[i])
                return false;
        }
    }
    return true;
}

// Сравнение (true, если данный объект больше)
bool Binary::bigger(const Binary &other){
    if (lsize > other.lsize){
        return true;
    }
    else if(lsize < other.lsize){
        return false;
    }
    else{
        for(int i{lsize-1};i>=0;--i){
            if(larray[i] > other.larray[i])
                return true;
        }
    }
    return false;
}

// Сложение
Binary Binary::add(const Binary &other)
{
    // При сложении может меняться размерность массива
    lsize = std::max(lsize,other.lsize);

    unsigned char* lnew_array = new unsigned char [lsize];
    memcpy(lnew_array,larray,lsize);

    int ost = 0; // Остаток

    for(int i{0}; i < lsize; ++i){

        if( lnew_array[i] < '0' or lnew_array[i] > '1') { lnew_array[i] = '0';}
        if( other.larray[i] < '0' or other.larray[i] > '1'){ other.larray[i] = '0';}

        int s = (lnew_array[i] - '0') + (other.larray[i] - '0') + ost;
        ost = s/2;
        lnew_array[i] = '0' + s%2;
    }

    if(ost){
        // Если всё ещё есть остаток, то у числа увеличится разряд
        larray = new unsigned char [lsize+1];
        memcpy(larray,lnew_array,lsize);
        lsize++;
        larray[lsize-1] = '0' + ost;
    }
    else{
        larray = new unsigned char [lsize+1];
        memcpy(larray,lnew_array,lsize);
    }

    delete[] lnew_array;

    return *this;
}

// Вычитание
Binary Binary::remove(const Binary &other){
    if( this->equals(other)){
        larray[0] = '0';
        lsize = 1;
    }
    else if(!this->bigger(other)){
        throw std::logic_error("negative balance");
    }
    else{
        unsigned char* lnew_array = new unsigned char [lsize];
        memcpy(lnew_array,other.larray, other.lsize);
    
        for(int i{0}; i<lsize; i++){

            if(lnew_array[i] < '0' or lnew_array[i] > '1') {lnew_array[i] = '0';}
            
            if(larray[i] >= lnew_array[i]){
                // Если уменьшаемое больше вычитаемого
                larray[i] = (larray[i] - lnew_array[i]) + '0'; 
            }
            else{
                // Если уменьшаемое меньше вычитаемого
                int tmp {i+1};

                while(larray[tmp] == '0'){
                    tmp++;
                }

                larray[tmp] = '0' + (larray[tmp] - '1');
                --tmp;

                larray[i] = (((larray[i] - '0') - (lnew_array[i] - '0')) + 2) + '0';

                while(tmp != i){
                    larray[tmp] = '1';
                    --tmp;
                }
            }
        }

        delete[] lnew_array;
        
        while(larray[lsize - 1] == '0' and lsize > 0){
            --lsize;
        }
    }
    return *this;
}

// Печать
void Binary::print(){
    if(lsize == 1){
        std::cout << larray[0];
    }
    else{
        for(int i{lsize-1};i>=0; i--){
            std::cout<<larray[i];
        }
    }
    std::cout << std::endl;
}

// Деструктор
Binary::~Binary() noexcept
{
    if (lsize > 0)
    {
        lsize = 0;
        delete[] larray;
        larray = nullptr;
    }
}