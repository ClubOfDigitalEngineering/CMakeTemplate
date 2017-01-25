#include "ConsoleLoggerTest.h"

TEST_F(ConsoleLoggerTest, TestTheConsoleLogger) {
    sut->log("I was tested!");
    EXPECT_TRUE(true);
}