#include <iostream>
#include "creatorfactory.h"
#include "battlechecker.h"
#include "unitscollection.h"
#include "scenariobuilder.h"
#include "logger.hpp"
#include "game.h"

int main(int argc, char** argv)
{
    if (argc>1)
    {
        std::string file(argv[1]);
        std::shared_ptr<int> currentTick = std::make_shared<int>(0);
        std::shared_ptr<Logger> log = std::make_shared<Logger>(currentTick);
        std::shared_ptr<UnitsCollection> db = std::make_shared<UnitsCollection>();
        std::shared_ptr<BattleChecker> bc = std::make_shared<BattleChecker>(db,log);
        std::shared_ptr<CreatorFactory> factory = std::make_shared<CreatorFactory>(bc,db,log);
        ScenarioBuilderFromText builder(factory,db,currentTick);
        auto eventQueue = builder.readFile(file);
        if (eventQueue.empty())
            return 1;
        Game g;
        g.addScenario(eventQueue);
        g.start();
    }

    return 0;
}
