#ifndef UNITSCOLLECTION_H
#define UNITSCOLLECTION_H

#include "unit.h"

class UnitsCollection
{
public:
    UnitsCollection();
    bool addUnit(std::shared_ptr<Unit> unit);
    const std::unordered_set<int>& getUnitsId();
    std::shared_ptr<Unit> getUnit(int id);
    void removeUnit(int id);
private:
    std::unordered_map<int,std::shared_ptr<Unit> > units;
    std::unordered_set<int> ids;
};

#endif // UNITSCOLLECTION_H
