#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include "helper.hpp"

class AbstractObserver
{
public:
    virtual ~AbstractObserver(){};
    virtual void slot(const std::string&) = 0;
};

class AbstractNotifier
{
public:
    AbstractNotifier(std::shared_ptr<AbstractObserver>logger=nullptr) : logger(logger){}
    virtual ~AbstractNotifier(){};
    virtual void subscribeTo(std::shared_ptr<AbstractObserver> ob) = 0;
    virtual void unsbscribeFrom(std::shared_ptr<AbstractObserver> ob) = 0;
    virtual void signal() = 0;
    virtual void log(const std::string& message) {
        if (logger)
            logger->slot(message);
    }
private:
    std::shared_ptr<AbstractObserver> logger;
};

#endif // ABSTRACTOBJECT_H
