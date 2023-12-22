#include "frog.h"
#include "dragon.h"
#include "knight.h"

Frog::Frog(int x, int y) : NPC(FrogType, x, y) {}
Frog::Frog(std::istream &is) : NPC(FrogType, is) {}

bool Frog::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Frog>(this,[](Frog*){}));
}

void Frog::print()
{
    std::cout << *this;
}

void Frog::save(std::ostream &os)
{
    os << FrogType << std::endl;
    NPC::save(os);
}


bool Frog::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return true;
}

bool Frog::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

bool Frog::fight(std::shared_ptr<Frog> other)
{
    fight_notify(other, false);
    return true;
}

std::ostream &operator<<(std::ostream &os, Frog &Frog)
{
    os << "Frog: " << *static_cast<NPC *>(&Frog) << std::endl;
    return os;
}