#include "unitstate.h"
#include "unit.h"

//====Ready====
void UnitReady::setMarch(Point target)
{
    unit->setTarget(target);
    unit->setTicksLeft(Helper::length(target,unit->getPosition()));
    unit->changeState(dynamic_cast<UnitState*>(new UnitInMarch(unit)));
}
void UnitReady::move(){}

void UnitReady::defeat()
{
     unit->changeState(dynamic_cast<UnitState*>(new UnitDead(unit)));
}

void UnitReady::victory(){}
//====In March====
UnitInMarch::UnitInMarch(Unit *u)
    : UnitState(u)
{
    u->log("#MARCH STARTED " + std::to_string(u->getId()) + " TO "+ Helper::ptostr(u->getTarget())+"\r\n");
}

void UnitInMarch::setMarch(Point){}
void UnitInMarch::move()
{
    if (0==unit->decrementTickLeft())
    {
        unit->log("#MARCH " + std::to_string(unit->getId()) +" FINISHED " + Helper::ptostr(unit->getTarget()));
        unit->signal();
        unit->setPos(unit->getTarget());
        if (!unit->checkBattle()){
            unit->log("\r\n");
            unit->changeState(dynamic_cast<UnitState*>(new UnitDoneMarch(unit)));
        }
    }
}

void UnitInMarch::defeat()
{
     unit->changeState(dynamic_cast<UnitState*>(new UnitRetreat(unit)));
}

void UnitInMarch::victory()
{
     unit->changeState(dynamic_cast<UnitState*>(new UnitDoneMarch(unit)));
}
//====Retreat====
UnitRetreat::UnitRetreat(Unit *u) : UnitState(u){
     unit->setTicksLeft(Helper::length(unit->getStart(),unit->getPosition()));
    u->log("#RETREAT STARTED " + std::to_string(u->getId()) + " TO "+ Helper::ptostr(u->getStart())+"\r\n");
}

void UnitRetreat::setMarch(Point){}
void UnitRetreat::move()
{
    if (0==unit->decrementTickLeft())
    {
        unit->log("#RETREAT " + std::to_string(unit->getId()) +" FINISHED " + Helper::ptostr(unit->getStart()));
        unit->signal();
        unit->setPos(unit->getStart());
        if (!unit->checkBattle()){
            unit->log("\r\n");
            unit->changeState(dynamic_cast<UnitState*>(new UnitReady(unit)));
        }
    }
}

void UnitRetreat::defeat()
{
    unit->changeState(dynamic_cast<UnitState*>(new UnitDead(unit)));
}

void UnitRetreat::victory()
{
    unit->changeState(dynamic_cast<UnitState*>(new UnitReady(unit)));
}

//====Ready after match====
UnitDoneMarch::UnitDoneMarch(Unit *u)
    : UnitReady(u)
{

}

void UnitDoneMarch::setMarch(Point p)
{
    UnitReady::setMarch(p);
}
void UnitDoneMarch::move()
{
    UnitReady::move();
}

void UnitDoneMarch::defeat()
{
    unit->changeState(dynamic_cast<UnitState*>(new UnitRetreat(unit)));
}

void UnitDoneMarch::victory(){}

void UnitState::death()
{
     unit->changeState(dynamic_cast<UnitState*>(new UnitDead(unit)));
}
//====Dead ready to delete====
void UnitDead::setMarch(Point){}
void UnitDead::move(){}
void UnitDead::defeat(){}
void UnitDead::victory(){}
void UnitDead::death(){}
