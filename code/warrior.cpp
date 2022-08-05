#include "warrior.h"
#include "battlechecker.h"

Warrior::Warrior(int id, int power, const Point &position, std::shared_ptr<BattleChecker> bc, std::shared_ptr<AbstractObserver> logger) :
    Unit(id,power,position,bc,logger)
{
    log("#WARRIOR SPAWNED "+std::to_string(id)+" ON "+ Helper::ptostr(position) + "\r\n");
}

bool Warrior::checkBattle()
{
    return battleChecker->checkForWarrior(this);
}
