#ifndef UNIT_H
#define UNIT_H

#include <list>

#include "abstractobject.h"
#include "unitstate.h"

class BattleChecker;

class Unit : public AbstractNotifier
{
public:
    Unit(int id,int power,const Point& position,std::shared_ptr<BattleChecker> bc, std::shared_ptr<AbstractObserver> logger=0);
    virtual ~Unit(){delete state;};
    virtual void unsbscribeFrom(std::shared_ptr<AbstractObserver> observer) override;
    virtual void subscribeTo(std::shared_ptr<AbstractObserver> observer) override;
    virtual void signal() override;
    Point getPosition() const {return pos;}
    int getPower() const {return power;}
    int getId() const {return id;}
    void changeState(UnitState *newState);
    void setMarch(Point target);
    void move();
    void defeat();
    void death();
    void victory();
    bool readyForBattle();

    //return tickleft copy
    int decrementTickLeft();
    UnitState *getState() const;

    virtual bool checkBattle()=0;

    void setPos(const Point &value);
    Point getTarget() const;
    void setTarget(const Point &value);
    Point getStart() const;
    void setStart(const Point &value);
    void setTicksLeft(int value);



private:
    int id;
    int power;
    Point pos;
    Point target;
    Point start;
    int health;
    int ticksLeft;
    UnitState* state;
    std::list<std::shared_ptr<AbstractObserver> > observers;
protected:
    std::shared_ptr<BattleChecker> battleChecker;
};


#endif // UNIT_H
