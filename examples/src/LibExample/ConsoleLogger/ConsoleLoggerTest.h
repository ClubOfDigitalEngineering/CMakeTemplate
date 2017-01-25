#ifndef LIBEXAMPLETEST_CONSOLELOGGERTEST_H
#define LIBEXAMPLETEST_CONSOLELOGGERTEST_H

#include <gmock/gmock.h>
#include "ConsoleLogger.h"

class ConsoleLoggerTest : public testing::Test {
protected:
    virtual void SetUp() override {
        sut = ConsoleLogger::getNewInstance();
    };
    ConsoleLoggerPtr sut;
};

#endif //LIBEXAMPLE_CONSOLELOGGER_H