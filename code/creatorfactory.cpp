#include "creatorfactory.h"
#include "battlechecker.h"

CreatorFactory::CreatorFactory(std::shared_ptr<BattleChecker> battleChecker, std::shared_ptr<UnitsCollection> unitsCollection, std::shared_ptr<AbstractObserver> logger)
    : battleChecker(battleChecker), unitsCollection(unitsCollection), map(nullptr)
{
    this->logger = logger;
}

std::shared_ptr<Map> CreatorFactory::createMap(Point size)
{
    map =  std::make_shared<Map>(size,logger);
    return map;
}

std::shared_ptr<Warrior> CreatorFactory::createWarrior(int id, int power, const Point &position)
{
    if (!map && !map->InBorder(position))
        return nullptr;
    auto w = std::make_shared<Warrior>(id, power, position, battleChecker, logger);
    unitsCollection->addUnit(w);
    return w;
}

std::shared_ptr<Map> CreatorFactory::getMap() const
{
    return map;
}
