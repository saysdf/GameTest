#ifndef WARRIOR_H
#define WARRIOR_H

#include "unit.h"

class Warrior : public Unit
{
public:
    Warrior(int id, int power, const Point &position, std::shared_ptr<BattleChecker> bc, std::shared_ptr<AbstractObserver>logger);
private:
    virtual bool checkBattle() override;
};

#endif // WARRIOR_H
