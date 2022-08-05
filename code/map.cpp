#include "map.h"

Map::Map(std::shared_ptr<AbstractObserver> logger)
    : AbstractNotifier(logger), size(Point{0,0})
{
    log("#MAP CREATED " + Helper::ptostr(size) + "\r\n");
}

Map::Map(const Point &size,std::shared_ptr<AbstractObserver>logger)
         : AbstractNotifier(logger), size(size)
{
    log("#MAP CREATED " + Helper::ptostr(size) + "\r\n" );
}

bool Map::InBorder(const PointF& pos)
{
    // int(-0.9(9)) -> 0 - it's ok
    int x=int(pos.first);
    int y=int(pos.second);
    return (x>=0 &&
            y>=0 &&
            static_cast<size_t>(x)<size.first &&
            static_cast<size_t>(y)<size.second);
}

bool Map::InBorder(const Point& pos)
{
    return (pos.first<size.first && pos.second<size.second);
}
