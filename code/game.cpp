#include "game.h"

Game::Game()
{
    pauseFlag = true;
    exitFlag = false;
}

Game::~Game()
{
    exit();
}

void Game::addScenario(std::queue<std::shared_ptr<ScenarioCommand> > commands)
{
    if (this->commands.empty())
        this->commands = commands;
    else
    {
        while (!commands.empty()) {
            auto command = commands.front();
            commands.pop();
            this->commands.push(command);
        }
    }
}

void Game::start()
{
    pauseFlag=false;
    gameLoop();
}

void Game::exit()
{
    exitFlag=true;
}

void Game::pause()
{
    pauseFlag=true;
}

void Game::unpause()
{
    pauseFlag=false;
}

void Game::gameLoop()
{
    while (!exitFlag) {
        if (pauseFlag) continue;
        std::shared_ptr<ScenarioCommand> command = popCommand();
        if (command)
            command->execute();
        else
            exit();
    }
}

std::shared_ptr<ScenarioCommand> Game::popCommand()
{
    if (commands.empty())
        return nullptr;
    auto c = commands.front();
    if (c->getReadyForDelete())
        commands.pop();
    return c;
}

