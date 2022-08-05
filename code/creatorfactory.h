#ifndef CREATORFACTORY_H
#define CREATORFACTORY_H

#include "warrior.h"
#include "map.h"
#include "unitscollection.h"

class CreatorFactory
{
public:
    CreatorFactory(std::shared_ptr<BattleChecker> battleChecker,std::shared_ptr<UnitsCollection> unitsCollection,std::shared_ptr<AbstractObserver> logger);
    std::shared_ptr<Map> createMap(Point size);
    std::shared_ptr<Warrior> createWarrior(int id, int power, const Point &position);
    std::shared_ptr<Map> getMap() const;

public:
    std::shared_ptr<BattleChecker> battleChecker;
    std::shared_ptr<UnitsCollection> unitsCollection;
    std::shared_ptr<AbstractObserver> logger;
    std::shared_ptr<Map> map;
};

#endif // CREATORFACTORY_H
