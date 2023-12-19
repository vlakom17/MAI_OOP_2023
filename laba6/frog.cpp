#include "dragon.h"
#include "knight.h"
#include "frog.h"
#include <algorithm>

Frog::Frog(int x, int y,std::string &_name) :  NPC(FrogType, x, y, _name) {}

Frog::Frog(std::ifstream &is,std::string &_name) : NPC(FrogType, is, _name) {}

Frog::~Frog() {}

void Frog::print()
{
    std::cout << *this;
}

void Frog::save(std::ofstream &os){
    os << FrogType << std::endl;
    NPC::save(os);
}

void Frog::get_name(std::ofstream &os){
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl;
}

void Frog::attach(std::shared_ptr<IObserver> observer) {
    NPC::observers.push_back(observer);
}
void Frog::detach(std::shared_ptr<IObserver> observer) {
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer));
}

std::ostream &operator<<(std::ostream &os, Frog &frog)
{
    os << "Frog: " << *static_cast<NPC*>(&frog) << std::endl;
    return os;
}