#ifndef BATTLECHECKER_H
#define BATTLECHECKER_H

#include "unitscollection.h"
#include "warrior.h"
#include "battle.h"

//implemetetion of Visiter pattern
class BattleChecker
{
public:
    BattleChecker(std::shared_ptr<UnitsCollection> unitsCollection,std::shared_ptr<AbstractObserver> logger)
        :unitsCollection(unitsCollection),battle(logger){}

    bool checkForWarrior(Warrior *warrior);
    //void checkForArcher()
private:
    std::shared_ptr<UnitsCollection> unitsCollection;
    Battle battle;
};

#endif // BATTLECHECKER_H
