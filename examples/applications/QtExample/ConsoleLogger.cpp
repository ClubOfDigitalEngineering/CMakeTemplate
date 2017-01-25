#include "ConsoleLogger.h"
#include <iostream>

ConsoleLoggerPtr ConsoleLogger::getNewInstance() {
    return ConsoleLoggerPtr(new ConsoleLogger());
}
ConsoleLogger::~ConsoleLogger() {}
ConsoleLogger::ConsoleLogger() {}

void ConsoleLogger::log(std::string logMessage) {
    std::cout << logMessage << std::endl;
}
