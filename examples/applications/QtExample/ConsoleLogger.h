#ifndef QTEXAMPLE_CONSOLELOGGER_H
#define QTEXAMPLE_CONSOLELOGGER_H

#include <QObject>
#include <memory>
#include <string>

class ConsoleLogger;
typedef std::shared_ptr<ConsoleLogger> ConsoleLoggerPtr;

class ConsoleLogger : public QObject {
public:
    Q_OBJECT
public:
    static ConsoleLoggerPtr getNewInstance();
    virtual ~ConsoleLogger();
private:
    ConsoleLogger();
public:
    virtual void log(std::string logMessage);
};

#endif //QTEXAMPLE_CONSOLELOGGER_H