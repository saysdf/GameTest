#include "unit.h"
#include "battlechecker.h"

Unit::Unit(int id, int power, const Point &position, std::shared_ptr<BattleChecker> bc, std::shared_ptr<AbstractObserver> logger)
    : AbstractNotifier(logger), id(id), power(power), pos(position), start(position), state(new UnitReady(this)), battleChecker(bc)
{

}

void Unit::unsbscribeFrom(std::shared_ptr<AbstractObserver> observer)
{
    auto it = std::find(observers.begin(),observers.end(),observer);
    if (it != observers.end())
        observers.erase(it);
}

void Unit::subscribeTo(std::shared_ptr<AbstractObserver> observer)
{
    observers.push_back(observer);
}

void Unit::signal()
{
    for (auto& i:observers){
        i->slot(std::string());
    }
}

void Unit::changeState(UnitState *newState)
{
    if (this->state != nullptr)
          delete this->state;
        this->state = newState;
    this->state->setUnit(this);
}

void Unit::setMarch(Point target)
{
    state->setMarch(target);
}

void Unit::move()
{
    state->move();
}

void Unit::defeat()
{
    state->defeat();
}

void Unit::death()
{
    state->death();
}

void Unit::victory()
{
    state->victory();
}

bool Unit::readyForBattle()
{
    return state->readyForBattle();
}

int Unit::decrementTickLeft()
{
    if (ticksLeft>0){
        --ticksLeft;
    }
    return ticksLeft;
}

UnitState *Unit::getState() const
{
    return state;
}

void Unit::setPos(const Point &value)
{
    pos = value;
}

Point Unit::getTarget() const
{
    return target;
}

Point Unit::getStart() const
{
    return start;
}

void Unit::setTicksLeft(int value)
{
    ticksLeft = value;
}

void Unit::setTarget(const Point &value)
{
    target = value;
}

void Unit::setStart(const Point &value)
{
    start = value;
}
