#ifndef SCENARIOBUILDER_H
#define SCENARIOBUILDER_H

#include <string>
#include <queue>

#include "creatorfactory.h"
#include "scenariocommand.h"
#include "helper.hpp"

class ScenarioBuilder
{
public:
    ScenarioBuilder(std::shared_ptr<CreatorFactory> factory, std::shared_ptr<UnitsCollection> unitsCollection,std::shared_ptr<int> currentTick)
        : factory(factory), unitsCollection(unitsCollection), currentTick(currentTick)
    {}
    virtual std::queue<std::shared_ptr<ScenarioCommand> > readFile(std::string file)=0;
protected:
    virtual std::shared_ptr<CommandCreateMap>     createMap (const std::string&)=0;
    virtual std::shared_ptr<CommandSetMarch>      createSetMarch (const std::string&)=0;
    virtual std::shared_ptr<CommandCreateWarrior> createCreateWarrior (const std::string&)=0;
    virtual std::shared_ptr<CommandWait>          createWait (const std::string&)=0;
    virtual std::shared_ptr<CommandFinish>        createFinish (const std::string&)=0;
    std::shared_ptr<CreatorFactory> factory;
    std::shared_ptr<UnitsCollection> unitsCollection;
    std::shared_ptr<int> currentTick;
};

class ScenarioBuilderFromText : public ScenarioBuilder
{
public:
    class ScenarioBuilderException :  public std::exception {
    private:
        char * message;
    public:
        ScenarioBuilderException(char * msg) : message(msg) {}
        char * what () {
            return message;
        }
    };
    ScenarioBuilderFromText(std::shared_ptr<CreatorFactory> factory, std::shared_ptr<UnitsCollection> unitsCollection,std::shared_ptr<int> currentTick)
        : ScenarioBuilder(factory,unitsCollection,currentTick)
    {}
    virtual std::queue<std::shared_ptr<ScenarioCommand> > readFile(std::string file);
protected:
    virtual std::shared_ptr<CommandCreateMap>     createMap (const std::string& line);
    virtual std::shared_ptr<CommandSetMarch>      createSetMarch (const std::string& line);
    virtual std::shared_ptr<CommandCreateWarrior> createCreateWarrior (const std::string& line);
    virtual std::shared_ptr<CommandWait>          createWait (const std::string& line);
    virtual std::shared_ptr<CommandFinish>        createFinish (const std::string&);
private:
    enum EventType{
        EWait,
        ECreateMap,
        EUnitSpawn,
        ESetMarch,
        EFinish
    };
};

#endif // SCENARIOBUILDER_H
