#include "battle.h"

void Battle::doBattle(Unit *u1, Unit *u2)
{
    log("BATTLE "+std::to_string(u1->getId()) + " " + std::to_string(u2->getId()));
    if (u1->getPower()==u2->getPower()){
        log("ALL DEAD\r\n");
        u1->defeat();
        u2->defeat();
    }
    else if (u1->getPower()>u2->getPower()){
        log("WINNER IS "+std::to_string(u1->getId())+"\r\n");
        u1->victory();
        u2->defeat();
    }
    else{
        log("WINNER IS "+std::to_string(u2->getId())+"\r\n");
        u1->defeat();
        u2->victory();
    }
}
