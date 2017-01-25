//GMock-Example

#include <gmock/gmock.h>
using namespace testing;

TEST(ThisIsATestCase, ThisTestPasses) {
    ASSERT_EQ(1,1);
};

TEST(ThisIsATestCase, ThisTestFails) {
    ASSERT_EQ(1,2);
};


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
