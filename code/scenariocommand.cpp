#include "scenariocommand.h"

void CommandCreateMap::execute()
{
    factory->createMap(size);
}

void CommandCreateWarrior::execute()
{
    factory->createWarrior(id,power,pos);
}

void CommandSetMarch::execute()
{
    if (!factory->getMap() && !factory->getMap()->InBorder(target))
        return;
    auto unit = unitsCollection->getUnit(id);
    if (nullptr == unit)
        return;
    unit->setMarch(target);
}

void CommandWait::execute()
{
    if (tickTimer>0){
        --tickTimer;
        (*currentTick)+=1;
        auto ids = unitsCollection->getUnitsId();
        for (auto id : ids){
            auto unit = unitsCollection->getUnit(id);
            if (dynamic_cast<UnitDead*>(unit->getState())){
                unitsCollection->removeUnit(id);
            }else{
                unit->move();
            }
        }
    }
}

bool CommandWait::getReadyForDelete()
{
    if (tickTimer<=0)
        return true;
    return false;
}

void CommandFinish::execute()
{
    (*currentTick)+=1;
    auto ids = unitsCollection->getUnitsId();
    for (auto id : ids){
        auto unit = unitsCollection->getUnit(id);
        if (dynamic_cast<UnitDead*>(unit->getState())){
            unitsCollection->removeUnit(id);
        }else{
            unit->move();
        }
    }
}

bool CommandFinish::getReadyForDelete()
{
    auto ids = unitsCollection->getUnitsId();
    for (auto id : ids){
        auto unit = unitsCollection->getUnit(id);
        if (dynamic_cast<UnitInMarch*>(unit->getState()) ||
                dynamic_cast<UnitRetreat*>(unit->getState()) ){
            return false;
        }
    }
    factory->logger->slot("#FINISH\r\n");
    return true;
}
