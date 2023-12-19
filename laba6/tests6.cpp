#include <gtest/gtest.h>
#include <memory>
#include "observer.cpp"
#include "npc.cpp"
#include "frog.cpp"
#include "dragon.cpp"
#include "knight.cpp"

bool success;

class Visitor{
public:
    virtual int visit(Frog* element) = 0;
    virtual int visit(Dragon* element) = 0;
    virtual int visit(Knight* element) = 0;
};

class ConcreteVisitor1 : public Visitor {
public:

    int visit(Frog* element) override {
        return 1;
    }
    
    int visit(Dragon* element) override {
        return 2;
    }

    int visit(Knight* element) override {
        return 3;
    }
};

void Frog::accept(std::shared_ptr<NPC> attacker, Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Frog*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Frog*>(attacker.get()));
    
    if(res == 1) success = true;
}

void Dragon::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
    int res = 0;
    if(dynamic_cast<Frog*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Frog*>(attacker.get()));
    if(dynamic_cast<Knight*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Knight*>(attacker.get()));
    if(res == 1 || res == 3) success = true;
}

void Knight::accept(std::shared_ptr<NPC> attacker,Visitor& visitor) {
     int res = 0;
    if(dynamic_cast<Frog*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Frog*>(attacker.get()));
    if(dynamic_cast<Dragon*>(attacker.get()))
        res = visitor.visit(dynamic_cast<Dragon*>(attacker.get()));
    if(res == 1 || res == 2) success = true;
}

TEST(test_01, frog_constructor){
    int x{100};
    int y{100};
    std::string name{"Frog_1"};

    std::shared_ptr<NPC> a = std::make_shared<Frog>(x,y,name);


    EXPECT_EQ(100,a->x);
}

TEST(test_02, frog_constructor){
    int x{100};
    int y{100};
    std::string name{"Frog_1"};

    std::shared_ptr<NPC> a = std::make_shared<Frog>(x,y,name);


    EXPECT_EQ(100,a->y);
}

TEST(test_03, frog_constructor){
    int x{100};
    int y{100};
    std::string name{"Frog_1"};

    std::shared_ptr<NPC> a = std::make_shared<Frog>(x,y,name);


    EXPECT_EQ("Frog_1",a->name);
}

TEST(test_04, dragon_constructor){
    int x{200};
    int y{200};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ(200,a->x);
}

TEST(test_05, dragon_constructor){
    int x{100};
    int y{150};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ(150,a->y);
}

TEST(test_06, dragon_constructor){
    int x{100};
    int y{100};
    std::string name{"Dragon_1"};

    std::shared_ptr<NPC> a = std::make_shared<Dragon>(x,y,name);


    EXPECT_EQ("Dragon_1",a->name);
}

TEST(test_07, knight_constructor){
    int x{500};
    int y{0};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> a = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ(500,a->x);
}

TEST(test_08, knight_constructor){
    int x{500};
    int y{0};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> a = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ(0,a->y);
}

TEST(test_09, knight_constructor){
    int x{100};
    int y{100};
    std::string name{"Knight_1"};

    std::shared_ptr<NPC> k = std::make_shared<Knight>(x,y,name);


    EXPECT_EQ("Knight_1",k->name);
}

TEST(test_10, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}


TEST(test_11, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Frog_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Frog>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Frog_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Frog>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}

TEST(test_12, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Frog_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Frog>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}

TEST(test_13, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Frog_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Frog>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_14, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Frog_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Frog>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_TRUE(success);
}

TEST(test_15, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Frog_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Frog>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_16, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Dragon_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Dragon>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_17, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Knight_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Knight>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_2"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_FALSE(success);
}

TEST(test_18, on_fight){

    ConcreteVisitor1 visitor;

    int x1{100};
    int y1{100};
    std::string name1{"Dragon_1"};

    std::shared_ptr<NPC> attacker = std::make_shared<Dragon>(x1,y1,name1);

    int x2{101};
    int y2{101};
    std::string name2{"Knight_1"};

    std::shared_ptr<NPC> defender = std::make_shared<Knight>(x2,y2,name2);

    success = false;
    defender->accept(attacker,visitor);
    EXPECT_EQ(true, success);
}