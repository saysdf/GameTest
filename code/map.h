#ifndef MAP_H
#define MAP_H

#include "helper.hpp"
#include "abstractobject.h"
class Map : public AbstractNotifier
{
public:
    Map(std::shared_ptr<AbstractObserver> logger);
    Map(const Point& sizep, std::shared_ptr<AbstractObserver> logger);
    bool InBorder(const PointF& pos);
    bool InBorder(const Point& pos);
    virtual void subscribeTo(std::shared_ptr<AbstractObserver>) override {};
    virtual void unsbscribeFrom(std::shared_ptr<AbstractObserver>) override {};
    virtual void signal() override {};
private:
    Point size;
};

#endif // MAP_H
