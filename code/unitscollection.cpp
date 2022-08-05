#include "unitscollection.h"

UnitsCollection::UnitsCollection()
{

}

bool UnitsCollection::addUnit(std::shared_ptr<Unit> unit)
{
    if (units.count(unit->getId()))
        return false;
    units[unit->getId()]=unit;
    ids.insert(unit->getId());
    return true;
}

const std::unordered_set<int>& UnitsCollection::getUnitsId()
{
    return ids;
}

std::shared_ptr<Unit> UnitsCollection::getUnit(int id)
{
    if (!units.count(id))
        return nullptr;
    return units[id];
}

void UnitsCollection::removeUnit(int id)
{
    units.erase(id);
    ids.erase(id);
}

