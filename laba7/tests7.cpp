#include <gtest/gtest.h>
#include <memory>
#include "npc.cpp"
#include "frog.cpp"
#include "dragon.cpp"
#include "knight.cpp"

TEST(test_01, frog_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_02, frog_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x, y);

    EXPECT_EQ((a->position()).second,100);
}

TEST(test_03, frog_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x, y);
    EXPECT_EQ(FrogType,a->get_type());
}

TEST(test_04, frog_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_05, frog_constructor){
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Frog>(x2, y2);
    EXPECT_TRUE(a->is_close(b,100));
}

TEST(test_06, frog_constructor){
    int x{1};
    int y{5};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Frog>(x, y);

    a->move(40,50,100,100);
    EXPECT_EQ((a->position()).first,41);
    EXPECT_EQ((a->position()).second,55);
}

TEST(test_07, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_08, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);

    EXPECT_EQ((a->position()).second,100);
}

TEST(test_09, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);
    EXPECT_EQ(DragonType,a->get_type());
}

TEST(test_10, dragon_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_11, dragon_constructor){
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Frog>(x2, y2);
    EXPECT_TRUE(a->is_close(b,100));
}

TEST(test_12, dragon_constructor){
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Dragon>(x, y);

    a->move(90,50,100,100);
    EXPECT_EQ((a->position()).first,100);
    EXPECT_EQ((a->position()).second,60);
}

TEST(test_13, knight_constructor){
    int x{100};
    int y{25};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    EXPECT_EQ((a->position()).first,100);
}

TEST(test_14, knight_constructor){
    int x{100};
    int y{80};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    EXPECT_EQ((a->position()).second,80);
}

TEST(test_15, knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_EQ(KnightType,a->get_type());
}

TEST(test_16, knight_constructor){
    int x{100};
    int y{100};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);
    EXPECT_TRUE(a->is_alive());
}


TEST(test_17, knight_constructor){
    int x1{100};
    int y1{100};

    int x2{90};
    int y2{90};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x1, y1);

    std::shared_ptr<NPC> b;
    b = std::make_shared<Frog>(x2, y2);
    EXPECT_TRUE(a->is_close(b,100));
}

TEST(test_18, knight_constructor){
    int x{10};
    int y{10};

    std::shared_ptr<NPC> a;
    a = std::make_shared<Knight>(x, y);

    a->move(70,60,100,100);
    EXPECT_EQ((a->position()).first,80);
    EXPECT_EQ((a->position()).second,70);
}