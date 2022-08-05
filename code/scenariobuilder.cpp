#include "scenariobuilder.h"
#include <unordered_map>
#include <fstream>

std::queue<std::shared_ptr<ScenarioCommand> > ScenarioBuilderFromText::readFile(std::string file)
{
    try {
        std::ifstream infile(file);
        std::string line;
        std::queue<std::shared_ptr<ScenarioCommand> >  eventQueue;
        //map for switch case
        std::unordered_map<std::string,EventType> eventsMap{{"CREATE_MAP",EventType::ECreateMap},
                                                            {"SPAWN",EventType::EUnitSpawn},
                                                            {"MARCH",EventType::ESetMarch},
                                                            {"WAIT",EventType::EWait},
                                                            {"FINISH",EventType::EFinish}};
        int commandNumber = 0;
        while (std::getline(infile, line))
        {

            auto stringListWithoutComment = Helper::split(line,"//");
            if (stringListWithoutComment.empty())
                continue;
            std::string stringWithoutComment = stringListWithoutComment[0];
            auto found = stringWithoutComment.find(' ');
            if (std::string::npos == found)
                continue;
            std::string command;
            command = stringWithoutComment.substr(0,found);
            if (0 == eventsMap.count(command)){
                throw ScenarioBuilderException((char*)"Undefiend command");
            }
            EventType et = eventsMap[command];
            switch (et) {
            case EWait:
                eventQueue.push(createWait(stringWithoutComment));
                break;
            case ECreateMap:
                if (commandNumber!=0){
                    throw ScenarioBuilderException((char*)"Trying create map not in first command");
                }
                eventQueue.push(createMap(stringWithoutComment));
                 break;
            case EUnitSpawn:
                eventQueue.push(createCreateWarrior(stringWithoutComment));
                break;
            case ESetMarch:
                eventQueue.push(createSetMarch(stringWithoutComment));
                break;
            case EFinish:
                eventQueue.push(createFinish(stringWithoutComment));
                break;
            }
        }
        return eventQueue;
    } catch (ScenarioBuilderException &e) {
        return std::queue<std::shared_ptr<ScenarioCommand> > ();
    }
}

std::shared_ptr<CommandCreateMap> ScenarioBuilderFromText::createMap(const std::string & line)
{
    auto stringList = Helper::split(line," ");
    if (stringList.size()<3)
        throw ScenarioBuilderException((char*)"Create map command arguments less than 3");
    Point size = Point(std::stoi(stringList[1]),std::stoi(stringList[2]));
    return std::make_shared<CommandCreateMap>(size,factory,unitsCollection);
}

std::shared_ptr<CommandSetMarch> ScenarioBuilderFromText::createSetMarch(const std::string & line)
{
    auto stringList = Helper::split(line," ");
    if (stringList.size()<4)
        throw ScenarioBuilderException((char*)"Set march command arguments less than 4");
    int id = std::stoi(stringList[1]);
    Point target = Point(std::stoi(stringList[2]),std::stoi(stringList[3]));
    return std::make_shared<CommandSetMarch>(id,target,factory,unitsCollection);
}

std::shared_ptr<CommandCreateWarrior> ScenarioBuilderFromText::createCreateWarrior(const std::string & line)
{
    auto stringList = Helper::split(line," ");
    if (stringList.size()<5)
        throw ScenarioBuilderException((char*)"Create warrior command arguments less than 5");
    int id = std::stoi(stringList[1]);
    Point pos = Point(std::stoi(stringList[2]),std::stoi(stringList[3]));
    int power = std::stoi(stringList[4]);
    return std::make_shared<CommandCreateWarrior>(id,power,pos,factory,unitsCollection);
}

std::shared_ptr<CommandWait> ScenarioBuilderFromText::createWait(const std::string & line)
{
    auto stringList = Helper::split(line," ");
    if (stringList.size()<2)
        throw ScenarioBuilderException((char*)"Wait command arguments less than 2");
     int ticks=std::stoi(stringList[1]);
     return std::make_shared<CommandWait>(ticks,currentTick,factory,unitsCollection);
}

std::shared_ptr<CommandFinish> ScenarioBuilderFromText::createFinish(const std::string &)
{
     return std::make_shared<CommandFinish>(currentTick,factory,unitsCollection);
}
