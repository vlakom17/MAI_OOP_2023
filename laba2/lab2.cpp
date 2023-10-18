#include <iostream>
#include <string>
#include "binary.h"

int main(){
    Binary a {'1','0','0','0','0','0','1'};
    std::cout << "a = ";
    a.print();

    Binary b{'1','0','1'};
    std::cout << "b = ";
    b.print();

    Binary c(a.add(b));
    std::cout << "c = a + b = ";
    c.print();

    Binary d {"1001"};
    std::cout << "d = ";
    d.print();

    Binary g {"1"};
    std::cout << "g = ";
    g.print();

    try{
        d.remove(b);
        std::cout << "d - b = ";
        d.print();

    } catch(std::exception &ex){
        std::cerr << "exception:" << ex.what() << std::endl;
    }
    try{
        g.remove(d);
        std::cout << "g - d = ";
        g.print();
    } catch(std::exception &ex){
        std::cerr << "exception: " << ex.what() << std::endl;
    }
}
