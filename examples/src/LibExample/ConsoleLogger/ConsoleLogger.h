#ifndef LIBEXAMPLE_CONSOLELOGGER_H
#define LIBEXAMPLE_CONSOLELOGGER_H

#include "LibExample_EXPORT.h"
#include <memory>
#include <string>

class ConsoleLogger;
typedef LibExample_EXPORT std::shared_ptr<ConsoleLogger> ConsoleLoggerPtr;

class LibExample_EXPORT ConsoleLogger {
public:
    static ConsoleLoggerPtr getNewInstance();
    virtual ~ConsoleLogger();
private:
    ConsoleLogger();
public:
    virtual void log(std::string logMessage);
};

#endif //LIBEXAMPLE_CONSOLELOGGER_H
