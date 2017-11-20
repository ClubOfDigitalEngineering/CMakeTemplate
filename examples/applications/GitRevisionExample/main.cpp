#include <iostream>

#include "buildInfo.h"

int main()
{
    std::cout << "git hash: " << GIT_COMMIT_HASH << std::endl;
    std::cout << "git branch: " << GIT_BRANCH << std::endl;
    std::cout << "build machine: " << BUILD_MACHINE << std::endl;
    std::cout << "project dir: " << PROJECT_DIR << std::endl;
    std::cout << "binary dir: " << BINARY_DIR << std::endl;
    std::cout << "compiler flags: " << COMPILER_FLAGS << std::endl;
    std::cout << "build type: " << BUILD_TYPE << std::endl;

    return 0;
}
