#include <gtest/gtest.h>
#include "lab1.h"

int s;

TEST(test_01, basic_test_set)
{
    s = 0;
    ASSERT_TRUE(is_clean(s)==true);
}

TEST(test_02, basic_test_set)
{
    s = 123;
    ASSERT_TRUE(is_clean(s)==true);
}

TEST(test_03, basic_test_set)
{
    s = 454;
    ASSERT_TRUE(is_clean(s)==false);
}

TEST(test_04, basic_test_set)
{
    s = 777;
    ASSERT_TRUE(is_clean(s)==true);
}

TEST(test_05, basic_test_set)
{
    s = 123345;
    ASSERT_TRUE(is_clean(s)==true);
}

TEST(test_06, basic_test_set)
{
    s = -5444;
    ASSERT_TRUE(is_clean(s)==false);
}

TEST(test_07, basic_test_set)
{
    s = -543;
    ASSERT_TRUE(is_clean(s)==false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}