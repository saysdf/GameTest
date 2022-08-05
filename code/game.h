#ifndef GAME_H
#define GAME_H

#include <atomic>
#include <queue>
#include "scenariocommand.h"

class Game
{
public:
    Game();
    virtual ~Game();
    void addScenario(std::queue<std::shared_ptr<ScenarioCommand> >commands);

    void start();
    void exit();
    void pause();
    void unpause();
    void gameLoop();
    std::shared_ptr<ScenarioCommand> popCommand();
    Game(Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;
private:
    std::atomic_bool pauseFlag,exitFlag;
    std::queue<std::shared_ptr<ScenarioCommand> >commands;
};

#endif // GAME_H
