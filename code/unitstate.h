#ifndef UNITSTATE_H
#define UNITSTATE_H

#include "helper.hpp"

class Unit;
class UnitState
{
public:
    UnitState(Unit* u) : unit(u){}
    virtual ~UnitState() {}
    virtual void setMarch(Point)=0;
    virtual void move()=0;
    virtual void death();
    virtual void defeat()=0;
    virtual void victory()=0;
    virtual bool readyForBattle()=0;
    void setUnit(Unit* u){unit = u;};
protected:
    Unit* unit;
};

class UnitReady : public UnitState
{
public:
    UnitReady(Unit* u) : UnitState(u){};
    virtual void setMarch(Point target) override;
    virtual void move() override;
    virtual void defeat() override;
    virtual void victory() override;
    virtual bool readyForBattle() override {return true;};
};
class UnitInMarch : public UnitState
{
public:
    UnitInMarch(Unit* u);
    virtual void setMarch(Point) override;
    virtual void move() override;
    virtual void defeat() override;
    virtual void victory() override;
    virtual bool readyForBattle() override {return false;};
};
class UnitRetreat : public UnitState
{
public:
    UnitRetreat(Unit* u);
    virtual void setMarch(Point) override;
    virtual void move() override;
    virtual void defeat() override;
    virtual void victory() override;
    virtual bool readyForBattle() override {return false;};
};
class UnitDoneMarch : public UnitReady
{
public:
    UnitDoneMarch(Unit* u);
    virtual void setMarch(Point p) override;
    virtual void move() override;
    virtual void defeat() override;
    virtual void victory() override;
    virtual bool readyForBattle() override {return true;};
};
class UnitDead : public UnitState
{
public:
    UnitDead(Unit* u) : UnitState(u){};
    virtual void setMarch(Point) override;
    virtual void move() override;
    virtual void defeat() override;
    virtual void victory() override;
    virtual void death() override;
    virtual bool readyForBattle() override {return false;};
};
#endif // UNITSTATE_H
