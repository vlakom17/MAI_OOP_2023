#include <gtest/gtest.h>
#include "Binary.cpp"

// Constructor tests

TEST(constructor_test01, default_constructor)
{
    Binary a = Binary();
    std::string b{'0'};

    EXPECT_EQ(a.get_string_value(), b);
    EXPECT_EQ(a.get_size(), 1);
}

TEST(constructor_test02, fill_constructor)
{
    Binary a = Binary(5,'1');
    std::string b{"11111"};

    EXPECT_EQ(a.get_string_value(), b);
    EXPECT_EQ(a.get_size(),5);
}

TEST(constructor_test03, initializer_list_constructor)
{
    Binary a {'1','0','0','1','1'};
    std::string b{"11001"};

    EXPECT_EQ(a.get_string_value(), b);
    EXPECT_EQ(a.get_size(), 5);
}

TEST(constructor_test04, string_constructor)
{
    std::string str = "10111";
    Binary a = Binary(str);

    std::string b{"11101"};

    EXPECT_EQ(a.get_string_value(), b);
    EXPECT_EQ(a.get_size(), 5);
}

TEST(constructor_test05, copy_constructor)
{
    Binary first {'0','1','1','1','1'};
    Binary second = Binary(first);

    std::string b{"11110"};

    EXPECT_EQ(second.get_string_value(), b);
    EXPECT_EQ(second.get_size(), 5);
}

TEST(constructor_test06, rvalue_constructor)
{
    Binary a = {"1111"};
    std::string b{"1111"};

    EXPECT_EQ(a.get_string_value(), b);
    EXPECT_EQ(a.get_size(), 4);
}

TEST(constructor_test07, error_input)
{
    try{
        Binary a {"1ab74"};
    }catch(std::exception &ex){
        EXPECT_STREQ(ex.what(),"not correct input");
    }
}

// Operators testing
TEST(op_test01, basic_test_set)
{
    // 1000 + 1 = 1001
    Binary a {"0001"};
    Binary b {'1'};
    Binary c {"1001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(op_test02, basic_test_set)
{
    // 11001 + 11001 = 110010
    Binary a {"10011"};
    Binary b {"10011"};
    Binary c {"010011"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(op_test03, basic_test_set)
{
    // 1111 + 101 = 10100
    Binary a {"1111"};
    Binary b {"101"};
    Binary c {"00101"};
    ASSERT_TRUE(c.equals(a.add(b)));
}


TEST(op_test04, basic_test_set)
{
    // 1011 + 1110 = 11001
    Binary a {"1101"};
    Binary b {"0111"};
    Binary c {"10011"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(op_test05, basic_test_set)
{
    // 1 - 11 = exception
    Binary a {"1"};
    Binary b {"11"};
    try{
        a.remove(b);
    }catch(std::exception &ex){
        EXPECT_STREQ(ex.what(),"negative balance");
    }
}

TEST(op_test06, basic_test_set)
{
    // 11000 - 1 = 10111
    Binary a {"00011"};
    Binary b {"1"};
    Binary c {"11101"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(op_test07, basic_test_set)
{
    // 1010101 - 1010101 = 0
    Binary a {"1010101"};
    Binary b {"1010101"};
    Binary c {"0"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(op_test08, basic_test_set)
{
    // 1 - 0 = 1
    Binary a {"1"};
    Binary b {"0"};
    Binary c {"1"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(op_test09, basic_test_set)
{
    // 0 - 0 = 0
    Binary a {"0"};
    Binary b {"0"};
    Binary c {"0"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(op_test10, basic_test_set)
{
    // 0 + 11011 = 11011
    Binary a  = Binary();
    Binary b {"11011"};
    Binary c {"11011"};
    ASSERT_TRUE(c.equals(a.add(b)));
}