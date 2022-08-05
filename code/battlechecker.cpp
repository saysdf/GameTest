#include "battlechecker.h"

bool BattleChecker::checkForWarrior(Warrior* warrior)
{
    Point p = warrior->getPosition();
    auto ids = unitsCollection->getUnitsId();
    for (auto id : ids){
        if (id == warrior->getId())
            continue;
        auto unit = unitsCollection->getUnit(id);
        if (unit->getPosition() == p){
            if (dynamic_cast<UnitReady*>(unit->getState())) {
                battle.doBattle(dynamic_cast<Unit*>(warrior),unit.get());
                return true;
            }
        }
    }
    return false;
}
