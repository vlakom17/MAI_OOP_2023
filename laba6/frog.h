#ifndef FROG_H
#define FROG_H

#include "npc.h"

struct Frog : public NPC
{
    Frog(int x, int y,std::string &_name);
    Frog(std::ifstream &is,std::string &_name);
    ~Frog();

    void print() override;
    void save(std::ofstream &os) override;

    void get_name(std::ofstream &os) override;

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor);

    void attach(std::shared_ptr<IObserver> observer) override;
    void detach(std::shared_ptr<IObserver> observer) override;

    friend std::ostream &operator<<(std::ostream &os, Frog &frog);
};

#endif // FROG_H