#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include "abstractobject.h"

class Logger : public AbstractObserver
{
public:
    Logger(std::shared_ptr<int> currentTick)
        : AbstractObserver(),currentTick(currentTick) {}
    ~Logger() {};
    virtual void slot(const std::string& message) override {
        log(message);
    }
    void log(const std::string& message) {
        std::string tick=" ";
        std::string msg(message);
        if (message.size()>0 && message[0]=='#'){
            tick="["+std::to_string(*currentTick)+"] ";
            msg = message.substr(1,message.size()-1);
        }
        std::cout<<tick<<msg;
    };
private:
    std::shared_ptr<int> currentTick;
};

#endif // LOGGER_HPP
