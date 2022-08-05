#ifndef SCENARIOCOMMAND_H
#define SCENARIOCOMMAND_H

#include "creatorfactory.h"

class ScenarioCommand
{
public:
    ScenarioCommand(std::shared_ptr<CreatorFactory> factory, std::shared_ptr<UnitsCollection> unitsCollection)
        : factory(factory), unitsCollection(unitsCollection){}
    virtual ~ScenarioCommand(){}
    virtual void execute()=0;
    virtual bool getReadyForDelete(){return true;}
protected:
    std::shared_ptr<CreatorFactory> factory;
    std::shared_ptr<UnitsCollection> unitsCollection;

};

class CommandCreateMap : public ScenarioCommand
{
public:
    CommandCreateMap(const Point& mapSize, std::shared_ptr<CreatorFactory> factory,
                     std::shared_ptr<UnitsCollection> unitsCollection)
        : ScenarioCommand(factory, unitsCollection), size(mapSize) {}
    virtual void execute();
private:
    Point size;
};

class CommandCreateWarrior : public ScenarioCommand
{
public:
    CommandCreateWarrior(int id,int power,const Point& position,std::shared_ptr<CreatorFactory> factory,
                         std::shared_ptr<UnitsCollection> unitsCollection)
        : ScenarioCommand(factory, unitsCollection),id(id),power(power),pos(position) {}
    virtual void execute();
private:
    int id;
    int power;
    Point pos;
};

class CommandSetMarch : public ScenarioCommand
{
public:
    CommandSetMarch(int id,const Point& position,std::shared_ptr<CreatorFactory> factory,
                    std::shared_ptr<UnitsCollection> unitsCollection)
        : ScenarioCommand(factory, unitsCollection),id(id),target(position) {}
    virtual void execute();
private:
    int id;
    Point target;
};

class CommandWait : public ScenarioCommand
{
public:
    CommandWait(int ticks, std::shared_ptr<int> currentTick, std::shared_ptr<CreatorFactory> factory, std::shared_ptr<UnitsCollection> unitsCollection)
        : ScenarioCommand(factory, unitsCollection), tickTimer(ticks), currentTick(currentTick) {}
    virtual void execute();
    virtual bool getReadyForDelete();
private:
    int tickTimer;
    std::shared_ptr<int> currentTick;
};

class CommandFinish : public ScenarioCommand
{
public:
    CommandFinish(std::shared_ptr<int> currentTick, std::shared_ptr<CreatorFactory> factory, std::shared_ptr<UnitsCollection> unitsCollection)
        : ScenarioCommand(factory, unitsCollection), currentTick(currentTick) {}
    virtual void execute();
    virtual bool getReadyForDelete();
private:
    std::shared_ptr<int> currentTick;
};

#endif // SCENARIOCOMMAND_H
