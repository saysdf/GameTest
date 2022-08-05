#ifndef BATTLE_H
#define BATTLE_H

#include "unit.h"

class Battle : public AbstractNotifier
{
public:
    Battle(std::shared_ptr<AbstractObserver> logger) : AbstractNotifier(logger){}
    virtual void subscribeTo(std::shared_ptr<AbstractObserver>) override {};
    virtual void unsbscribeFrom(std::shared_ptr<AbstractObserver>) override {};
    virtual void signal() override {};
    void doBattle(Unit* u1, Unit* u2);
};

#endif // BATTLE_H
