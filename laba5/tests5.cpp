#include <gtest/gtest.h>
#include <map>
#include <vector>
#include "alloc.hpp"
#include "list.hpp"

TEST(allocator_01, map_alloc_test)
{
    std::map<int, int, std::less<int>,mai::Allocator<std::pair<const int,int>,11>> my_map;

    my_map[0] = 1;

    for(int i{1}; i <= 10; ++i){
        my_map[i] = my_map[i-1] * i;
    }

    EXPECT_EQ(24,my_map[4]);
}

TEST(allocator_02, vector_alloc_test)
{
    std::vector<int, mai::Allocator<int>> vec;

    vec.push_back(1);

    EXPECT_EQ(1, vec[0]);
}

TEST(list_01, list_based_constructor01)
{
    my_stl::List<int> lst;

    EXPECT_EQ(0,lst.Size());
}

TEST(list_02, list_based_constructor02)
{
    my_stl::List<int> lst;

    EXPECT_EQ(true, lst.IsEmpty());
}

TEST(list_03, list_based_constructor03)
{
    my_stl::List<int> lst;

    for(int i{0}; i < 10; ++i){
        lst.Add(i,0);
    }

    EXPECT_EQ(10, lst.Size());
}

TEST(list_04, list_based_constructor04)
{
    my_stl::List<int> lst;

    for(int i{0}; i < 10; ++i){
        lst.Add(i,0);
    }

    EXPECT_EQ(9, lst.Head());
}

TEST(list_05, list_based_constructor05)
{
    my_stl::List<int> lst;

    for(int i{0}; i < 10; ++i){
        lst.Add(i,0);
    }

    lst.Remove(4);

    EXPECT_EQ(9, lst.Size());
    EXPECT_EQ(false, lst.IsEmpty());
}

TEST(list_06, list_copy_constructor01)
{
    my_stl::List<int> ls1;

    for(int i{0}; i < 10; ++i){
        ls1.Add(i,0);
    }

    my_stl::List<int> ls2(ls1);

    EXPECT_EQ(10, ls2.Size());
}


TEST(list_07, list_copy_constructor02)
{
    my_stl::List<int> ls1;

    for(int i{0}; i < 10; ++i){
        ls1.Add(i,ls1.Size());
    }

    my_stl::List<int> ls2(ls1);

    ls2.Add(-1,0);

    EXPECT_EQ(10, ls1.Size());
    EXPECT_EQ(11, ls2.Size());
}

TEST(list_08, list_move_constructor01)
{
    my_stl::List<int> ls1;

    for(int i{0}; i < 10; ++i){
        ls1.Add(i,ls1.Size());
    }

    my_stl::List<int> ls2(std::move(ls1));

    EXPECT_EQ(10, ls2.Size());
}


TEST(list_09, list_copy_operation)
{
    my_stl::List<int> ls1;

    for(int i{0}; i < 10; ++i){
        ls1.Add(i, 0);
    }

    my_stl::List<int> ls2 = ls1;

    ls2.Remove(1);

    EXPECT_EQ(9, ls2.Size());
}

TEST(list_10, Iterator_01)
{
    my_stl::List<int> ls;

    for(int i{0}; i < 10; ++i){
        ls.Add(i, ls.Size());
    }

    auto it = ls.begin();

    EXPECT_EQ(0, *it);
}

TEST(list_11, Iterator_02)
{
    my_stl::List<int> ls;

    for(int i{0}; i < 10; ++i){
        ls.Add(i, 0);
    }

    auto it = ls.begin();
    EXPECT_EQ(9, *it);

    it++;
    EXPECT_EQ(8, *it);

    it++;
    EXPECT_EQ(7, *it);
}

TEST(list_12, CosntIterator_01)
{
    my_stl::List<int> ls;

    for(int i{0}; i < 10; ++i){
        ls.Add(i, 0);
    }

    auto it = ls.cbegin();

    EXPECT_EQ(9, *it);
}

TEST(list_13, ConstIterator_02)
{
    my_stl::List<int> ls;

    for(int i{0}; i < 10; ++i){
        ls.Add(i, 0);
    }

    auto it = ls.cbegin();
    EXPECT_EQ(9, *it);

    it++;
    EXPECT_EQ(8, *it);

    it++;
    EXPECT_EQ(7, *it);
}