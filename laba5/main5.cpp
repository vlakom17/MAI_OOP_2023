#include <iostream>
#include <memory>
#include <map>
#include "alloc.hpp"
#include "list.hpp"

int main(){

    std::map<int, int, std::less<int>,mai::Allocator<std::pair<const int,int>,10>> my_map;

    my_map[0] = 1;

    for(int i{1}; i < 10; ++i){
        my_map[i] = my_map[i-1] * i;
    }

    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;


    my_stl::List<int,mai::Allocator<int>> my_list;
    my_list.Show(); // показать пустой список
    for(int i{100}; i < 110; ++i){
        my_list.Add(i,0);
    }

    for(auto it = my_list.begin(); it != my_list.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List Size = " << my_list.Size() << std::endl;
    
    my_list.Remove(4);

    std::cout << "Stack after Remove" << std::endl;

    my_list.Show();

    int x = 105;
    my_list.Add(x,2);

    my_list.Show();

    my_stl::List<int,mai::Allocator<int>> st(my_list);

    st.Show();

    return 0;
}